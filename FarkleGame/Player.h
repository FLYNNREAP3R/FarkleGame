#pragma once
#include <string>

using namespace std;

class Player
{
private:
	string a_name;
	unsigned int a_score;
	unsigned int totalScore;

public:
	Player()
	{
		a_score = 0;
		a_name = "";
		totalScore = 0;
	}
	Player(string name)
	{
		a_name = name;
		a_score = 0;
		totalScore = 0;
	}

	// These serve as the accessors for the player names and scores
	void SetName(string name)
	{
		a_name = name;
		a_score = 0;
		totalScore = 0;
	}
	string GetName()
	{
		return a_name;
	}

	// This handles the scoring of each round as well as the total score of the game
	void addScore(int roundScore)
	{
		a_score = roundScore;
		totalScore += roundScore;
	}
	void SetScore(int score)
	{
		a_score = score;
	}
	int GetScore()
	{
		return a_score;
	}

	int GetTotalScore()
	{
		return totalScore;
	}

};
