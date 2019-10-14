#include <iostream>
using namespace std;


int myreverse(int n) {
	int res;
	while (n > 0) {
		res = (res + n % 10) * 10;
		n /= 10;
	}
	return res / 10;
}


int main() {
	while (1) {
		int n, revn;
		cout << "n = ";
		cin >> n;
		revn = myreverse(n);
		if (revn == n)
			cout << "yeas" << endl;
		else cout << "noo" << endl;
		cout << revn << endl;
	}
	return 0;
}
