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

void bst::destroyTree(node *leaf)
{
	if (leaf != NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
		cout << "\nThe tree has been destroyed!\n";
	}
}

void bst::sort(node *leaf)
{
	if (leaf != NULL)
	{
		sort(leaf->right);
		cout << leaf->value << "\n";
		sort(leaf->left);	
	}
}

void bst::deleteNode(node *&leaf)
{
	node *current, *trailing, *temp;
	if (leaf == NULL) 
		cout << "Can not remove from empty tree \n";
	else if (leaf->left == NULL && leaf->right == NULL) 
	{
		//both children are empty
		temp = leaf;
		leaf = NULL;
		delete temp;
	}
	else if (leaf->left == NULL) 
	{
		//left child is empty
		temp = leaf;
		leaf = leaf->right;
		delete temp;
	}
	else if (leaf->right == NULL) 
	{
		//right child is empty
		temp = leaf;
		leaf = leaf->left;
		delete temp;
	}

	else 
	{
		//both children have items
		current = leaf->left;
		trailing = NULL;
		while (current->right != NULL)
		{
			trailing = current;
			current = current->right;
		}
		leaf->value = current->value;
		if (trailing == NULL)
			leaf->left = current->left;
		else
			trailing->right = current->left;
		delete current;
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
	destroyTree();
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

void bst::destroyTree()
{
	destroyTree(root);
}

void bst::sort()
{
	sort(root);
}

//void bst::deleteNode(int deleteValue)
//{
	//deleteNode(deleteValue, root);
//}

void bst::deleteNode(int deleteValue)
{
	node* current, *trailCurrent = NULL;
	bool found = false;
	if (root == NULL)
		cout << "The tree does not exist!";
	else 
	{
		current = root;
		while (current != NULL && !found) 
		{
			if (current->value == deleteValue)
				found = true;
			else 
			{
				trailCurrent = current;
				if (deleteValue < current->value)
					current = current->left;
				else
					current = current->right;
			}
		}
		
		if (current == NULL)
			cout << "Node to be deleted is not in tree \n";
		else if (found)
		{
			if (current == root)
				deleteNode(root);
			else if (deleteValue < trailCurrent->value)
				deleteNode(trailCurrent->left);
			else 
				deleteNode(trailCurrent->right);
		}
	}
}
