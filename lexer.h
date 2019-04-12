#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <math.h>
#include "token.h"
class Lexer{
public:
    using Word = std::pair<size_t, Token*>;
    using Words = std::map<size_t, std::shared_ptr<Token>>; //id to respective token;
    explicit Lexer(std::istream &is);
    void reserve(const std::shared_ptr<Token>& word);
    std::shared_ptr<Words> getWords()const{return words;}
    std::shared_ptr<Token> scan(); //Scans stream lexeme per lexeme
private:

    size_t GetNewId();
    char NextChar();
    char seekChar(int offset)const;
    char CurrentChar()const;
    bool Match(const std::string &to_match);
    void calculateLength();
    void skipEmpty();
    void skipBetween(const std::string& first, const std::string& second);
    size_t next_id = 0;
    size_t pos = 0;
    size_t length = 0;
    std::istream* is_p;
    std::shared_ptr<Words> words;
};