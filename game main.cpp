#include <iostream>
#include "menu.h"
#include "Game.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Who wants to be a millionaire");
	//meny
	Menu menu;
	Game game;
	sf::Event event;
	int menuCheck = -1;
	bool rightAnswer = true;
	bool outOfQuestions = false;
	bool updatedHighScore = false;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				if (menuCheck == -1) {
					menu.showMenu(event, window, menuCheck);
					updatedHighScore = false;
				}
				else if (menuCheck == 0)
				{
					game.runGame(event, window);
					rightAnswer = game.getAnswerCheck();
					outOfQuestions = game.anymoreQuestions();
					if (!rightAnswer || outOfQuestions) {
						menuCheck = 2;
					}
				}
				else if (menuCheck == 1) {
					game.highScoreList(window);
				}
				else if (menuCheck == 2) {
					game.scoreScreen(event, window, menuCheck);
					if (!updatedHighScore) {
						//game.updateHighscoreList();
						updatedHighScore = true;
					}
				}
			}
		}
	}
	return 0;
}
