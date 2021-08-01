#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

typedef int Key;
class AVL {
	struct Node {
		int key, h;
		Node* left, * right;
	};

	Node* root;

	Node* createNode(Key);
	int height(Node*);
	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	int getBalanceFactor(Node*);
	Node* insertNode(Node*, Key);
	int updateHeight(Node*);
	void PreOrder(Node*);
	void InOrder(Node*);
	void PostOrder(Node*);
	void printTreeGoto(Node*, int, int, int);
	void clearAVL(Node*);
	Node* lowestCommonAncestor(Node*, int, int);
public:
	AVL();
	void insertNode(Key);
	void PreOrder();
	void InOrder();
	void PostOrder();
	void clearAVL();
	void printTree();

	int lowestCommonAncestor(int, int);
	~AVL();
};

void inputSelect(int& ans, int beg, int end);
void EnterDataNode(AVL& tree);
void Demo();