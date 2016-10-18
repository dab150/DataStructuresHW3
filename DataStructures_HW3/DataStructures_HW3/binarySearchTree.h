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
        void destroy_tree();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        
        node *root;
};


