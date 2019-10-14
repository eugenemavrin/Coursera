#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dim;
	dim = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = 0; //January;
	vector<vector<string>> tasks(dim[month]);
	while (n > 0) {
		string s;
		cin >> s;
		if (s == "ADD") {
			int day;
			cin >> day;
			--day;
			string s;
			cin >> s;
			tasks[day].push_back(s);
		}
		else if (s == "DUMP") {
			int day;
			cin >> day;
			--day;
			cout << tasks[day].size() << " ";
			for (auto task : tasks[day]) {
				cout << task << " ";
			}
			cout << endl;
		}
		else if (s == "NEXT") {
			month++;
			if (month == 12) month = 0;
			for (int i = dim[month]; i < dim[month - 1]; i++) {
				tasks[dim[month] - 1].insert(end(tasks[dim[month] - 1]), begin(tasks[i]), end(tasks[i]));
			}
			tasks.resize(dim[month]);
/*
			int i = 1;
			for (auto line : tasks) {
				cout << i << ": ";
				i++;
				for (auto t: line) {
					cout << t << " ";
				}
				cout << endl;
			}
			cout << "MONTH :" << month + 1;
*/
		}
		//else cout << "ERROR";
		n--;
	}
	return 0;
}