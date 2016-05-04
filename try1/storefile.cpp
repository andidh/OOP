
#include "storeFile.h"

StoreFile::~StoreFile() {}

StoreFile::StoreFile() : Store{}, filename{""} {}

StoreFile::StoreFile(const string& file) {
    filename = file;
}


void StoreFile::setFile(const string &file){
    this->filename = file;
}
