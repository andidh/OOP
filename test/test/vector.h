//
//  vector.h
//  test
//
//  Created by Dehelean Andrei on 4/4/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once

#include<iostream>

using namespace std;

template typename<TE>
class vector{
    TE* arr;
    int capacity, length;
    
public:
    vector() {
        capacity = 2;
        length = 0;
        arr = new TE[capacity];
    }
    
    ~vector() {
        capacity=0;
        length=0;
        delete [] arr;
    }
    
    vector(const vector& obj){
        capacity=obj.capacity;
        length=obj.length
        arr = new TE[capacity];
        for ( int i=0; i<length; i++)
            arr[i] = obj.arr[i];
    }
    
    vector& operator=(const vector& obj){
        capacity=obj.capacity;
        length=obj.length;
        arr = new TE[capacity];
        for ( int i=0; i<length; i++)
            arr[i] = obj.arr[i];
        return *this;
    }
    
    void push_back(TE& el){
        
    }
};