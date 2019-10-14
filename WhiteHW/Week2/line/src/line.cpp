#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector (const vector<bool>& line) {
	for (bool state : line)
		cout << state << endl;
}

int main() {
	int n;
	cin >> n;
	vector<bool> line(0, 0);
	while (n > 0) {
		string s;
		cin >> s;
		if (s == "WORRY") {
			int n_person;
			cin >> n_person;
			line[n_person] = true;
		}
		else if (s == "QUIET") {
			int n_person;
			cin >> n_person;
			line[n_person] = false;

		}
		else if (s == "COME") {
			// DONE
			int count;
			cin >> count;
			line.resize(count + line.size());
		}
		else if (s == "WORRY_COUNT") {
			int counter = 0;
			for (bool state : line)
				if (state) counter++;
			//cout << "Worried peoples: ";
			cout << counter << endl;
		}
		n--;
		//cout << "line size = " << line.size() << endl;
		//printVector(line);
	}
	return 0;
}