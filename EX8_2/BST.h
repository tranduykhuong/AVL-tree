#include<iostream>
#include<fstream>
using namespace std;

class BST {
	struct Node {
		int data;
		Node* left, * right;
		int h;
	};
	int n;
	Node* root;

	Node* createNode(int);
	void insert(Node*&, int);
	int height(Node*);
	int updateHeight(Node*);
	int getBalance(Node*);
	void PreOrder(Node*);
	void checkAVL_Tree(Node*, bool&);

public:
	BST();
	void insertNode(int);
	void PreOrder();
	bool checkAVL_Tree();
	~BST() {};
};

void readFile(string, BST tree[], int&);