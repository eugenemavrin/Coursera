#include <iostream>
#include <map>
#include <string>
using namespace std;


template <typename key, typename value>
value& GetRefStrict(map<key, value>& M, const key& k) {
	try {
		M.at(k);
	} catch (exception &e) {
		throw runtime_error("key doesn't exist");
	}
	return (value&) M.at(k);
}

int main() {
	map<int, string> m = {{1, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue	return 0;
	return 0;
}
