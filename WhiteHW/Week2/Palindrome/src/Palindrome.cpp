#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
	string revs, tail;
	for (char c : s) {
		revs = c + tail;
		tail = revs;
	}

	return s == revs;
}

int main() {
	string s;
	cin >> s;
	cout << IsPalindrom(s);
	return 0;
}
