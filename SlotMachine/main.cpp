
//Slot machine - Created by Stace Frear

//Headers
#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Main Menu Enum

enum MainMenu
{
	Menu,
	Play,
	Credits,
	Exit,
};

//Heading function
void Heading();

//Clear input function
void ClearInput();

int main()
{
	//INITIATE VARIABLES

	//Variable for starting chips
	float fPlayerChips = 2000.0f;  // float so that my check for entered decimal number works correctly

	//Variable for user input
	int MainMenuInput = Menu;

	//Play variables
	float fBet = 0.0f;  //User bet amount - float so that my check for entered decimal number works correctly
	int num1, num2, num3; //Variables for three random numbers

	//Seed rand
	srand((unsigned int)(time(NULL)));

	//Slots Program
	do
	{
		//Show main menu
		Heading(); //call heading function
		//Provide output if an incorrect menu selection - will show at top of screen
		if (cin.fail())
		{
			ClearInput();
			cout << "   Please enter one of the below choices" << endl;
			cout << endl;
		}

		if (MainMenuInput != Play && MainMenuInput != Credits && MainMenuInput != Exit && MainMenuInput != Menu)
		{
			cout << MainMenuInput << " is not an available option. Please try again" << endl;
			cout << endl;
		}

		cout << "         Player's Chips: $" << fPlayerChips << endl;
		cout << endl;
		cout << "          1) Play Slots" << endl;
		cout << "          3) Quit Slot Machine" << endl;

		cout << endl;
		cout << "          Please enter your choice: ";

		//Take user input for main menu
		cin >> MainMenuInput;
		system("CLS");

		//Menu options (Play, Credits, Exit)
		switch (MainMenuInput)
		{
			case Play:
			{
				ClearInput();
				Heading(); //call heading function
				cout << "         Player's Chips: $" << fPlayerChips << endl << endl;
				cout << "         Please enter your bet: ";
				cin >> fBet;

				while ((cin.fail()) || (int(fBet) != fBet) || (fBet > fPlayerChips) || (fBet > fPlayerChips) || (fBet <= 0))
				{
					if (cin.fail())
					{
						ClearInput();
						system("CLS");
						Heading(); //call heading function
						cout << "     Please enter a numerical value" << endl;
						cout << endl;
						cout << "         Player's Chips: $" << fPlayerChips << endl << endl;
						cout << "         Please enter your bet: ";
						cin >> fBet;
					}
					//Check that Bet amount isn't a decimal (minimum amount $1)
					if (int(fBet) != fBet)
					{
						ClearInput();
						system("CLS");
						Heading(); //call heading function
						cout << "        Minimum Bet interval is $1" << endl;
						cout << endl;
						cout << "         Player's Chips: $" << fPlayerChips << endl << endl;
						cout << "         Please enter your bet: ";
						cin >> fBet;
					}
					//Prompt if bet amount is more than available chips
					if (fBet > fPlayerChips)
					{
						ClearInput();
						system("CLS");
						Heading(); //call heading function
						cout << "You do not have enough chips to make that bet" << endl;
						cout << "            Please try again" << endl;
						cout << endl;
						cout << "         Player's Chips: $" << fPlayerChips << endl << endl;
						cout << "         Please enter your bet: ";
						cin >> fBet;
					}
					//Prompt if bet amount is 0 or negative number
					if (fBet <= 0)
					{
						ClearInput();
						system("CLS");
						Heading(); //call heading function
						cout << "   That is not an acceptable bet amount" << endl;
						cout << "            Please try again" << endl;
						cout << endl;
						cout << "         Player's Chips: $" << fPlayerChips << endl << endl;
						cout << "         Please enter your bet: ";
						cin >> fBet;
					}
				}

				cout << endl;
				//Calculate three random numbers
				num1 = rand() % 6 + 2;
				num2 = rand() % 6 + 2;
				num3 = rand() % 6 + 2;

				//Display three random numbers on screen
				cout << "                   " << num1 << " " << num2 << " " << num3 << endl << endl;

				//Calculate winnings or loss
				//Three sevens 
				if (num1 == 7 && num2 == 7 && num3 == 7)
				{
					fPlayerChips = fPlayerChips + (fBet * 10);
					cout << "              Congratulations!" << endl;
					cout << "   You got three 7's and receive 10x your bet" << endl;
					cout << endl;
					cout << "        New Player Chip amount: " << fPlayerChips << endl;
				}
				//Three of a kind
				else if (num1 == num2 && num1 == num3)
				{
					fPlayerChips = fPlayerChips + (fBet * 5);
					cout << "              Congratulations!" << endl;
					cout << "You got three of a kind and receive 5x your bet" << endl;
					cout << endl;
					cout << "        New Player Chip amount: " << fPlayerChips << endl;
				}
				//Two of a kind
				else if (num1 == num2 || num1 == num3 || num2 == num3)
				{
					fPlayerChips = fPlayerChips + (fBet * 3);
					cout << "              Congratulations!" << endl;
					cout << "You got two of a kind and receive 3x your bet" << endl;
					cout << endl;
					cout << "        New Player Chip amount: " << fPlayerChips << endl;
				}
				//Anything else
				else
				{
					fPlayerChips = fPlayerChips - fBet;
					cout << "      You did not win. You lose your bet" << endl;
					cout << endl;
					cout << "        New Player Chip amount: " << fPlayerChips << endl;
				}
				cout << endl;
				cout << "      Press Enter to return to Main Menu"; //return to Main Menu
				ClearInput();
				cin.ignore(); //second ignore required for the 'Enter to exit' to work
				system("CLS");
				MainMenuInput = Menu;
				break;
			}
			default:
			{
				system("CLS"); //will clear the screen if not one of the options, then run the checks
			}
		}
	} while (MainMenuInput != Exit && fPlayerChips > 0);

	//What to do if player runs out of chips - close game
	if (fPlayerChips == 0)
	{
		Heading(); //call heading function
		cout << "   Unfortunately you have run out of chips" << endl;
		cout << "          Thank you for playing" << endl;
		cout << endl;
		cout << "          Press Enter to Exit";
		cin.ignore(); //required otherwise game will exit without showing above text
	}

	//If user chooses option 3 from Main Menu - Quit
	if (MainMenuInput == Exit)
	{
		system("CLS");
		Heading(); //call heading function
		cout << "         Thank you for playing" << endl;
		cout << endl;
		cout << "         Press Enter to Exit";
		cin.ignore();
		cin.ignore(); //these ignores required otherwise game will exit without showing above text
	}

	return 0;
}

void Heading()
{
	cout << "___________________________________________" << endl;
	cout << "|                                          |" << endl;
	cout << "|  $$$$$$   $$             $$              |" << endl;
	cout << "| $$    $$  $$             $$              |" << endl;
	cout << "| $$        $$   $$$$$$  $$$$$$    $$$$$$$ |" << endl;
	cout << "|  $$$$$$   $$  $$    $$   $$     $$       |" << endl;
	cout << "|       $$  $$  $$    $$   $$      $$$$$$  |" << endl;
	cout << "| $$    $$  $$  $$    $$   $$  $$       $$ |" << endl;
	cout << "|  $$$$$$   $$   $$$$$$     $$$$  $$$$$$$  |" << endl;
	cout << "|__________________________________________|" << endl;
	cout << endl;
}

void ClearInput()
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}