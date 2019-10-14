#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<int>& array) {
	for (const int& i : array) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> array(n);
	for (int& i : array) {
		cin >> i;
	}
	sort(begin(array), end(array), [] (int x, int y) { return abs(x) < abs (y); });
	printVector(array);
	return 0;
}
