#pragma once
#include<string>
#include<vector>

using namespace std;

class Question
{
    int id, score;
    string text, answer;

public:
    Question(const int& id, const string& text,const string& answer,const int& score);
    int getId() const { return id; }
    string getText() { return text; }
    string getAnswer() { return answer; }
    int getScore() const { return score; }
    string toString(){
        return to_string(id) + "," + text + "," + answer + "," + to_string(score);
    }


};

inline bool operator == (const Question& q1, const Question q2){
    return q1.getId() == q2.getId();
}
