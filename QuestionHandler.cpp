#include "QuestionHandler.h"
#include <fstream>
#include <iostream>
QuestionHandler::QuestionHandler() {
	this->capacity = 10;
	this->questionCounter = 0;
	this->questions = new Question[this->capacity];
}

QuestionHandler::QuestionHandler(int rightAnswer, string question, string option1, string option2, string option3, string option4) {
	this->capacity = 10;
	this->questionCounter = 0;
	this->questions = new Question[this->capacity];
	this->questions[this->questionCounter++] = Question(rightAnswer, question, option1, option2, option3, option4);
}

QuestionHandler::~QuestionHandler() {
	delete [] this->questions;
}

void QuestionHandler::setQuestionsFromFile() {
	ifstream questionFile;
	int nrOfQuestions = 0;
	int rightAnswer = 0;
	string questionAndAnswers[5];
	questionFile.open("C:\\Users\\Majjke\\Documents\\Programmering\\niklas\\projekt\\projekt\\questions.txt");
	if (!questionFile.is_open()) {
		cout << "Error reading file";
	}
	else {
		questionFile >> nrOfQuestions;
		for (int i = 0; i < nrOfQuestions; i++) {
			questionFile >> rightAnswer;
			questionFile.ignore();
			getline(questionFile, questionAndAnswers[0]); //question
			getline(questionFile, questionAndAnswers[1]);
			getline(questionFile, questionAndAnswers[2]);
			getline(questionFile, questionAndAnswers[3]);
			getline(questionFile, questionAndAnswers[4]);
			this->questions[this->questionCounter++] = Question(rightAnswer, questionAndAnswers[0], questionAndAnswers[1], questionAndAnswers[2], questionAndAnswers[3], questionAndAnswers[4]);
		}
	}
	questionFile.close();
}

string QuestionHandler::getQuestion(int nr) {
	return this->questions[nr].getQuestion();
}

string QuestionHandler::getOp1(int nr) {
	return this->questions[nr].getOp1();
}

string QuestionHandler::getOp2(int nr) {
	return this->questions[nr].getOp2();
}

string QuestionHandler::getOp3(int nr) {
	return this->questions[nr].getOp3();
}

string QuestionHandler::getOp4(int nr) {
	return this->questions[nr].getOp4();
}

bool QuestionHandler::rightAnswer(int questionNr, int answer) {
	bool check = false;
	if (this->questions[questionNr].getRightAnswer() == answer) {
		check = true;
	}
	return check;
}

int QuestionHandler::getNrOfQuestions() {
	return this->questionCounter;
}