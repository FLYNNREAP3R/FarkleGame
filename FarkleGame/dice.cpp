#include "dice.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

// Rolls the dice 
void Dice::DiceRoll()
{
	for (int i = 0; i < 6; ++i)
	{
		DiceNumbers[i] = (rand() % 6 + 1);
		if (DiceNumbers[i] != 1 && DiceNumbers[i] != 5)
		{
			RerollDiceNumbers[i] = true;
		}
	}
}

// Rerolls the non point dice
void Dice::RerollDice()
{
	for (int i = 0; i < 6; ++i)
	{
		if (RerollDiceNumbers[i] == true)
		{
			DiceNumbers[i] = (rand() % 6 + 1);
		}
	}
}

// Resets Dice to false
void Dice::ResetRoll()
{
	for (int i = 0; i < 6; ++i)
	{
		RerollDiceNumbers[i] = false;
	}
}

// Gets the score of the dice based on the displayed dice
int Dice::RoundScore()
{
	int oneCount = 0;
	int twoCount = 0;
	int threeCount = 0;
	int fourCount = 0;
	int fiveCount = 0;
	int sixCount = 0;
	int score = 0;
	diceCount = 0;

	for (int i = 0; i < 6; ++i)
	{
		switch (DiceNumbers[i])
		{
			case 1:
				score += 100;
				oneCount++;
				break;
			case 2:
				twoCount++;
				diceCount++;
				break;
			case 3:
				threeCount++;
				diceCount++;
				break;
			case 4:
				fourCount++;
				diceCount++;
				break;
			case 5:
				score += 50;
				fiveCount++;
				break;
			case 6:
				sixCount++;
				diceCount++;
				break;
		}
	}

	if (diceCount == 6)
	{
		cout << "Farkle!" << endl;
		score = 0;
	}
	else
	{
		if (oneCount >= 3)
		{
			score = (score - 300) + 1000;
		}
		else if (twoCount >= 3)
		{
			score += 200;
			for (int i = 0; i < 6; i++)
			{
				if (DiceNumbers[i] == 2)
				{
					DiceNumbers[i] = false;
				}
			}
			diceCount -= 3;
		}
		else if (threeCount >= 3)
		{
			score += 300;
			for (int i = 0; i < 6; i++)
			{
				if (DiceNumbers[i] == 3)
				{
					RerollDiceNumbers[i] = false;
				}
			}
			diceCount -= 3;
		}
		else if (fourCount >= 3)
		{
			score += 400;
			for (int i = 0; i < 6; i++)
			{
				if (DiceNumbers[i] == 4)
				{
					RerollDiceNumbers[i] = false;
				}
			}
			diceCount -= 3;
		}
		else if (fiveCount >= 3)
		{
			score = (score - 150) + 500;
		}
		else if (sixCount >= 3)
		{
			score += 600;
			for (int i = 0; i < 6; i++)
			{
				if (DiceNumbers[i] == 6)
				{
					RerollDiceNumbers[i] = false;
				}
			}
			diceCount -= 3;
		}
	}
	return score;
}

void Dice::ReadDice()
{
	for (int i = 0; i < 6; ++i)
	{
		cout << DiceNumbers[i] << " ";
	}
}
