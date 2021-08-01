#include"AVL.h"

AVL::AVL() {
	root = nullptr;
}

void AVL::clearAVL(Node* root) {
	if (!root)	return;
	clearAVL(root->left);
	clearAVL(root->right);
	delete root;
	root = nullptr;
}
AVL::~AVL() {
	clearAVL(root);
	root = nullptr;
}
void AVL::clearAVL() {
	clearAVL(root);
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

	if (key < root->key)		root->left = insertNode(root->left, key);
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

void AVL::PreOrder(Node* root) {
	if (!root)	return;
	cout << root->key << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void AVL::PreOrder() {
	PreOrder(root);
}

void AVL::InOrder(Node* root) {
	if (!root)	return;
	InOrder(root->left);
	cout << root->key << " ";
	InOrder(root->right);
}
void AVL::InOrder() {
	InOrder(root);
}

void AVL::PostOrder(Node* root) {
	if (!root)	return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->key << " ";
}
void AVL::PostOrder() {
	PostOrder(root);
}

void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void AVL::printTreeGoto(Node* t, int h, int l, int r) {
	GoTo((l + r) / 2, h);
	if (t == nullptr) {
		cout << "*";
		return;
	}
	else	cout << t->key;
	printTreeGoto(t->left, h + 2, l, (l + r) / 2);
	printTreeGoto(t->right, h + 2, (l + r) / 2, r);
}
void AVL::printTree() {
	if (root->h > 5) {
		cout << "PreOrder: "; PreOrder();
		return;
	}
	int col = (1 << (root->h + 1));
	printTreeGoto(root, 0, 0, col);
	GoTo(0, 2 * root->h + 1);
}

AVL::Node* AVL::lowestCommonAncestor(Node* root, int p, int q) {
	if (!root || root->key == p || root->key == q)	return root;
	if (p < root->key && root->key < q)	return root;
	if (p > root->key && root->key > q)	return root;
	if (p < root->key)
		return lowestCommonAncestor(root->left, p, q);
	return lowestCommonAncestor(root->right, p, q);
}
int AVL::lowestCommonAncestor(int p, int q) {
	Node* node = lowestCommonAncestor(root, p, q);
	if (node)	return node->key;
	return INT_MIN;
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

void Demo() {
	AVL tree;
	int p, q;
	tree.insertNode(4);
	tree.insertNode(3);
	tree.insertNode(2);
	tree.insertNode(6);
	tree.insertNode(7);
	tree.insertNode(0);
	tree.insertNode(5);
	tree.insertNode(1);
	tree.printTree();
	cout << "\nEnter 2 elements to find the least common ancestor: "; cin >> p >> q;
	cout << "\n=> The least common ancestor of " << p << " and " << q << " is: " << tree.lowestCommonAncestor(p, q);
}