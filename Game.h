#pragma once
#include <SFML\Graphics.hpp>
#include "QuestionHandler.h"
#include "Player.h"
const static int MAX_NR_OF_CHOICES = 4;
const static int TOTAL_LEVELS = 10;
class Game
{
private:
	Player player;
	int selectedItemIndex;
	sf::Font font;
	sf::Text choice[MAX_NR_OF_CHOICES];
	sf::Text question;
	sf::Text level[TOTAL_LEVELS];
	int score[TOTAL_LEVELS];
	QuestionHandler questions;
	int currentQuestion;
	int nrOfQuestions;
	bool rightAnswerCheck;
	bool outOfQuestions;

public:
	Game();
	~Game();
	void Game::runGame(sf::Event event, sf::RenderWindow &window);
	void setQuestions(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void newQuestion(sf::RenderWindow &window, int nr);
	bool checkRightAnswer(int nr);
	void moveUp();
	void moveDown();
	//void moveRight();
	//void moveLeft();
	int getPressedItem();
	bool anymoreQuestions();
	void scoreScreen(sf::Event event, sf::RenderWindow &window, int &menu);
	bool getAnswerCheck();
	void setStandardChoices();
	void updateHighscoreList();
	void highScoreList(sf::RenderWindow &window);
};

