// Weakness systems code

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

//function declarations
void SetEnemyWeaknessGrid(vector<int> &weaknesses);
int BattleLoopCommands();

int main() {
	srand(time(NULL));//initialize random seeding

	//variables to build out further
	bool gameOver = false;
	int currEnemyHP = 5;

	//Hold weakness and strength settings. -1 indicates a weakness. 
	//Order (0-5) - Agi , Zio, Garu, Bufu, Mudo, Hama
	vector<int> enemyWeaknessGrid(6, 0);
	SetEnemyWeaknessGrid(enemyWeaknessGrid);

	bool extraTurn = false;

	cout << "\nType 0 to quit game...\n\n";

	//add game loop here
	while (!gameOver) {
		//reset extra turn
		extraTurn = false;

		//check if enemy weakness set and if not set it
		int commandSelection = BattleLoopCommands();
		if (commandSelection == 0)
			break;

		cout << "Next phase here\n";

		//check if weakness match
		if (enemyWeaknessGrid.at(commandSelection - 1) == -1) {
			cout << "\nYou Hit the Enemy's Weakness!\n";
			extraTurn = true;//set extra turn to true
		}

		//if extra turn is true attack again
		if (extraTurn) {
			int commandSelection = BattleLoopCommands();

			//check if weakness match
			if (enemyWeaknessGrid.at(commandSelection - 1) == -1) {
				cout << "\nYou Hit the Enemy's Weakness Again!\n";
			}
		}

		cout << "\nEnemy Gets to Attack!\n";//enemy finally gets its turn...maybe
	}

	//message for closing the game
	cout << "\nClosing the game....";

	return 0;
}

//function definitions
//sets a single weakness based on random selection -- would usually be handled by game designer
void SetEnemyWeaknessGrid(vector<int>& weaknesses) {
	
	int weakSpot = rand() % weaknesses.size();
	cout << "\nWeakspot is...." << (weakSpot + 1);
	weaknesses.at(weakSpot) = -1;
}

int BattleLoopCommands() {
	cout << "Select Your Attack:\n";
	cout << "1 - Agi\n";
	cout << "2 - Zio\n";
	cout << "3 - Garu\n";
	cout << "4 - Bufu\n";
	cout << "5 - Mudo\n";
	cout << "6 - Hama\n\n";

	int userInput = 0;

	//get user input and check if a valid input type
	while (!(cin >> userInput)) {
		cin.clear(); //clear any bad input flags
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Incorrect Input. Please Select Your Attack:\n\n";
	}

	//check if input is a valid selection
	if (userInput >= 0 && userInput <= 6) {
		cout << "Attack Selected\n\n";
		return userInput;//return input
	}
	else {
		cout << "Invalid Selection\n\n";
		return BattleLoopCommands();//call method again to get valid input
	}
}