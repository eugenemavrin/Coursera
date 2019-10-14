#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> countries;
	int Q;
	cin >> Q;
	while (Q > 0) {
		string query;
		cin >> query;
		if (query == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			if (countries.count(country) == 1) {
				if (countries[country] == new_capital) {
					cout << "Country " << country <<" hasn't changed its capital";
				}
				else {
					cout << "Country "<< country << " has changed its capital from "
							<< countries[country]  <<" to " << new_capital;

				}
			}
			else {
				cout << "Introduce new country " << country
						<<" with capital "<< new_capital;
			}
			countries[country] = new_capital;
			cout << endl;
		}
		else if (query == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (countries.count(old_country_name) == 0 || countries.count(new_country_name) == 1) {
				cout << "Incorrect rename, skip";
			}
			else {
				countries[new_country_name] = countries[old_country_name];
				countries.erase(old_country_name);
				cout << "Country " << old_country_name << " with capital " << countries[new_country_name] << " has been renamed to " << new_country_name;
			}
			cout << endl;
		}
		else if (query == "ABOUT") {
			string country;
			cin >> country;
			if (countries.count(country) == 1) {
				cout << "Country " << country << " has capital " << countries[country];
			}
			else cout << "Country " << country << " doesn't exist";
			cout << endl;
		}
		else if (query == "DUMP") {
			if (countries.size() > 0) {
				for (auto pair_cc : countries) {
					cout << pair_cc.first << "/" << pair_cc.second << " ";
				}

			}
			else cout << "There are no countries in the world";
			cout << endl;
		}
		Q--;
	}
	return 0;
}
