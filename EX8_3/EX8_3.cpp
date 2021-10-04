#include"AVL.h"

int main()
{
	AVL tree;
	int ans;
	while (1) {
		system("cls");
		cout << "=============================================================================\n"
			<< "=  A PROGRAM TO TEST WHETHER ALL LEAVES OF AN AVL TREE HAVE THE SAME DEPTH  =\n"
			<< "=============================================================================\n\n";
		cout << "\tThe options:\n\t1. Run Demo program\n\t2. Enter your AVL tree\n\t3. Exit\n";
		inputSelect(ans, 1, 3);
		system("cls");
		if (ans == 1)	Demo();
		else if (ans == 2) {
			cout << "Enter the elements (enter \"n\" to finish entering):\n";
			EnterDataNode(tree);
			system("cls");	tree.printTree();
			cout << "\nAll leaves of an AVL tree have the same depth: " << boolalpha << tree.checkLeaves_sameDepth() << endl;
		}
		else return 0;
		cout << endl; system("pause");
		tree.clearAVL();
	}
}