// lab 6 C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int user_turn, num, sticks, comp_choice;


	bool winner = false;



	cout << "Welcome to the game of NIM! Please enter an integer 9 or greater\n"
		<< "to indicate the number of sticks used in this game." << endl;
	cin >> sticks;

	while (sticks < 9){
		cout << "This is not an acceptable value.\n"
			<< "Please enter a number 9 or greater." << endl;
		cin >> sticks;
	}

	while (!winner){


		if (sticks >= 9){
			cout << "There are " << sticks << " sticks in the pile.\n"
				<< "Please enter the amount(between 1 and 4) that you would like to remove from the pile." << endl;
			cin >> num;
		}
		if ((num >= 1) && (num <= 4)){
			cout << "You have removed " << num << " sticks from the pile." << endl;
			sticks -= num;
			cout << "There are " << sticks << " left in the pile." << endl;
		}
		if ((num < 1) || (num > 4)){
			cout << "This is not an acceptable value.\n"
				<< "Please enter an amount between 1 and 4." << endl;
			cin >> num;
		}
		else if (sticks - num <= 0){
			cout << "Oops! There aren't enough sticks left to take this many from the pile.\n"
				<< "Please enter an acceptable amount." << endl;
			cin >> num;
		}
		if (sticks == 1){
			winner = true;
			cout << "Yay!!! You won the game of NIM! Congratulations!" << endl;
		}
		else{
			{
				srand((unsigned)time(NULL));
				comp_choice = rand() % 4;
				return comp_choice;
			}
			sticks -= comp_choice;
			cout << "The computer has chosen to take away " << sticks << " sticks from the pile.\n"
				<< "There are " << sticks << " sticks left in the pile." << endl;

			if (sticks == 1){
				winner = true;
				cout << "Awwww darn.  The computer won. Better luck next time!" << endl;
			}
		}
	}

	system("pause");
	return 0;
}

