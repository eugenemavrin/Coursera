#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<int, string> m;
	m[1] = "odd";
	m[2] = "even";
	m[3] = "one";
	m[2] = "two";
	m.erase(1);
	m[3] = "three";
	m.erase(4);
	m[5] = "five";
	cout << m.size();
	return 0;
}
