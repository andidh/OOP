#pragma once
#include <string>
#include<iostream>

using namespace std;

class Coat {
    int quantity, price;
    string color, link, size;
public:

    //----constructors------
    Coat();
    Coat( const string& size, const string& color , const int& price , const int& quantity , const string& link);

    //-----GETTERS-----
    string getSize() const;
    string getColor() const;
    int getPrice() const;
    int getQuantity() const;
    string getLink() const;

    void setQuantity(int& n);

    void toString() const;
    void show();


    friend istream& operator>>(istream& is, Coat& c);
    friend ostream& operator<<(ostream& os, const Coat& c);
};


inline bool operator==(const Coat& c1,const Coat& c2){
    return c1.getLink() == c2.getLink();
}
