#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
	int c;
	cin >> c;
	vector<string> input(c);
	for (string& s: input) {
		cin >> s;
	}
	set<string> unique(begin(input), end(input));
	cout << unique.size() << endl;
	return 0;
}