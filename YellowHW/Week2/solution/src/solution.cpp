#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {
		string bus;
	    is >> bus;
	    int stop_count;
	    is >> stop_count;
	    vector<string> stops(stop_count);
	    for (string& stop : stops) {
	    	is >> stop;
	    }
		q.type = QueryType::NewBus;
		q.bus = bus;
		q.stops = stops;

	}
	else if (operation_code == "BUSES_FOR_STOP") {
		string stop;
		is >> stop;
		q.type = QueryType::BusesForStop;
		q.stop = stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		string bus;
		is >> bus;
		q.bus = bus;
	}
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	vector<string> buses;
	bool status = false;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.status) {
		for (const string &s : r.buses) {
			os << s << " ";
		}
	}
	else os << "No stop";
	os << endl;
  return os;
}

struct StopsForBusResponse {
	vector<string> sequence;
	map<string, vector<string>> stops;
	bool status = false;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.status) {
		for (const auto &s : r.sequence) {
			os << "Stop " << s << ": ";
			if (r.stops.at(s).size() > 0) {
				for (const auto &b : r.stops.at(s)) {
					os << b << " ";
				}
			}
			else cout << "no interchange";
			os << endl;
		}
	}
	else os << "No bus" << endl;
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses;
	bool status = false;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.status) {
		for (const auto &b : r.buses) {
			os << "Bus " << b.first << ": ";
			for (const auto &s : b.second) {
				os << s << " ";
			}
			os << endl;
		}
	}
	else cout << "No buses" << endl;
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const string &s : stops) {
			stops_to_buses[s].push_back(bus);
		}
	}
	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse res;
		try {
			res.buses = stops_to_buses.at(stop);
			res.status = true;
		} catch(exception &ex) {
			res.status = false;
		}
		return res;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse res;
		try {
			for (const string &stop : buses_to_stops.at(bus)) { //buses_to_stops.at(bus) возвращает остановки
				res.stops[stop];
				for (const string &b : stops_to_buses.at(stop)) { //stops_to_buses.at(stop)) возвращает автобусы для остановки
					if (b != bus) {
						res.stops[stop].push_back(b);
					}
				}

			}
			res.sequence = buses_to_stops.at(bus);

			res.status = true;
		} catch (exception &ex) {
			res.status = false;
		}
		return res;
	}
	AllBusesResponse GetAllBuses() const {
		AllBusesResponse res;
		if(buses_to_stops.size() > 0) {
			res.buses = buses_to_stops;
			res.status = true;
		}
		else res.status = false;
		return res;
	}
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
