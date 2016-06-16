#pragma once
#include "question.h"
#include "participant.h"
#include "subject.h"


class Repository : public Subject
{
    vector<Participant> part;
    vector<Question> quest;
    string file;

public:
    Repository(string file);
    ~Repository();

    void addQuestion(Question& q);
    void removeQuestion(int& id);
    vector<Question> getQuestions() { return this->quest; }
    vector<Participant> getParticipants() { return this->part; }


private:
    void loadFromFile();
    void writeToFile();
};


