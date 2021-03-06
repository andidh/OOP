#pragma once
#include "repository.h"


class Controller
{
    Repository* repo;

public:
    Controller(Repository* repo);

    vector<Question> getQuestionsPresenter() { return repo->getQuestionsPresenter(); }
    vector<Question> getQuestionsParticipant() { return repo->getQuestionsParticipant(); }

    vector<Participant> getParticipants() { return repo->getParticipants(); }
    void addQuestion(int& id, string& text, string& answ, int& score);
    void removeQuestion(int& id);
    int answerQuestion(int& ind, string& answ);
};

