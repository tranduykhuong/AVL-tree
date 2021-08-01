#pragma once
#include<iostream>
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
	Node* deleteNode(Node*, Key);
	Node* minNode(Node*);
	int updateHeight(Node*);
	void PreOrther(Node*);
	void InOrther(Node*);
	void PostOrther(Node*);
	void search(Node*, Key, Node**);
public:
	AVL();
	void insertNode(Key);
	void PreOrther();
	void InOrther();
	void PostOrther();
	int getHeightTree();
	bool search(Key);
	void deleteNode(Key key);
	~AVL() {};
};

void inputSelect(int& ans, int beg, int end);
void EnterDataNode(AVL& tree);
void deleteNode(AVL& tree);