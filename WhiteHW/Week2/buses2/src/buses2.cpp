#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int bus_counter = 1;
	map<vector<string>, int> buses;
	int Q;
	cin >> Q;
	while (Q > 0) {
		int count;
		cin >> count;
		vector<string> new_bus_stops(count);
		for (string& s: new_bus_stops) {
			cin >> s;
		}
		if (buses.count(new_bus_stops) == 1) {
			cout << "Already exists for " << buses[new_bus_stops] << endl;
		}
		else {
			buses[new_bus_stops] = bus_counter;
			cout << "New bus " << bus_counter << endl;
			bus_counter++;
		}
		Q--;
	}
	return 0;
}
