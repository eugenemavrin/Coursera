#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct BusesForStopResponse {
	std::vector< std::string > buses;
	bool status = false;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::vector<std::string> sequence;
	std::map<std::string, std::vector<std::string>> stops;
	bool status = false;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	std::map<std::string, std::vector<std::string>> buses;
	bool status = false;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);
