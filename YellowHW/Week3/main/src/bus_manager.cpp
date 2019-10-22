#include "bus_manager.h"


void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
		buses_to_stops[bus] = stops;
		for (const std::string &s : stops) {
			stops_to_buses[s].push_back(bus);
		}
	}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
		BusesForStopResponse res;
		try {
			res.buses = stops_to_buses.at(stop);
			res.status = true;
		} catch(std::exception &ex) {
			res.status = false;
		}
		return res;
	}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
		StopsForBusResponse res;
		try {
			for (const std::string &stop : buses_to_stops.at(bus)) { //buses_to_stops.at(bus) возвращает остановки
				res.stops[stop];
				for (const std::string &b : stops_to_buses.at(stop)) { //stops_to_buses.at(stop)) возвращает автобусы для остановки
					if (b != bus) {
						res.stops[stop].push_back(b);
					}
				}

			}
			res.sequence = buses_to_stops.at(bus);

			res.status = true;
		} catch (std::exception &ex) {
			res.status = false;
		}
		return res;
	}

AllBusesResponse BusManager::GetAllBuses() const {
		AllBusesResponse res;
		if(buses_to_stops.size() > 0) {
			res.buses = buses_to_stops;
			res.status = true;
		}
		else res.status = false;
		return res;
	}
