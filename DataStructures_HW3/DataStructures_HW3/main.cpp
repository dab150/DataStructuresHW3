//Data Structures HW3
//Daniel Barber-Cironi
//October 20, 2016
//Binary Tree


#include <stdio.h>
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void printMenu();
void showContinueScreen();

//create our tree object from our bst class
bst tree = bst::bst();

int main()
{

	printMenu();

	cin.get();
	cin.get();

}

void printMenu()
{
	int command;
	int enteredValue;

	cout << "\n\n\n";
	cout << "1. Insert Node \n";
	cout << "2. Search Node \n";
	cout << "3. Delete Node \n";
	cout << "4. Sort in Ascending Order \n";

	cout << " \n \nEnter the corresponding number for the command you would like to perform:";
	cin >> command;

	switch (command)
	{
	case 1:
		cout << "Enter the number you would like to insert: ";
		cin >> enteredValue;
		tree.insert(enteredValue);
		break;
	case 2:
		cout << "Enter the number you would like to search: ";
		cin >> enteredValue;
		tree.search(enteredValue);
		break;
	case 3:
		cout << "Enter the number you would like to delete: ";
		cin >> enteredValue;
		tree.deleteNode(enteredValue);
		break;
	case 4:
		tree.sort();
		break;
	}

	showContinueScreen();
}

void showContinueScreen()
{
	char input;
	cout << "\n";
	cout << "Would you like to continue with another operation? \n";
	cout << "Enter 'Y' to continue or 'N' to exit the program. \n";
	cin >> input;
	if (input == 'Y' || input == 'y')
	{
		printMenu();
	}
	else if (input == 'N' || input == 'n')
	{
		exit(0);
	}
	else
	{
		cout << " \n Error: Please enter either 'Y' or 'N'. \n";
		showContinueScreen();
	}
}