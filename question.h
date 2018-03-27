#include <string>
#pragma once

using namespace std;

const static int CAPACITY = 5;
class Question {
private:
	int rightAnswer;
	string questionAndAnswers[CAPACITY];
public:
	Question();
	Question(int rightAnswer, string question, string option1, string option2, string option3, string option4);
	~Question();
	//void setQuestionsFromFile();
	string getQuestion();
	string getOp1();
	string getOp2();
	string getOp3();
	string getOp4();
	int getRightAnswer();
};