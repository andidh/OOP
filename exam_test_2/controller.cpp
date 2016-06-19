#include "controller.h"
#include "exception.h"

Controller::Controller(Repository* repo) : repo{repo} {}

void Controller::addQuestion(int& id, string& text, string& answ, int& score){
    for( auto q : this->getQuestionsPresenter()){
        if( q.getId() == id)
            throw Exception("The question is already added");
    }
    Question quest(id, text, answ, score);
    this->repo->addQuestion(quest);
}

void Controller::removeQuestion(int& id) {
    this->repo->removeQuestion(id);
}

int Controller::answerQuestion(int &ind, string &answ) {
    Question q = this->getQuestionsParticipant()[ind];
    if( q.getAnswer() == answ )
        return q.getScore();
    else
        return -1;
}
