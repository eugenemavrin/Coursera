#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	string first_name;
	string last_name;
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

int main() {
	int n;
	cin >> n;
	vector<Student> students(n);
	for (auto& s : students) {
		cin >> s.first_name >> s.last_name >> s.day >> s.month >> s.year;
	}
	int queue;
	cin >> queue;
	while (queue > 0) {
		string q;
		cin >> q;
			if (q == "name") {
				int i;
				cin >> i;
				if (i > 0 && i <= n)
					cout << students[i - 1].first_name << " " << students[i - 1].last_name << endl;
				else cout << "bad request" << endl;

			}
			else if (q == "date") {
				int i;
				cin >> i;
				if (i > 0 && i <= n)
					cout << students[i - 1].day << "." << students[i - 1].month << "." << students[i - 1].year << endl;
				else cout << "bad request" << endl;

			}
			else {
				string arg;
				cin >> arg;
				cout << "bad request" << endl;
			}
			queue--;
	}

	return 0;
}