#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool bus_find(const string& stop_for_find, const vector<string>& stops) {
	bool isFind = false;
	for (auto s: stops) {
		if (stop_for_find == s) {
			isFind = true;
			break;
		}
	}
	return isFind;
}
vector<string> buses_for_stop(const string& stop,
							  const vector<string>& buses_line,
						      map<string, vector<string>>& buses) {
	vector<string> res;
	for(auto b : buses_line) {
		if (bus_find(stop, buses[b])) {
			res.push_back(b);
		}
	}
	return res;
}
bool bus_exist(const string& bus, const vector<string> buses_line) {
	bool flag = false;
	for(auto bl: buses_line) {
		if (bus == bl) {
			flag = true;
			break;
		}
	}
	return flag;
}
int main() {
	map<string, vector<string>> buses;
	vector<string> buses_line;
	int Q;
	cin >> Q;
	while (Q > 0) {
		string query;
		cin >> query;
		if (query == "NEW_BUS") {
			string bus, stop_temp;
			int stop_count;
			cin >> bus >> stop_count;
			buses_line.push_back(bus);
			while (stop_count > 0) {
				cin >> stop_temp;
				buses[bus].push_back(stop_temp);
				stop_count--;
			}
		}
		else if (query == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			vector<string> answer = buses_for_stop(stop, buses_line, buses);
			if (answer.size() > 0)
				for(auto a : answer) {
					cout << a << " ";
				}
			else cout << "No stop";
			cout << endl;
		}
		else if (query == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (bus_exist(bus, buses_line)) {
				for(auto stop : buses[bus]) { //получили вектор остановок маршрута bus
					cout << "Stop " << stop << ": ";
					vector<string> answer = buses_for_stop(stop, buses_line, buses);
					if (answer.size() > 1) {
						for(auto a : answer) {
							if (a != bus)
								cout << a << " ";
						}
					}
					else cout << "no interchange";
					cout << endl;
				}
			}
			else cout << "No bus" << endl;

		}
		else if (query == "ALL_BUSES") {
			if (buses_line.size() > 0) {
				for (auto b: buses) {
					cout << "Bus " << b.first << ": ";
					for (auto s : b.second) {
						cout << s << " ";
					}
					cout << endl;
				}
			}
			else cout << "No buses";
			cout << endl;
		}
		Q--;
	}
	return 0;
}
