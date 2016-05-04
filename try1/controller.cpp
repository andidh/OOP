#include "controller.h"
#include <algorithm>


//--------ADMIN-----------
void Controller::addToRepo(const string& size, const string& color, const int& price, const int& quantity, const string& link){
    Coat c{ size, color, price, quantity, link};
    this->val.validate(c);
    this->repo.addCoat(c);
}

vector<Coat> Controller::getAll(){
    return this->repo.getAll();
}

void Controller::removeCoat(const string& link){
    this->repo.removeCoat(link);
}

void Controller::updateCoat(const string &size, const string &color, const int &price, const int &quantity, const string &link){
    Coat c{ size, color, price, quantity, link};
    this->val.validate(c);
    this->repo.update(c);
}




//--------USER---------


void Controller::addToStore(const string& size){
    this->store->clear();
    this->store->clearTotal();
    vector<Coat> all = this->getAll();

    long nCoats = count_if(all.begin(), all.end(), [size](const Coat& c){
        return c.getSize() == size;
    });

    vector<Coat> filter(nCoats);
    copy_if(all.begin(), all.end(), filter.begin(), [size](const Coat& c)
    {
        return c.getSize() == size;
    });

    for(auto c: filter)
        this->store->add(c);


}

void Controller::start(){
    if(this->store->isEmpty())
        cout<<"There are no coats available";
    this->store->start();
}

void Controller::next(){
    if(this->store->isEmpty())
        cout<<"There are no coats available";
    this->store->next();
}

void Controller::buyCoat(Coat& c){
    this->store->buyCoat(c);
}

int Controller::showTotal(){
    return this->store->showTotal();
}





void Controller::saveToFile(){
    /*if(this->store == nullptr)
        return;
    this->store->setFile(filename);
     */
    this->store->writeToFile();
}


void Controller::openStore(){
    if(this->store == nullptr)
        return;

    this->store->display();

}



