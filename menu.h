#pragma once
#include <SFML\Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
	Menu();
	~Menu();
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem();
	void Menu::showMenu(sf::Event event, sf::RenderWindow &window, int &menu);
	
};

