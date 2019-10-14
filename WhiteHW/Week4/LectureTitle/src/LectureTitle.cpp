#include <iostream>
using namespace std;

struct Specialization {
	string value;
	explicit Specialization (const string& s) {
		value = s;
	}
};
struct Course {
	string value;
	explicit Course (const string& s) {
		value = s;
	}
};
struct Week {
	string value;
	explicit Week (const string& s) {
		value = s;
	}

};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle (const Specialization& s, const Course& c, const Week& w) {
	  specialization = s.value;
	  course = c.value;
	  week = w.value;
  }
};

int main() {
	return 0;
}
