#include <string>
#pragma once
using namespace std;
class Player
{
private:
	string name;
	int score;
public:
	Player(string name, int score);
	Player();
	~Player();
	int getScore();
	void setScore(int score);
	string getName();
	void setName(string name);
};