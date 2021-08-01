#include"BST.h"

BST::BST() {
	root = nullptr;
	n = 0;
}

BST::Node* BST::createNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	node->h = 1;
	return node;
}

int BST::updateHeight(Node* root) {
	return 1 + max(height(root->left), height(root->right));
}

int BST::height(Node* root) {
	if (!root)	return 0;
	return root->h;
}
void BST::insert(Node*& root, int data) {
	if (!root) {
		root = createNode(data);
		n++;
		return;
	}
	if (root->data == data)	return;
	if (root->data > data) 
		insert(root->left, data);
	if (root->data < data)
		insert(root->right, data);
	root->h = updateHeight(root);
}
void BST::insertNode(int data) {
	insert(root, data);
}

int BST::getBalance(Node* root) {
	if (!root)	return 0;
	return height(root->left) - height(root->right);
}

void BST::checkAVL_Tree(Node * root, bool &k) {
	if (!root)	return;
	if (abs(getBalance(root)) > 1)
		k = false;
	checkAVL_Tree(root->left, k);
	checkAVL_Tree(root->right, k);
}
bool BST::checkAVL_Tree() {
	bool k = true;
	checkAVL_Tree(root, k);
	return k;
}

void BST::PreOrder(Node* root) {
	if (!root)	return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void BST::PreOrder() {
	PreOrder(root);
}

void readFile(string filename, BST tree[], int& n) {
	ifstream fin(filename);
	if (!fin)	return;

	fin >> n;
	int x; char c;
	for (int i = 0; i < n; i++) {
		while (1) {
			fin >> x;
			c = fin.get();
			tree[i].insertNode(x);
			if (c == '\n' || fin.fail())
				break;
		}
	}
	fin.close();
}
