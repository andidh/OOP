#pragma once
#include<string>
#include<vector>

using namespace std;

class Participant
{
    string name;
    int score;

public:
    Participant(const string& name,const int& score);
    string getName() { return name; }
    int getScore() { return score; }
    void setScore(const int& score);
};

