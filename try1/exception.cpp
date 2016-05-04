#include "exception.h"

RepoException::~RepoException() {}


RepoException::RepoException() : exception{}, msg{""} {}

RepoException::RepoException(const string& msg){
    this->msg = msg;
}

const char* RepoException::what(){
    return msg.c_str();
}



FileException::FileException(const string& msg){
    this->msg = msg;
}

const char* FileException::what(){
    return this->msg.c_str();
}


