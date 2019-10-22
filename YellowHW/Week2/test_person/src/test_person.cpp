#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    string first_name = FindNameByYear(first_names, year);
    string last_name = FindNameByYear(last_names, year);

    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

void TestOne() {
	Person person;
	  vector<int> d;
	  person.ChangeFirstName(100, "Polina");
	  person.ChangeLastName(200, "Sergeeva");
	  for (int i = -100; i < 100; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Incognito";
		  AssertEqual(person.GetFullName(i), "Incognito", s.str());
	  }
	  for (int i = 100; i < 200; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Polina with unknown last name";
		  AssertEqual(person.GetFullName(i), "Polina with unknown last name", s.str());
	  }
	  for (int i = 200; i < 300; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Polina Sergeeva";
		  AssertEqual(person.GetFullName(i), "Polina Sergeeva", s.str());
	  }

}

void TestTwo() {
	Person person;
	  vector<int> d;
	  person.ChangeFirstName(200, "Polina");
	  person.ChangeLastName(100, "Sergeeva");
	  for (int i = -100; i < 100; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Incognito";
		  AssertEqual(person.GetFullName(i), "Incognito", s.str());
	  }
	  for (int i = 100; i < 200; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Sergeeva with unknown first name";
		  AssertEqual(person.GetFullName(i), "Sergeeva with unknown first name", s.str());
	  }
	  for (int i = 200; i < 300; i++) {
		  stringstream s;
		  s << "In year" << i << "Person is Polina Sergeeva";
		  AssertEqual(person.GetFullName(i), "Polina Sergeeva", s.str());
	  }

}

int main() {
  TestRunner runner;
  runner.RunTest(TestOne, "TestOne");
  runner.RunTest(TestTwo, "TestTwo");

  // добавьте сюда свои тесты
  return 0;
}
