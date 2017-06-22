cmake_minimum_required(VERSION 3.7)
project(chap9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Account.cpp Account.h BankingCommonDecl.h NormalAccount.h HighCreditAccount.h AccountHandler.cpp AccountHandler.h AccountArray.cpp AccountArray.h string.cpp string.h)
add_executable(chap9 ${SOURCE_FILES})