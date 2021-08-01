#include"AVL.h"

int main()
{
	int n;
	do {
		system("cls");
		AVL tree;

		cout << "\t========================\n"
			<< "\t=\tAVL TREE       =\n"
			<< "\t========================\n\n";
		cout << "Enter the elements (enter \"n\" to finish entering):\n";
		EnterDataNode(tree);

		cout << "* Print tree to console screen\n"
			<< "   PreOrder:  ";		tree.PreOrther();
		cout << "\n   InOrder:   ";		tree.InOrther();
		cout << "\n   PostOrder: ";		tree.PostOrther();

		cout << "\n\n* Calculate tree height: " << tree.getHeightTree();

		cout << "\n\n* Identify whether a given value exists in the tree:\n"
			<< "\tEnter a value: ";		cin >> n;
		cout << "\tResult: ";
		if (tree.search(n))	cout << "Exists\n";
		else cout << "No exists\n";

		cout << "\n* Delete some value from the tree\n";
		deleteNode(tree);

		cout << "AVL tree after delete:\n"
			<< "PreOrder: ";	tree.PreOrther();

		cout << "\n\nPress 1 to continue, other key to stop...";
		cin >> n;

		tree.~AVL();
	} while (n == 1);
}