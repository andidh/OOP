//
//  utils.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

/*
#include "utils.hpp"



Vector::Vector(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->arr = new TE[capacity];
}

Vector::Vector(const Vector& v){
    this->size = v.size;
    this->capacity = v.capacity;
    this->arr = new TE[capacity];
    for( int i=0; i<this->size; i++)
        this->arr[i] = v.arr[i];
    
}

Vector::~Vector(){
    delete[] this->arr;
}

Vector& Vector::operator=(Vector& v){
    if(this == &v)
        return *this;
    this->size = v.size;
    this->capacity = v.capacity;
    
    delete[] this->arr;
    for(int i=0;i < this->size; i++)
        this->arr[i] = v.arr[i];
    return *this;
}


void Vector::add(TE elem){
    if(this->size>=this->capacity){
        this->resize();
    }
    this->arr[this->size++] = elem;
}

int Vector::getSize() const{
    return size;
}

TE* Vector::getAll() const{
    return this->arr;
}

void Vector::remove(int pos){
    long len = Vector::getSize();
    for( long i = len; i< len - 1; ++i)
        this->arr[i] = this->arr[i+1];
    --this->size;
}

TE& Vector::getAt(int& pos){
    return this->arr[pos];
}








void Vector::resize(double factor){
    int new_capacity = this->size * factor;
    TE* new_arr = new TE[new_capacity];
    for( int i=0; i<this->size; i++)
        new_arr[i] = this->arr[i];
    delete[] arr;
    this->arr = new_arr;
}

*/