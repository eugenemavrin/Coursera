#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "array length = ";
	unsigned int l;
	cin >> l;
	vector <int> array(l);
	for (int& d : array) {
		cin >> d;
	}
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] < 0) {
			array.erase(array.begin() + i);
			--i;
		}
	}
	for (int& d : array) {
		cout << d << " ";
	}
	return 0;
}
