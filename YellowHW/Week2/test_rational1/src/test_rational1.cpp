#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>

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

class Rational {
public:
    Rational() {
    	// Реализуйте конструктор по умолчанию
    	_numerator = 0;
    	_denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
    	if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
    	else {
    		_numerator = numerator;
			_denominator = denominator;
			format(_numerator, _denominator);
    	}
    }

    int Numerator() const { // числитель
        // Реализуйте этот метод
    	return _numerator;
    }

    int Denominator() const { // знаменатель
        // Реализуйте этот метод
    	return _denominator;
    }
private:
    // Добавьте поля
    int _numerator;
    int _denominator;

    void format(int& numerator, int& denominator) {
    	// форматировали знак
    	if (denominator < 0) {
    		denominator *= -1;
    		numerator *= -1;
    	}
    	// форматировали числа дроби
    	int divisor = greatest_common_divisor(abs(numerator), abs(denominator));
    	numerator /= divisor;
    	denominator /= divisor;

    }
    //greatest common divisor
    int greatest_common_divisor (int a, int b) {
    	while (a != 0 & b != 0) {
    		if (a > b) {
    			a = a % b;
    		}
    		else b = b % a;
    	}
    	return a + b;
    }

};

bool operator== (Rational r1, Rational r2) {
	return r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator();
}
bool operator!= (Rational r1, Rational r2) {
	return r1.Numerator() != r2.Numerator() && r1.Denominator() != r2.Denominator();
}

Rational operator+ (Rational r1, Rational r2) {
	int numerator = r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

Rational operator- (Rational r1, Rational r2) {
	int numerator = r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

Rational operator/ (Rational r1, Rational r2) {
	if (r2.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	else {
		int numerator = r1.Numerator() * r2.Denominator();
		int denominator = r1.Denominator() * r2.Numerator();
		Rational r3(numerator, denominator);
		return r3;
	}
}

Rational operator* (Rational r1, Rational r2) {
	int numerator = r1.Numerator() * r2.Numerator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

bool operator< (Rational r1, Rational r2){
	return (r1 - r2).Numerator() < 0;
}

bool operator> (Rational r1, Rational r2){
	return (r1 - r2).Numerator() > 0;
}

ostream& operator<<(ostream& stream, Rational r1) {
	stream << r1.Numerator() << "/" <<r1.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational &r1) {

	if (stream.tellg() != -1) {
		int numerator;
		int denominator;
		stream >> numerator;
		stream.ignore(1);
		stream >> denominator;
		r1 = Rational(numerator, denominator);
	}
	return stream;
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (!(t == u)) {
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

/*
void TestDivToZero() {
	Rational r1;
	string s;
	for (int i = -100; i < 100; i++) {
		if (i != 0) {
			try {
				r1 = Rational(i, 0);
			}
			catch (invalid_argument &ex) {
				s = ex.what();
			}
			AssertEqual(s, "Invalid argument", "Denomirator is Invalid argument");
		}
	}
}
*/
template<class A, class B>
int GCD (A a, B b) {
	while (a != 0 & b != 0) {
		if (a > b) {
			a = a % b;
		}
		else b = b % a;
	}
	return a + b;
}

void TestToNOD() {
	for (int i = 1; i < 100; i++) {
		int a = i;
		int b = a * i * 5;
		Rational r1(a, b);
		int gcd = GCD(a, b);
		a /= gcd;
		b /= gcd;
		Rational r2(a, b);
		AssertEqual(r1, r2, "Numerator and/or Denomirator doen't formatted NOD");

	}
}

void TestToOmen() {
	mt19937 gen;
	uniform_real_distribution<> unif(-100, 100);
	int i = 0;
	while (i < 100) {
		int a = unif(gen);
		int b = unif(gen);
		if (a < 0 || b < 0) {
			i++;
			Rational r1(a, b);
			a *= -1;
			a *= -1;
			Rational r2(a, b);
			AssertEqual(r1, r2, "Numerator and/or Denomirator doen't formatted +/-");
		}

	}
}

void DefaultValue() {
	Rational r1;
	Rational r2(0, 1);
	AssertEqual(r1, r2, "Default value != 0/1");
	for (int i = -100; i < 100; i++) {
		if (i != 0) {
			Rational r3(0, i);
			AssertEqual(r3, r2, "Default value != 0/1");
		}
	}
}

int main() {
  TestRunner runner;
  //runner.RunTest(TestDivToZero, "TestDivToZero");
  runner.RunTest(TestToOmen, "TestToOmen");
  runner.RunTest(TestToNOD, "TestToNOD");
  runner.RunTest(DefaultValue, "DefaultValue");
  // добавьте сюда свои тесты
  return 0;
}
