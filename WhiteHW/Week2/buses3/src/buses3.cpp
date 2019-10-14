#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
	int bus_counter = 1;
	map<set<string>, int> buses;
	int Q;
	cin >> Q;
	while (Q > 0) {
		int count;
		cin >> count;
	    string s;
		set<string> new_bus_stops;
		for (int i = 0; i < count; ++i) {
		    cin >> s;
		    new_bus_stops.insert(s);
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
