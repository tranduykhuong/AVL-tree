#include"BST.h"

int main() {
	BST tree[100];
	int n;
	do {
		string file;
		system("cls");
		cout << "================================================================\n"
			<< "#   PROGRAM TO DETERMINE IF GIVEN BINARY TREES ARE AVL TREES   #\n"
			<< "================================================================\n\n";

		cout << "Enter 1 to read input.txt of program\nOr enter your file's name to read it: ";
		cin >> file;
		if (file == "1")	file = "input.txt";
		readFile(file, tree, n);

		ofstream fout("output.txt");	cout << endl;
		for (int i = 0; i < n; i++) {
			tree[i].PreOrder();
			if (tree[i].checkAVL_Tree()) {
				cout << "\nYes\n";
				fout << "Yes\n";
			}
			else {
				cout << "\nNo\n";
				fout << "No\n";
			}
		}
		cout << "\nSave to output.txt file successfully!\n";
		cout << "\nPress 1 to continue, other key to stop...";
		cin >> n;
	} while (n == 1);
}