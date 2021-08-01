#include"AVL.h"

AVL::AVL() {
	root = nullptr;
}

AVL::Node* AVL::createNode(Key key) {
	Node* newnode = new Node;
	newnode->key = key;
	newnode->left = nullptr;
	newnode->right = nullptr;
	newnode->h = 1;
	return newnode;
}

int AVL::updateHeight(Node* node) {
	return 1 + max(height(node->left), height(node->right));
}

int AVL::height(Node* root) {
	if (!root)
		return 0;
	return root->h;
}

AVL::Node* AVL::rightRotate(Node* y) {
	Node* x = y->left;
	y->left = x->right;
	x->right = y;
	y->h = updateHeight(y);
	x->h = updateHeight(x);
	return x;
}

AVL::Node* AVL::leftRotate(Node* y) {
	Node* x = y->right;
	y->right = x->left;
	x->left = y;
	y->h = updateHeight(y);
	x->h = updateHeight(x);
	return x;
}

int AVL::getBalanceFactor(Node* node) {
	if (!node)	return 0;
	return height(node->left) - height(node->right);
}

AVL::Node* AVL::insertNode(Node* root, Key key) {
	if (!root)
		return createNode(key);

	if (key < root->key)	root->left = insertNode(root->left, key);
	else if (key > root->key)	root->right = insertNode(root->right, key);
	else return root;

	root->h = updateHeight(root);

	int balance = getBalanceFactor(root);
	if (balance > 1) {
		if (key < root->left->key)
			return rightRotate(root);
		else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balance < -1) {
		if (key > root->right->key)
			return leftRotate(root);
		else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}
void AVL::insertNode(Key key) {
	root = insertNode(root, key);
}

void AVL::PreOrther(Node* root) {
	if (!root)	return;
	cout << root->key << " ";
	PreOrther(root->left);
	PreOrther(root->right);
}
void AVL::PreOrther() {
	PreOrther(root);
}

void AVL::InOrther(Node* root) {
	if (!root)	return;
	InOrther(root->left);
	cout << root->key << " ";
	InOrther(root->right);
}
void AVL::InOrther() {
	InOrther(root);
}

void AVL::PostOrther(Node* root) {
	if (!root)	return;
	PostOrther(root->left);
	PostOrther(root->right);
	cout << root->key << " ";
}
void AVL::PostOrther() {
	PostOrther(root);
}

int AVL::getHeightTree() {
	return root->h;
}

void AVL::search(Node* root, Key key, Node** res) {
	if (!root || key == root->key) {
		*res = root;
		return;
	}
	if (root->left && root->key > key)		search(root->left, key, res);
	if (root->right && root->key < key)		search(root->right, key, res);
}
bool AVL::search(Key key) {
	Node* res = nullptr;
	search(root, key, &res);
	return res != nullptr;
}

AVL::Node* AVL::minNode(Node* root) {
	if (!root)
		return root;
	while (root->left)
		root = root->left;
	return root;
}

AVL::Node* AVL::deleteNode(Node* root, Key key) {
	if (!root)	return root;

	if (key < root->key)	
		root->left = deleteNode(root->left, key);
	else if (key > root->key)	
		root->right = deleteNode(root->right, key);
	else {
		if (!root->left || !root->right) {
			Node* node = root->left ? root->left : root->right;
			if (!node) {
				node = root;
				root = nullptr;
			}
			else *root = *node;
			delete node;
		}
		else {
			Node* node = minNode(root->right);
			root->key = node->key;
			root->right = deleteNode(root->right, node->key);
		}
	}
	if (!root)	return root;

	root->h = updateHeight(root);
	int balance = getBalanceFactor(root);

	if (balance > 1) {
		if (getBalanceFactor(root->left) >= 0)
			return rightRotate(root);
		else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balance < -1) {
		if (getBalanceFactor(root->right) <= 0)
			return leftRotate(root);
		else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}
void AVL::deleteNode(Key key) {
	root = deleteNode(root, key);
}

void inputSelect(int& ans, int beg, int end)
{
	cout << "\tYour choice: ";
	cin >> ans;
	if (ans<beg || ans>end) {
		cout << "Enter error! Please enter again!\n";
		return inputSelect(ans, beg, end);
	}
}

void EnterDataNode(AVL& tree)
{
	double num;
	if (cin >> num)
		if ((int)(num)-num == 0) {
			tree.insertNode(num);
			EnterDataNode(tree);
		}

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}
}

void deleteNode(AVL& tree)
{
	cout << "\tEnter value to delete: ";	
	int n;	 cin >> n;
	tree.deleteNode(n);
	cout << "\tDelete successfully!\n\n"
		<< "\tDo you want to continue deleting? (y/n): ";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
		deleteNode(tree);
}