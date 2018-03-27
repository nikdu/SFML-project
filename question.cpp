#include "question.h"
#include <fstream>
#include <iostream>
Question::Question() {
	this->rightAnswer = 0;
	for (int i = 0; i < CAPACITY; i++)
	{
		this->questionAndAnswers[i] = "";
	}

}

Question::Question(int rightAnswer, string question, string op1, string op2, string op3, string op4) {
	this->rightAnswer = rightAnswer;
	this->questionAndAnswers[0] = question;
	this->questionAndAnswers[1] = op1;
	this->questionAndAnswers[2] = op2;
	this->questionAndAnswers[3] = op3;
	this->questionAndAnswers[4] = op4;
}

Question::~Question() {}

string Question::getQuestion() {
	return this->questionAndAnswers[0];
}
string Question::getOp1() {
	return this->questionAndAnswers[1];
}
string Question::getOp2() {
	return this->questionAndAnswers[2];
}
string Question::getOp3() {
	return this->questionAndAnswers[3];
}
string Question::getOp4() {
	return this->questionAndAnswers[4];
}

int Question::getRightAnswer() {
	return this->rightAnswer;
}


