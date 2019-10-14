#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v){
	vector<int> oldv = v, res;
    res.clear();
	for (int i = oldv.size() - 1; i >= 0; --i) {
		res.push_back(oldv[i]);
	}
	return res;
}

int main() {
	vector<int> f= {1, 5, 3, 4, 2}, x;
    x = Reversed (f);
    for (auto z : x) {
		cout << z << " ";
	}
	return 0;
}
