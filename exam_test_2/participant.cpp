#include "participant.h"

Participant::Participant(const string& name,const int& score) : name{name}, score{score} {}

void Participant::setScore(const int &score){
    this->score = score;
}
