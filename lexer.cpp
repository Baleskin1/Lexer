#include "lexer.h"
using namespace std;

Lexer::Lexer(std::istream &is):is_p(&is){
    words = std::make_shared<Words>();
    calculateLength();
    reserve(make_shared<Boolean>(false));
    reserve(make_shared<Boolean>(true));
    //A list of reserved words
}



void Lexer::reserve(const shared_ptr<Token>& word){
    for(auto [k,v]: *words)if(v->getLexeme()==word->getLexeme())return;
    (*words)[GetNewId()]=word;
}

size_t Lexer::GetNewId(){
    return next_id++;
}

char Lexer::seekChar(int offset = 1)const{//gets char at offset pos, without changing pos!
    return is_p->seekg(pos+offset).peek();
}

char Lexer::CurrentChar()const{
    return seekChar(0);
}

bool Lexer::Match(const std::string &to_match){
    for(size_t i = 0; i<to_match.size(); ++i){
        if(seekChar(i)!=to_match[i])return false;
    }
    return true;
}

void Lexer::calculateLength(){
    is_p->seekg(0, std::istream::end);
    length = is_p->tellg();
    is_p->seekg(0, std::istream::beg);
}

char Lexer::NextChar(){//gets char at next pos, changing current pos!
    return is_p->seekg(++pos).peek();;
}

bool isEmpty(const char& c){
    return (c == ' ' || c == '\n' || c == '\t');
}

void Lexer::skipEmpty() {
    if(isEmpty(CurrentChar()) && pos<length){
        while(isEmpty(CurrentChar()) && pos<length)NextChar();
    }
}

void Lexer::skipBetween(const std::string& first, const std::string& second){
    if(Match(first)) {
        while (!Match(second))NextChar();
        NextChar();
    }
}

shared_ptr<Token> Lexer::scan() {
    //If that's the end, returns empty token. This way last token will be an empty one
    if(is_p->eof())return make_shared<EmptyToken>();
    //Skip whitespaces, empty lines and comments
    skipEmpty();
    skipBetween("//", "\n");
    skipBetween("/*", "*/");
    if(isdigit(CurrentChar()) || (CurrentChar()=='-'&&isdigit(seekChar()))){
        //For now, numbers will be considered long doubles
        string potential_number = "";
        if(CurrentChar()=='-'){potential_number="-"; NextChar();}
        bool is_decimal = false, ill_formed = false;
        while((isdigit(CurrentChar()) || CurrentChar() == '.' || CurrentChar() == ',')&&pos<length){
            if(CurrentChar() == '.' || CurrentChar() ==','){
                if(is_decimal)ill_formed = true;
                else is_decimal = true;
            }
            if(ill_formed)break;
            potential_number += string(1, CurrentChar());
            NextChar();
        }
        if(ill_formed)throw runtime_error("ill-formed number");
        auto t = stold(potential_number);
        return make_shared<Number<long double>>(t);
    }else if(isalpha(CurrentChar())){
        string var_name;
        while(isalnum(CurrentChar())){
            var_name+=string(1,CurrentChar());
            NextChar();
        }
        auto var = make_shared<Variable>(var_name);
        reserve(var);
        return var;
    }
    if(pos == length)return make_shared<EmptyToken>();
    //If this is neither a var or number - it's an operator
    auto op = make_shared<Operator>(string(1,CurrentChar()));
    NextChar();
    return op;
}