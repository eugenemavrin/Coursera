#include <iostream>
#include <algorithm>
#include "sum_reverse_sort.h"
using namespace std;

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	string reverse;
	for (int i = s.length() - 1; i >=0; i--) {
		reverse += s[i];
	}
	return reverse;
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << Sum(2, 5) << endl << Reverse("airaloh") << endl;
	vector<int> a = {1, 9, 5};
	Sort(a);
	for (auto i : a) {
		cout << i << " ";
	}
	return 0;
}
*/
