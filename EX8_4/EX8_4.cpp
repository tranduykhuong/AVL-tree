#include"AVL.h"

int main()
{
	AVL tree;
	int ans;
	while (1) {
		system("cls");
		cout << "==============================================================================\n"
			<< "=  PROGRAM TO FIND THE LEAST COMMON ANCESTOR FOR ANY TWO GIVEN NODES IN AVL  =\n"
			<< "==============================================================================\n\n";
		cout << "\tThe options:\n\t1. Run Demo program\n\t2. Enter your AVL tree\n\t3. Exit\n";
		inputSelect(ans, 1, 3);
		system("cls");
		if (ans == 1)	Demo();
		else if (ans == 2) {
			cout << "Enter the elements (enter \"n\" to finish entering):\n";
			EnterDataNode(tree);
			system("cls");	tree.printTree();
			int p, q;
			cout << "\nEnter 2 elements to find the least common ancestor: "; cin >> p >> q;
			cout << "\n=> The least common ancestor of " << p << " and " << q << " is: ";
			cout << tree.lowestCommonAncestor(p, q);
		}
		else return 0;
		cout << endl; system("pause");
		tree.clearAVL();
	}
}