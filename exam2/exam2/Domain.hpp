//
//  Domain.hpp
//  exam2
//

#pragma once
#include <string>

using namespace std;


class Painting {
    string title, artist;
    int year;
    
public:
    //--->>CONSTRUCTORS<<---
    Painting() : artist{""}, title{""},  year(-1) {}
    Painting(const string& artist, const string&title, const int& year) {
        this->artist = artist;
        this->title = title;
        this->year = year;
    }
    
    //--->>GETTERS<<---
    inline string getArtist() const { return this->artist; }
    inline string getTitle() const { return this->title; }
    inline int getYear() const { return this->year; }
    
    void toString();
    
};


inline bool operator==(const Painting& a, const Painting& b){
    return a.getArtist() == b.getArtist() && a.getTitle()==b.getTitle() && a.getYear()==b.getYear();
}