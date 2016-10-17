/*	Data Structures Homework #3
Daniel Barber-Cironi
October 20, 2016
Binary Search Tree
Functions to create, search, insert nodes into BST
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include "binarySearchTree.h"

using namespace std;

void insert(int insertedValue, node *leaf)
{
	if (insertedValue < leaf->value)
	{
		if (leaf->left != NULL)
			insert(insertedValue, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->value = insertedValue;
			leaf->left->left = NULL;	//set new node's children to NULL
			leaf->left->right = NULL;	//
		}
	}
	else if (insertedValue >= leaf->value)
	{
		if (leaf->right != NULL)
			insert(insertedValue, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->value = insertedValue;
			leaf->right->left = NULL;	//set new node's children to NULL
			leaf->right->right = NULL;	//
		}
	}
	else if (leaf->value == NULL)	//first node
	{
		node *root = new node;
		root->value = insertedValue;
		root->left = NULL;
		root->right = NULL;
	}
}

node *search(int searchValue, node *leaf)
{
	if (leaf != NULL)
	{
		if (searchValue == leaf->value)
			return leaf;		//found the desired node
		if (searchValue < leaf->value)
			return search(searchValue, leaf->left);	//didn't find, search to the left
		else
			return search(searchValue, leaf->right); //didn't find, search to the right
	}
	else return NULL;	//not found
}