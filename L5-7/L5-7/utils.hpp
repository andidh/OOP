//
//  utils.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"

template<typename TE>
class Vector{
    TE* arr;
    int size;
    int capacity;
    
public:
    //-----CONSTRUCTORS-----
    Vector(int capacity = 10){
        this->size = 0;
        this->capacity = capacity;
        this->arr = new TE[capacity];
    }
    
    //-----COPY CONSTRUCTOR-----
    Vector(const Vector& v){
        this->size = v.size;
        this->capacity = v.capacity;
        this->arr = new TE[capacity];
        for( int i=0; i<this->size; i++)
            this->arr[i] = v.arr[i];
    }
    
    //-----DESTRUCTOR------
    ~Vector(){
        delete[] this->arr;
    }
    
    Vector& operator=(Vector& v){
        if(this == &v)
            return *this;
        this->size = v.size;
        this->capacity = v.capacity;
        
        delete[] this->arr;
        for(int i=0;i < this->size; i++)
            this->arr[i] = v.arr[i];
        return *this;
    }
    
    void add(TE elem){
        if(this->size>=this->capacity){
            this->resize();
        }
        this->arr[this->size++] = elem;
    }
    
    int getSize() const{
        return size;
    }
    
    TE* getAll() const{
        return this->arr;
    }
    
    void remove(int pos){
        long len = Vector::getSize();
        for( long i = pos; i< len - 1; ++i)
            this->arr[i] = this->arr[i+1];
        --this->size;
    }
    
    TE& getAt(int& pos){
        return this->arr[pos];
    }
    
    
private:
    void resize(double factor = 2){
        int new_capacity = this->size * factor;
        TE* new_arr = new TE[new_capacity];
            for( int i=0; i<this->size; i++)
                new_arr[i] = this->arr[i];
        delete[] arr;
        this->arr = new_arr;
    }
    
    
};

