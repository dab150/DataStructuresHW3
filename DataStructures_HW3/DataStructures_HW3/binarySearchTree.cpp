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

//private functions
void bst::insert(int insertedValue, node *leaf)
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
			cout << "\n" << insertedValue << " has been inserted!\n";
		}
	}
	else if (insertedValue > leaf->value)
	{
		if (leaf->right != NULL)
			insert(insertedValue, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->value = insertedValue;
			leaf->right->left = NULL;	//set new node's children to NULL
			leaf->right->right = NULL;	//
			cout << "\n" << insertedValue << " has been inserted!\n";
		}
	}
	else if (insertedValue == leaf->value)
	{
		cout << "\n" << insertedValue << " is already in the tree, no need to insert.\n";
	}
}

node *bst::search(int searchValue, node *leaf)
{
	if (leaf != NULL)
	{
		if (searchValue == leaf->value)
		{
			cout << "\n" << searchValue << " has been found in the tree!\n";
			return leaf;		//found the desired node
		}
		if (searchValue < leaf->value)
			return search(searchValue, leaf->left);	//didn't find, search to the left
		else
			return search(searchValue, leaf->right); //didn't find, search to the right
	}
	else
	{
		cout << "\n" << searchValue << " was not found in the tree!\n";
		return NULL;	//not found
	}		
}

void bst::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
		cout << "\nThe tree has been destroyed!\n";
	}
}


//public functions
bst::bst()
{
	//initialize the bst
	root = NULL;
}

bst::~bst()
{
	destroy_tree();
}

void bst::insert(int insertedValue) //this will be used for inserting nodes after the root
{
	if (root != NULL)
	{
		insert(insertedValue, root);
	}
	else
	{
		root = new node;
		root->value = insertedValue;
		root->left = NULL;
		root->right = NULL;
		cout << "\n" << insertedValue << " has been inserted as the root node of the tree!\n";
	}
}

node *bst::search(int searchValue)
{
	return search(searchValue, root);
}

void bst::destroy_tree()
{
	destroy_tree(root);
}