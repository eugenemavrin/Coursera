#include <iostream>
#include <sstream>
#include "phone_number.h"
using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
	stringstream s(international_number);
	string plus;
	getline(s, plus, '+');
	getline(s, country_code_, '-');
	getline(s, city_code_, '-');
	getline(s, local_number_);
	cout << plus << endl << country_code_ << endl << city_code_ << endl << local_number_ << endl;
	if (plus != "" || country_code_ == ""|| city_code_ == "" || local_number_ == "") {
		throw invalid_argument("Wrong format");
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}
string PhoneNumber::GetCityCode() const{
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}
/*
int main() {
	PhoneNumber number("+1-2-coursera-cpp");
	cout << "sad";
	return 0;
}
*/
