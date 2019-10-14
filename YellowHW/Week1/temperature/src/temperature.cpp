#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for (auto &d : a) {
		cin >> d;
	}
	int64_t sum = 0;
	for (auto &d : a) {
		sum += d;
	}
	int average = sum / static_cast<int> (a.size());
	int count = 0;

	for (int i = 0; i < static_cast<int>(a.size()); ++i) {
		if (average < a[i]) {
			count++;
		}
	}
	cout << count << endl;

	for (int i = 0; i < static_cast<int>(a.size()); ++i) {
		if (average < a[i]) {
			cout << i << " ";
		}
	}

	return 0;
}
