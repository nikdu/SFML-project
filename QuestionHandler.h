#include "question.h"
#pragma once

using namespace std;

class QuestionHandler {
private:
	Question *questions;
	int capacity;
	int questionCounter;
public:
	QuestionHandler();
	QuestionHandler(int rightAnswer, string question, string option1, string option2, string option3, string option4);
	~QuestionHandler();
	void setQuestionsFromFile();
	string getQuestion(int nr);
	string getOp1(int nr);
	string getOp2(int nr);
	string getOp3(int nr);
	string getOp4(int nr);
	bool rightAnswer(int questionNr, int answer);
	Question expand();
	int getNrOfQuestions();
};