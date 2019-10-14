#include <iostream>
using namespace std;

bool isPalin(int n) {
	int a = n, rvrs = 0;
	while (a > 9) {
		rvrs += a % 10;
		rvrs *= 10;
		a /= 10;
	}
	return (rvrs + a) == n;
}

int main() {
	int a = 11;
	isPalin(a) ? cout << "yes\n" : cout << "no\n";
	return 0;
}

