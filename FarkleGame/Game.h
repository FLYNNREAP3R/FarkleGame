#pragma once
#include <string>
#include "Player.h"

using namespace std;
class Game
{
private:
	Player* players;
	int playerCount;

public:
	Game(int numPlayers)
	{
		Game::players = new Player[numPlayers];
		Game::playerCount = numPlayers;
	}
	void PlayerNames();
	void PlayerTurn(int i);
	void Rounds(int value);
	void PointMinToEnter();
	bool GameWin(int *mark);
	void RunGame();
};