//
//  storeHTML.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/14/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "storeHTML.hpp"
#include <fstream>
#include "exception.hpp"

using namespace std;

StoreHTML::StoreHTML(const string& file){
    this->filename = file;
}


void StoreHTML::display() const {
    string cmd = "open " + this->filename;
    system(cmd.c_str());
}

void StoreHTML::writeToFile() {

    ofstream file(this->filename);
    
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    
    
    file << "<!DOCTYPE html>" << "\n";
    file << "<html>" << "\n";
    file << "<head>" << "\n";
    file << "<title>Shopping bag</title>" << "\n";
    file << "<link rel=\"stylesheet\" href=\"style.css\"> " <<endl;
    file << "</head> <body>" << "\n";
    file << "<div class=\"main\">"<<endl;
    file << "<h1>My shopping bag</h1>"<<endl;
    file << "<table>" << "\n";
    
    file << "<tr>" << "\n";
    file << "<td>Size</td>" << "\n";
    file << "<td>Color</td>" << "\n";
    file << "<td>Price</td>" << "\n";
    file << "<td>Quantity</td>" <<"\n";
    file << "<td>Link</td>" << "\n";
    
    file << "</tr>" << "\n";
    
    for (auto c : this->basket ){
        file << "<tr>" << "\n";
        file << "<td>"<<c.getSize()<<"</td>" << "\n";
        file << "<td>"<<c.getColor()<<"</td>" << "\n";
        file << "<td>"<<c.getPrice()<<"</td>" << "\n";
        file << "<td>"<<c.getQuantity()<<"</td>" << "\n";
        file << "<td><a href ="<<c.getLink()<<">Link</a></td>" << "\n";
        file << "</tr>" << "\n";
    }
    
   
    file << "</table>" << "\n";
    file << "<h2> Total is: " << this->total <<"</h2>" <<endl;
    file << "</div>"<<endl;
    file << "</body>" << "\n";
    file << "</html>" << "\n";
    file.close();

}
