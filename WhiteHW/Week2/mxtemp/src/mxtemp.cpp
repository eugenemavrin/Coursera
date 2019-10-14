#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t;
	cin >> n;
	vector<int> temp(n);
	vector<int> index;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	int sum = 0;
	for (int i : temp) {
		sum = sum + i;
	}
	sum /= n;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (sum < temp[i]) {
			res++;
			index.push_back(i);
		}
	}
	cout << res << endl;
	for (int i : index) {
		cout << i << " ";
	}
	return 0;
}
