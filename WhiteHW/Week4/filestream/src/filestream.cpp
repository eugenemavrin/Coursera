#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream text("input.txt");
	int tmp, row, col;
	string s;
	//ofstream otext("output.txt");
	if(text.is_open()) {
		text >> row >> col;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (j < col - 1){
					text >> tmp;
					text.ignore(1);
					cout << setw(10) << tmp << " ";
				}
				else {
					text >> tmp;
					cout << setw(10) << tmp;
				}

			}
			if (i < row - 1)
				cout << endl;
		}
	}
	return 0;
}
