//Data Structures HW3
//Daniel Barber-Cironi
//October 20, 2016
//Binary Tree


#include <stdio.h>
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	int command;
	int enteredValue;

	cout << "1. Insert Node \n";
	cout << "2. Search Node \n";
	cout << "3. Delete Node \n";

	cout << " \n \nEnter the corresponding number for the command you would like to perform:";
	cin >> command;

	switch (command)
	{
		case 1:
			cout << "Enter the number you would like to insert: ";
			cin >> enteredValue;
			insert(enteredValue, root);
			break;
		case 2:
			cout << "Enter the number you would like to search: ";
			cin >> enteredValue;
			search(enteredValue, root);
			break;
		case 3:
			cout << "Enter the number you would like to delete: ";
			cin >> enteredValue;
			break;
	}

	cin.get();
	cin.get();

}