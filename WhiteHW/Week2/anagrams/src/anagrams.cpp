#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> BuildCharCounters(string s) {
	map<char, int> res;
	for (char c : s) {
		++res[c];
	}
	return res;

}

int main() {
	int n = 0;
	cin >> n;
	while (n > 0) {
		string s1, s2;
		cin >> s1 >> s2;
		if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
		n--;
	}
	return 0;
}
