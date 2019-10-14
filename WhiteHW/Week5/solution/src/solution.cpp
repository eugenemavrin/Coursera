#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои
class Date {
public:
	Date() {
		_year = 0;
		_month = 0;
		_day = 0;
	}
	Date(int y, int m, int d) {
		_year = y;
		_month = m;
		_day = d;
	}
	int GetYear() const {
		return _year;
	}
	void SetYear(const int& year) {
		_year = year;
	}
	int GetMonth() const {
		return _month;
	}
	void SetMonth(const int& month) {
		_month = month;
	}
	int GetDay() const {
		return _day;
	}
	void SetDay(const int& day) {
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	}
	else if (lhs.GetMonth() != rhs.GetMonth()) {
		return lhs.GetMonth() < rhs.GetMonth();
	}
	else if (lhs.GetDay() != rhs.GetDay()) {
		return lhs.GetDay() < rhs.GetDay();
	}
	return false;
}

Date ReadDate(string stringdate) {

	stringdate += "-";
	stringstream s(stringdate);
	stringdate.erase(stringdate.size()-1);
	int y, m, d;
	//string ds;
	char divider1, divider2, divider3;
	s >> y >> divider1 >> m >> divider2 >> d >> divider3;
	//проброс исключения
	if (divider1 != '-' || divider2 != '-' || divider3 != '-') {
		throw invalid_argument("Wrong date format: " + stringdate);
	}
	if(m > 12 || m < 1) {
		throw invalid_argument("Month value is invalid: " + to_string(m));
	}
	if(d > 31 || d < 1) {
		throw invalid_argument("Day value is invalid: " + to_string(d));
	}
	Date date(y, m, d);
	return date;
}
string ReadEvent(istream& s) {
	string event;
	s >> event;
	return event;
}

class Database {
public:
	explicit Database() {};
	void AddEvent(const Date& date, const string& event) {
			_db[date].insert(event);
			//cout << "added" << endl;
	}
	bool DeleteEvent(const Date& date, const string& event) {
		bool flag = false;
		if (_db.count(date) > 0) {
			if(_db.at(date).count(event) > 0) {
				_db.at(date).erase(event);
				flag = true;
			}
		}
		return flag;
	}
	int  DeleteDate(const Date& date) {
		int counter = 0;
		if (_db.count(date) > 0) {
			counter = _db.at(date).size();
			_db.erase(date);
		}
		return counter;
	}

	void Find(const Date& date) const {
		if (_db.count(date) > 0)
			for(const auto &event : _db.at(date)) {
				cout << event << endl;
			}
	}

	void Print() const {
		for (const auto &l : _db) {
			for (const auto &e : l.second) {
				cout << setfill('0') << setw(4) << l.first.GetYear() << "-" <<
						setfill('0') << setw(2) << l.first.GetMonth() << "-" <<
						setfill('0') << setw(2) << l.first.GetDay() <<
						" " << e << endl;;
			}
		}
	}
private:
	map<Date, set<string> > _db;
};


int main() {
	Database db;
	string command;

	while (getline(cin, command)) {
		//положим, что строки подаются согласно формату
		stringstream stream(command);
		string queue;
		stream >> queue;
		stream.ignore(1);
		if(queue == "Add") {
			Date date;
			try {
				string stringdate;
				getline(stream, stringdate, ' ');
				date = ReadDate(stringdate);
			} catch (invalid_argument &ex) {
				cout << ex.what();
				return 0;
			}
			string event = ReadEvent(stream);
			db.AddEvent(date, event);
		}
		else if (queue == "Del") {
			Date date;
			try {
				string stringdate;
				getline(stream, stringdate, ' ');
				date = ReadDate(stringdate);
			} catch (invalid_argument &ex) {
				cout << ex.what();
				return 0;
			}
			if (stream.tellg() != -1) {
				string event;
				stream >> event;
				db.DeleteEvent(date, event) ? cout << "Deleted successfully" << endl : cout << "Event not found" << endl;
			}
			else cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
		}
		else if (queue == "Find") {
			Date date;
			try {
				string stringdate;
				getline(stream, stringdate, ' ');
				date = ReadDate(stringdate);
			} catch (invalid_argument &ex) {
				cout << ex.what();
				return 0;
			}
			db.Find(date);
		}
		else if (queue == "Print") {
			db.Print();
		}
		else if (queue == "") {}
		else {
			cout << "Unknown command: " << queue << endl;
			return 0;
		}
		  	  // Считайте команды с потока ввода и обработайте каждую
		}

  return 0;
}
