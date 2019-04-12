#pragma once
#include <iostream>
#include <memory>
enum class TokenType{
    OPERATOR,
    NUMBER,
    BOOLEAN,
    VARIABLE,
    EMPTY,
    UNKNOWN
};
class Token{
public:
    using true_type = std::nullptr_t;
    Token(const TokenType& type, std::string lexeme):type(type), lexeme(std::move(lexeme)){}
    virtual const Token* evaluate()const=0;
    std::string getLexeme()const{return lexeme;}
    virtual bool empty()const{return false;}
protected:
    TokenType type;
    std::string lexeme;
};
template<typename Type>
class Number: virtual public Token{
public:
    using true_type = Type;
    explicit Number(Type value):Token(TokenType::NUMBER, std::to_string(value)), value(value){}
    const Token* evaluate()const override{
        return this;
    }
protected:
    Type GetValue()const{
        return value;
    }
    Number operator+(Number other){
        return Number(value + other.GetValue());
    }
    Number operator-(Number other){
        return Number(value - other.GetValue());
    }
    Number operator*(Number other){
        return Number(value * other.GetValue());
    }
    Number operator/(Number other){
        if(other.GetValue()==0)throw std::runtime_error("Division by zero");
        return Number(value / other.GetValue());
    }
    Type value;
};

class Operator: public Token{
public:
    using true_type = std::string;
    explicit Operator(std::string op):Token(TokenType::OPERATOR, move(op)){}
    const Token* evaluate()const override{
        return this;
    }
private:

};

template<typename Type>
class NumberArithmetic: public Number<Type>{
public:
    NumberArithmetic(Number<Type>* lhs, Number<Type>* rhs, const char& op){
        switch(op){
            case '+':
                val = new Number((*lhs + *rhs).GetValue());
                break;
            case '-':
                val = new Number((*lhs - *rhs).GetValue());
                break;
            case '*':
                val = new Number((*lhs * *rhs).GetValue());
                break;
            case '/':
                val = new Number((*lhs / *rhs).GetValue());
                break;
            default:
                throw std::runtime_error("unknown operator! Ill-formed code!");
        }
    }
    const Token* evaluate()const override {
        return val;
    }
    ~NumberArithmetic(){
        delete val;
    }
private:
    std::shared_ptr<Number<Type>> val;
};
class Boolean: virtual public Token{
public:
    using true_type = bool;
    explicit Boolean(const bool& new_value):
            Token(TokenType::BOOLEAN, new_value?"true":"false"), value(new_value){}
    const Token* evaluate()const override{
        return this;
    }
protected:
    bool value;
};
class EmptyToken: virtual public Token{
public:
    using true_type = std::nullptr_t;
    EmptyToken():Token(TokenType::EMPTY, ""){}
    bool empty()const override{return true;}
    const Token* evaluate()const override{
        return this;
    }
};
class Variable: virtual public Token{
public:
    using true_type = std::shared_ptr<Token>;
    explicit Variable(std::string name):Token(TokenType::VARIABLE, std::move(name)){
        definition = std::make_shared<EmptyToken>();
    }
    std::shared_ptr<Variable> setDefinition(std::shared_ptr<Token> def){
        definition = std::shared_ptr<Token>(move(def)); //Represents an exact value of a token.
        return std::make_shared<Variable>(this);
    }
    const Token* evaluate()const override{
        return definition->evaluate();
    }
protected:
    std::shared_ptr<Token> definition;
};

