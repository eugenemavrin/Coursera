#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, set<string>> syn_voc;
	int Q;
	cin >> Q;
	while (Q > 0) {
		string queue;
		cin >> queue;
		if (queue == "ADD") {
			string s1, s2;
			cin >> s1 >> s2;
			syn_voc[s1].insert(s2);
			syn_voc[s2].insert(s1);
		}
		else if (queue == "COUNT") {
			string s;
			cin >> s;
			if (syn_voc.count(s) > 0)
				cout << syn_voc[s].size() << endl;
			else cout << 0 << endl;
		}
		else if (queue == "CHECK") {
			string s1, s2;
			cin >> s1 >> s2;
			if (syn_voc.count(s1) > 0 && syn_voc[s1].count(s2) > 0) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
		Q--;
	}
	return 0;
}
