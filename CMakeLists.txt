cmake_minimum_required(VERSION 3.13)
project(Lexer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexer main.cpp lexer.h lexer.cpp token.h)