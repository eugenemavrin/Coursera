#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
	if (r.status) {
		for (const std::string &s : r.buses) {
			os << s << " ";
		}
	}
	else os << "No stop";
	os << std::endl;
  return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
	if (r.status) {
		for (const auto &s : r.sequence) {
			os << "Stop " << s << ": ";
			if (r.stops.at(s).size() > 0) {
				for (const auto &b : r.stops.at(s)) {
					os << b << " ";
				}
			}
			else std::cout << "no interchange";
			os << std::endl;
		}
	}
	else os << "No bus" << std::endl;
	return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
	if (r.status) {
		for (const auto &b : r.buses) {
			os << "Bus " << b.first << ": ";
			for (const auto &s : b.second) {
				os << s << " ";
			}
			os << std::endl;
		}
	}
	else std::cout << "No buses" << std::endl;
	return os;
}
