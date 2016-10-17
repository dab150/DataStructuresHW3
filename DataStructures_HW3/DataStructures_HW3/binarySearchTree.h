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

//function prototypes
void insert(int insertedValue, node *root);
node *search(int searchValue, node *root);
