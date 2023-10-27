#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include "dice.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Dice dice;

void Game::RunGame()
{
	int numPlayers;
	int value = 0;

	while (!GameWin(&value))
	{
		Rounds(0);
	}

	int i = 0;
	int count = 0;

	for (i = value + 1; i < playerCount; ++i)
	{
		PlayerTurn(i);
		count++;
	}

	int max = 0;

	for (int i = 0; i < playerCount; i++)
	{
		if (players[i].GetTotalScore() > max)
		{
			max = players[i].GetTotalScore();
			value = i;
		}
	}

	cout << players[i].GetName() << "has won the game! Congratulations!" << endl;

	cout << "How many players will be playing?" << endl;
	cin >> numPlayers;

	while (numPlayers < 2 || numPlayers > 8)
	{
		cin.ignore();
		cin.clear();

		cout << "Please choose a number between 2 and 8" << endl;
		cin >> numPlayers;
	}
}

void Game::PlayerNames()
{
	string name;
	for (int i = 0; i < playerCount; ++i)
	{
		cout << "What is player " << (i + 1) << "'s name?: ";
		cin >> name;
		players[i].SetName(name);
	}
}

void Game::PlayerTurn(int i)
{
	int score = 0;
	char rerollChoice;
	
	cout << "It is " << players[i].GetName() << " turn to roll!" << endl;
	dice.DiceRoll();
	dice.ReadDice();

	score += dice.RoundScore();
	cout << "Points: " << score << endl;
	players[i].SetScore(score);

	if (dice.GetDiceCount() == 0)
	{
		cout << "You got all scoring dice! Let's go again!" << endl;
		players[i].addScore(score);
		dice.RerollDice();
		dice.ReadDice();
		score += dice.RoundScore();
		cout << "Points: " << score << endl;
		players[i].SetScore(score);
	}
	else if (dice.GetDiceCount() != 6)
	{
		cout << "There are " << dice.GetDiceCount() << " left for you to roll. Would you like to? (Y/N)";
		cin >> rerollChoice;
		cout << endl;
		
		if (rerollChoice == 'Y' || rerollChoice == 'y')
		{
			dice.RerollDice();
			dice.ReadDice();
			score = dice.RoundScore();
			cout << "Points: " << score << endl;
			if (players[i].GetScore() > score)
			{
				score = players[i].GetScore();
			}
			players[i].SetScore(score);
		}
		else if (rerollChoice == 'N' || rerollChoice == 'n')
		{
			cout << "You have ended your turn!" << endl;
			dice.SetDiceCount(0);
		}
	}

	dice.ResetRoll();
	cout << "You scored: " << players[i].GetScore() << endl << endl;
}

void Game::Rounds(int value)
{
	for (int i = value; i < playerCount; ++i)
	{
		PlayerTurn(i);
	}
}

void Game::PointMinToEnter()
{
	int score = 0;
	for (int i = 0; i < playerCount; ++i)
	{
		score = 0;
		while (score < 1000)
		{
			dice.DiceRoll();
			dice.ReadDice();
			score = dice.RoundScore();
			cout << "Points Scored: " << score << endl;
		}
		players[i].addScore(score);
		cout << players[i].GetName() << " made the point minimum point requirement!" << endl;
	}
	dice.SetDiceCount(0);
	cout << "All players have entered the game. Things are getting serious!" << endl;
}

bool Game::GameWin(int* mark)
{
	for (int i = 0; i < playerCount; i++)
	{
		if (players[i].GetTotalScore() >= 10000)
		{
			*mark = i;
			return true;
		}
	}
	return false;
}