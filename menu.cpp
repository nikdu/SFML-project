#include "menu.h"
#include <iostream>
using namespace std;
Menu::Menu()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error
	}
	//START GAME
	this->menu[0].setFont(font);
	this->menu[0].setString("Start Game");
	this->menu[0].setCharacterSize(30);
	this->menu[0].setColor(sf::Color::Red);
	this->menu[0].setPosition(sf::Vector2f(237, 150));
	//OPTIONS
	this->menu[1].setFont(font);
	this->menu[1].setString("High-Score List");
	this->menu[1].setCharacterSize(30);
	this->menu[1].setColor(sf::Color::White);
	this->menu[1].setPosition(sf::Vector2f(237, 210));
	//QUIT GAME
	this->menu[2].setFont(font);
	this->menu[2].setString("Quit Game");
	this->menu[2].setCharacterSize(30);
	this->menu[2].setColor(sf::Color::White);
	this->menu[2].setPosition(sf::Vector2f(237, 270));

	this->selectedItemIndex = 0;
}


Menu::~Menu()
{
}


void Menu::draw(sf::RenderWindow &window)
{
	//BILD
	sf::Texture menuTexture;
	if (!menuTexture.loadFromFile("menu.jpg"))
	{
		//error
	}
	sf::Sprite menuSprite;
	menuSprite.setTexture(menuTexture);
	window.clear();
	window.draw(menuSprite);
	//MENU TEXT
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(this->menu[i]);
	}
	window.display();
}

void Menu::moveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[this->selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex--;
		this->menu[this->selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		this->menu[this->selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex++;
		this->menu[this->selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Menu::getPressedItem()
{
	return this->selectedItemIndex;
}

void Menu::showMenu(sf::Event event, sf::RenderWindow &window, int &menu) {
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
			switch (this->getPressedItem())
		case 0:
			menu = 0;
			break;
		case 1:
			menu = 1;
			break;
		case 2:
			window.close();
			break;
		}
		break;
	}
}