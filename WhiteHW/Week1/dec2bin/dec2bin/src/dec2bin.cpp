#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> s;
	while (n > 1) {
		if (n % 2 == 1) {
			s.push_back(1);
		}
		else {
			s.push_back(0);
		}
		n /= 2;
	}
	s.push_back(1);
	for (int i = s.size() - 1; i >= 0; --i) {
		cout <<s[i];
	}

	return 0;
}
