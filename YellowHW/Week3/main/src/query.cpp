#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	std::string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {
		std::string bus;
	    is >> bus;
	    int stop_count;
	    is >> stop_count;
	    std::vector<std::string> stops(stop_count);
	    for (std::string& stop : stops) {
	    	is >> stop;
	    }
		q.type = QueryType::NewBus;
		q.bus = bus;
		q.stops = stops;

	}
	else if (operation_code == "BUSES_FOR_STOP") {
		std::string stop;
		is >> stop;
		q.type = QueryType::BusesForStop;
		q.stop = stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		std::string bus;
		is >> bus;
		q.bus = bus;
	}
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}
