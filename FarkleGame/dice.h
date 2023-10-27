#pragma once
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
class Dice
{
private:
	int DiceNumbers[6];
	bool RerollDiceNumbers[6];
	int RerollCount;
	int diceCount;

public:
	
	Dice()
	{
		for (int i = 0; i < 6; ++i)
		{
			DiceNumbers[i] = 0;
			RerollDiceNumbers[i] = false;
		}
		RerollCount = 0;
		diceCount = 0;
	}

	void DiceRoll();
	void RerollDice();
	void ResetRoll();

	// Determines the scores based on the dice values and the Farkle rules
	int RoundScore();

	// Displays the dice values
	void ReadDice();

	// The accessors for dice count
	void SetDiceCount(int value)
	{
		diceCount = value;
	}
	int GetDiceCount()
	{
		return diceCount;
	}

};
