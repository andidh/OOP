

#include "domain.h"
#include "utils.h"
#include<cstdlib>
#include<iomanip>


Coat::Coat() : size(""), color(""), price(0), quantity(0), link("") {}

Coat::Coat( const string& size, const string& color , const float& price , const int& quantity , const string& link){
    this->size = size;
    this->color = color;
    this->price = price;
    this->quantity = quantity;
    this->link = link;
}

string Coat::getSize() const{
    return size;
}
string Coat::getColor() const{
    return color;
}

float Coat::getPrice() const{
    return price;
}

int Coat::getQuantity() const{
    return quantity;
}

string Coat::getLink() const{
    return link;
}
void Coat::setQuantity(int& n){
    quantity = n;
}


void Coat::show(){
    string cmd = "open " + link;
    system(cmd.c_str());
}


void Coat::toString() const {
    cout<<size<<" | ";
    cout<<color<<" | ";
    cout<<price<<" | ";
    cout<<quantity<<" | ";
    cout<<link<<" | "<<endl;
    }




istream& operator>>(istream& is, Coat& c){

    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    c.size = tokens[0];
    c.color = tokens[1];
    c.price = stof(tokens[2]);
    c.quantity = stoi(tokens[3]);
    c.link = tokens[4];

    return is;
}


ostream& operator<<(ostream& os, const Coat& c)
{
    os << c.size << "," << c.color << "," << c.price << "," << c.quantity << "," << c.link << "\n";
    return os;
}
