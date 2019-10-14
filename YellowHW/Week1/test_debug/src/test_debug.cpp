
#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
	Test() {
		vector<vector<int> > s(3, vector<int>(5, 0));
		second = s;
	}
	int& At(int i) {
		return second[i][i];
	}
private:
	vector<vector<int> >  second;
};


int main() {
	Test t;
	t.At(2) = 6;
 	cout << t.At(2) << endl;
	return 0;
}
