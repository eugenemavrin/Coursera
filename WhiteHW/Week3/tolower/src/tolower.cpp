#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(const vector<string>& array) {
	for (const string& i : array) {
		cout << i << ' ';
	}
	cout << endl;
}
string Tolower(string s) {
	for (char& c : s) {
		c = tolower(c);
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	vector<string> array(n);
	for (string& i : array) {
		cin >> i;
	}
	sort(begin(array), end(array), [] (string x, string y) { return Tolower(x) < Tolower(y); });
	printVector(array);
	return 0;
}
