#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool f2nd = false;
	bool isPrint = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'f') {
			if (f2nd) {
				cout << i;
				isPrint = true;
				break;
			}
			f2nd = true;
		}
	}
	if (!isPrint) {
		if(f2nd)
			cout << "-1";
		else cout << "-2";
	}
	return 0;
}
