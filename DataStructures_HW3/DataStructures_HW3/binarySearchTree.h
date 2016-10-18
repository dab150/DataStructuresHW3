#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

//node structure
struct node {
public:
	int value;
	node *left;
	node *right;
};

class bst
{
    public:
        bst();
        ~bst();

        void insert(int key);
        node *search(int key);
        void destroyTree();
		void sort();
		void deleteNode(int deleteValue);

    private:
        void destroyTree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
		void sort(node * leaf);
		void deleteNode(node *&leaf);
        
        node *root;
};


