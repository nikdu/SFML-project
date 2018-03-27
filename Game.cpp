#include "Game.h"
#include <iostream>
#include <sstream> 
#include <fstream>
//visa ruta med fraga samt alternativ
Game::Game()
{	
	string name;
	cout << "enter name: ";
	cin >> name;
	this->player.setName(name);
	this->questions.setQuestionsFromFile();
	this->nrOfQuestions = questions.getNrOfQuestions();
	if (!font.loadFromFile("arial.ttf"))
	{
		// error
	}
	this->rightAnswerCheck = true;
	this->outOfQuestions = false;
	int amount = 100;
	float x = 470;
	float y = 400;
	for (int i = 0; i < this->nrOfQuestions; i++)
	{
		string stringAmount;
		ostringstream convert;
		convert << amount;
		stringAmount = convert.str();

		this->level[i].setFont(font);
		this->level[i].setCharacterSize(40);
		this->level[i].setColor(sf::Color::Yellow);
		this->level[i].setPosition(x, y);
		this->level[i].setString(stringAmount);

		this->score[i] = amount;
		amount += 100;
		y -= 40;
	}
	this->level[0].setColor(sf::Color::Red);
	this->currentQuestion = 0;
	this->question.setFont(font);
	this->question.setCharacterSize(35);
	this->question.setColor(sf::Color::Black);
	this->question.setPosition(sf::Vector2f(30, 106));
	this->question.setString(questions.getQuestion(currentQuestion));

	this->choice[0].setFont(font);
	this->choice[0].setString(questions.getOp1(currentQuestion));
	this->choice[0].setCharacterSize(30);
	this->choice[0].setColor(sf::Color::Red);
	this->choice[0].setPosition(sf::Vector2f(27, 320));

	this->choice[1].setFont(font);
	this->choice[1].setString(questions.getOp2(currentQuestion));
	this->choice[1].setCharacterSize(30);
	this->choice[1].setColor(sf::Color::White);
	this->choice[1].setPosition(sf::Vector2f(27, 380));

	this->choice[2].setFont(font);
	this->choice[2].setString(questions.getOp3(currentQuestion));
	this->choice[2].setCharacterSize(30);
	this->choice[2].setColor(sf::Color::White);
	this->choice[2].setPosition(sf::Vector2f(233, 320));

	this->choice[3].setFont(font);
	this->choice[3].setString(questions.getOp4(currentQuestion));
	this->choice[3].setCharacterSize(30);
	this->choice[3].setColor(sf::Color::White);
	this->choice[3].setPosition(sf::Vector2f(233, 380));

	this->selectedItemIndex = 0;
}


Game::~Game() {}

void Game::runGame(sf::Event event, sf::RenderWindow &window) {
	this->draw(window);
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			window.close();
			break;
		case sf::Keyboard::Up:
			moveUp();
			break;
		case sf::Keyboard::Down:
			moveDown();
			break;
		case sf::Keyboard::Return:
			switch (getPressedItem()) {
			case 0:
				newQuestion(window, 0);
				break;
			case 1:
				newQuestion(window, 1);
				break;
			case 2:
				newQuestion(window, 2);
				break;
			case 3:
				newQuestion(window, 3);
				break;
			}
			break;
		}
	}
	draw(window);
}


void Game::setQuestions(sf::RenderWindow &window) {
	this->question.setString(questions.getQuestion(this->currentQuestion));
	this->choice[0].setString(questions.getOp1(this->currentQuestion));
	this->choice[1].setString(questions.getOp2(this->currentQuestion));
	this->choice[2].setString(questions.getOp3(this->currentQuestion));
	this->choice[3].setString(questions.getOp4(this->currentQuestion));
	this->selectedItemIndex = 0;
}

void Game::newQuestion(sf::RenderWindow &window, int nr) {
	this->setStandardChoices();
	this->rightAnswerCheck = checkRightAnswer(nr);
	if (rightAnswerCheck) {
		this->currentQuestion++;
		if (this->currentQuestion < nrOfQuestions && rightAnswerCheck) {
			this->question.setString(questions.getQuestion(this->currentQuestion));
			this->choice[0].setString(questions.getOp1(this->currentQuestion));
			this->choice[1].setString(questions.getOp2(this->currentQuestion));
			this->choice[2].setString(questions.getOp3(this->currentQuestion));
			this->choice[3].setString(questions.getOp4(this->currentQuestion));
			this->selectedItemIndex = 0;
			window.clear();
			for (int i = 0; i < MAX_NR_OF_CHOICES; i++)
			{
				window.draw(this->choice[i]);
			}
			this->level[currentQuestion].setColor(sf::Color::Red);
			this->level[currentQuestion - 1].setColor(sf::Color::Yellow);
		}
	}
}

void Game::draw(sf::RenderWindow &window)
{
	if (this->currentQuestion <= nrOfQuestions) {
		sf::Texture startGameTexture;
		if (!startGameTexture.loadFromFile("startGame1.jpg"))
		{
			//error
		}
		sf::Sprite startGameSprite;
		startGameSprite.setTexture(startGameTexture);
		window.clear();
		window.draw(startGameSprite);
		window.draw(this->question);
		for (int i = 0; i < TOTAL_LEVELS; i++)
		{
			if (i < MAX_NR_OF_CHOICES) {
				window.draw(this->choice[i]);
			}
			window.draw(this->level[i]);
		}
	}
	window.display();
}




void Game::moveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->choice[this->selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex--;
		this->choice[this->selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Game::moveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NR_OF_CHOICES)
	{
		this->choice[this->selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex++;
		this->choice[this->selectedItemIndex].setColor(sf::Color::Red);
	}
}


//void Game::moveLeft()
//{
//	if (this->selectedItemIndex - 2 < 0)
//	{
//		if (this->selectedItemIndex <= 0 || this->selectedItemIndex == 0)
//		{
//			this->setStandardChoices();
//		}
//		else {
//			this->choice[this->selectedItemIndex].setColor(sf::Color::White);
//			this->selectedItemIndex -= 2;
//			this->choice[this->selectedItemIndex].setColor(sf::Color::Red);
//		}
//	}
//}

//void Game::moveRight()
//{
//	if (this->selectedItemIndex + 2 < MAX_NR_OF_CHOICES)
//	{
//		if (this->selectedItemIndex > 4)
//		{
//			this->selectedItemIndex = 4;
//		}
//		else {
//			this->choice[this->selectedItemIndex].setColor(sf::Color::White);
//			this->selectedItemIndex += 2;
//			this->choice[this->selectedItemIndex].setColor(sf::Color::Red);
//		}
//	}
//}

int Game::getPressedItem()
{
	return this->selectedItemIndex;
}

bool Game::anymoreQuestions() {
	if (this->currentQuestion >= questions.getNrOfQuestions()) {
		this->outOfQuestions = true;
	}
	return this->outOfQuestions;
}

bool Game::checkRightAnswer(int nr) {
	bool check = false;
	if (this->questions.rightAnswer(currentQuestion,nr)) {
		check = true;
	}
	return check;
}

void Game::scoreScreen(sf::Event event, sf::RenderWindow &window, int &menu) {
	sf::Texture endGameTexture;
	if (!endGameTexture.loadFromFile("winner.jpg"))
	{
		//error
	}
	sf::Sprite endGameSprite;
	endGameSprite.setTexture(endGameTexture);
	sf::Text scoreText;
	sf::Text secondText;
	sf::Text goMenuText;
	secondText.setFont(font);
	secondText.setCharacterSize(50);
	secondText.setColor(sf::Color::Red);
	secondText.setPosition(sf::Vector2f(170, 130));
	if (rightAnswerCheck || this->currentQuestion >= this->nrOfQuestions) {
		secondText.setString("Congratulations!");
		scoreText.setString("You won " + level[currentQuestion - 1].getString());
		this->player.setScore(score[currentQuestion - 1]);
	}
	else if (!rightAnswerCheck) {
		secondText.setString("Wrong Answer");//
		scoreText.setString("Your score: " + level[currentQuestion].getString());
		this->player.setScore(score[currentQuestion]);
	}

	//money text
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setColor(sf::Color::Red);
	scoreText.setPosition(sf::Vector2f(160, 170));
	goMenuText.setFont(font);
	goMenuText.setCharacterSize(50);
	goMenuText.setColor(sf::Color::Red);
	goMenuText.setPosition(sf::Vector2f(160, 300));
	goMenuText.setString("Tap space to go back to menu");
	window.clear();
	window.draw(endGameSprite);
	window.draw(scoreText);
	window.draw(secondText);
	window.draw(goMenuText);
	window.display();
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			window.close();
			break;
		case sf::Keyboard::Space:
			menu = -1;
			break;
		}
	}
}

bool Game::getAnswerCheck() {
	return this->rightAnswerCheck;
}

void Game::setStandardChoices() {
	this->choice[0].setColor(sf::Color::Red);
	this->choice[1].setColor(sf::Color::White);
	this->choice[2].setColor(sf::Color::White);
	this->choice[3].setColor(sf::Color::White);
	this->selectedItemIndex = 0;
}

void Game::updateHighscoreList() {
	int nrOfPersons;
	fstream highScoreFile;
	string namesString[10];
	int scoreInt[10];
	highScoreFile.open("C:\\Users\\Majjke\\Documents\\Programmering\\niklas\\projekt\\projekt\\highScore.txt");
	if (!highScoreFile.is_open()) {
		//error
	}
	else {
		highScoreFile >> nrOfPersons;
		if (nrOfPersons == 0) {
			highScoreFile << this->player.getName() << endl;
			highScoreFile << this->player.getScore() << endl;
		}
		else {
			for (int i = 0; i < nrOfPersons; i++) {
				highScoreFile >> namesString[i];
				highScoreFile >> scoreInt[i];
				nrOfPersons++;
			}
		}
		for (int i = 0; i < nrOfPersons; i++) {
			if (this->player.getScore() > scoreInt[i]) {
				string stringTemp;
				int intTemp;
				stringTemp = namesString[i];
				intTemp = scoreInt[i];
				namesString[i] = player.getName();
				scoreInt[i] = player.getScore();
				for (int k = i + 1; k < nrOfPersons; k++) {
					namesString[k + 1] = namesString[k];
					scoreInt[k + 1] = scoreInt[k];
				}
				namesString[i + 1] = stringTemp;
				scoreInt[i + 1];
			}
		}
	}
	highScoreFile << nrOfPersons;
	for (int i = 0; i < nrOfPersons; i++) {
		highScoreFile << namesString[i] << endl;
		highScoreFile << scoreInt[i] << endl;
	}
	highScoreFile.close();
}

void Game::highScoreList(sf::RenderWindow &window) {
	float xName = 32;
	float yName = 30;
	float xScore = 330;
	float yScore = 35;
	sf::Texture highscoreTexture;
	ifstream highScoreFile;
	string namesString[10];
	string scoreString[10];
	sf::Text names[10];
	sf::Text scores[10];
	int nrOfPersons;
	highScoreFile.open("C:\\Users\\Majjke\\Documents\\Programmering\\niklas\\projekt\\projekt\\highScore.txt");
	if (!highScoreFile.is_open()) {
		//error
	}
	else {
		highScoreFile >> nrOfPersons;
		for (int i = 0; i < nrOfPersons; i++) {
			highScoreFile >> namesString[i];
			highScoreFile >> scoreString[i];
			names[i].setFont(font);
			names[i].setString(namesString[i]);
			names[i].setCharacterSize(30);
			names[i].setColor(sf::Color::Black);
			names[i].setPosition(sf::Vector2f(xName, yName));
			scores[i].setFont(font);
			scores[i].setString(scoreString[i]);
			scores[i].setCharacterSize(30);
			scores[i].setColor(sf::Color::Black);
			scores[i].setPosition(sf::Vector2f(xScore, yScore));
			yName += 35;
			yScore += 35;
		}
	}
	highScoreFile.close();
	if (!highscoreTexture.loadFromFile("highscore.jpg"))
	{
		//error
	}
	else {
		sf::Sprite highscoreSprite;
		highscoreSprite.setTexture(highscoreTexture);
		window.clear();
		window.draw(highscoreSprite);
		for (int i = 0; i < 5; i++)
		{
			window.draw(names[i]);
			window.draw(scores[i]);
		}
		window.display();
	}
}