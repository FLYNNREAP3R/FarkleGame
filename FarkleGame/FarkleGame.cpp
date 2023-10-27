#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Game.h"

int main()
{
	void FarkleRules();
	srand(time(0));
	int numPlayers = 0;

	FarkleRules();

	cout << "How many players will be playing?" << endl;
	cin >> numPlayers;

	while (numPlayers < 2 || numPlayers > 8)
	{
		cin.ignore();
		cin.clear();

		cout << "Please choose a number between 2 and 8" << endl;
		cin >> numPlayers;
	}

	Game newGame(numPlayers);

	newGame.PlayerNames();
	newGame.PointMinToEnter();
	newGame.RunGame();


	return 0;

}

void FarkleRules()
{
	string farkleFile;
	ifstream farkleText;

	farkleText.open("Farkle Rules.txt");

	if (farkleText.is_open()) // This lets the developer(s) know if the .txt file opened correctly or not
	{
		while (getline(farkleText, farkleFile)) { // This prints the .txt file to the console for the user
			cout << farkleFile << endl;
		}

		farkleText.close();
	}
	else
	{
		cout << "Uh oh. Looks like something went wrong" << endl;
	}
}
