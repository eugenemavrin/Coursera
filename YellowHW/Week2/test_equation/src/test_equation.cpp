#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <tuple>

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

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	int res;
	double d;
	d = b * b - 4 * a * c;
	if (a != 0) {
		if (d > 0) {
			//double x1, x2;
	        //x1 = (-b - sqrt(d)) / (2 * a);
	        //x2 = (-b + sqrt(d)) / (2 * a);
			//cout << "2 " << min(x1, x2) << " " << max(x1, x2);
	        res = 2;
		}
		else if (d == 0) {
			res = 1;
			//cout << "1 " << -b / (2 * a);
		}
		else res = 0; //cout << "0";
	    }
	else if (b != 0) {
		res = 1;
		//cout << "1 " << -c / b;
	}
	else res = 0;//cout << "0";
	return res;
}
tuple<double, double, double> GetrandomRoots() {
	double a, b, c;
	mt19937 gen;
	uniform_real_distribution<> unif(-10, 10);
	a = unif(gen);
	b = unif(gen);
	c = unif(gen);
	return tie(a, b, c);
}


void Test100RandomRoots() {
	mt19937 gen;
	uniform_real_distribution<> unif(-100, 100);
	for (auto i = 0; i < 100; ++i) {
			double a = unif(gen);
			double b = unif(gen);
			double c = unif(gen);
			int count = GetDistinctRealRootCount(a, b, c);
			Assert(count >= 0 && count <= 2, "Func returned below 0 or above 2.");
	}
}


void TestOneRoot() {
	//a = 0 or D == 0
	double a, b, c;
	int i = 0;
	while (i < 10) {
		tie(a, b, c) = GetrandomRoots();
		//cout << "==" << endl;
		a = 1;
		b = c + c;
		c = c * c;
		i++;
		stringstream s;
		s << a << "x^2" << " + " << b << "x + " << c << " = 0 must returned 1 root, because D == 0";
		AssertEqual(GetDistinctRealRootCount(a, b, c), 1, s.str());

	}
	i = 0;
	while (i < 10) {
		tie(a, b, c) = GetrandomRoots();
		if (b != 0) {
			i++;
			stringstream s;
			s << b << "x + " << c << " = 0 must returned 1 root, because it's a linear func";
			AssertEqual(GetDistinctRealRootCount(0, b, c), 1, s.str());
		}

	}
}
void TestZeroRoot() {
	double a, b, c;
	int i = 0;
	while (i < 10) {
		tie(a, b, c) = GetrandomRoots();
		a = -a;
		if (b * b - 4 * a * c < 0) {
			i++;
			stringstream s;
			s << a << "x^2" << " + " << b << "x + " << c << " = 0 must returned 0 root, because D < 0";
			AssertEqual(GetDistinctRealRootCount(a, b, c), 0, s.str());
		}
	}
	i = 0;
	while (i < 10) {
		tie(a, b, c) = GetrandomRoots();
		if (c != 0) {
			i++;
			stringstream s;
			s << c << " = 0 must returned 0 root, because c is const";
			AssertEqual(GetDistinctRealRootCount(0, 0, c), 0, s.str());
		}
	}
	stringstream s;
	s << 0 << "x^2" << " + " << 1 << "x + " << 1 << " = 0 must returned 0 root, because D < 0";
	AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, s.str());
}

void TestTwoRoots() {
	double a, b, c;
	tie(a, b, c) = GetrandomRoots();
	int i = 0;
	while (i < 10) {
		if (b * b - 4 * a * c > 0) {
			i++;
			stringstream s;
			s << "x^2" << a << " + x" << b << " + " << c << " = 0 must returned 2 roots, because D > 0";
			AssertEqual(GetDistinctRealRootCount(a, b, c), 2, s.str());
		}
	}
}


int main() {
  TestRunner runner;
  runner.RunTest(Test100RandomRoots, "Test100RandomRoots");
  runner.RunTest(TestTwoRoots, "TestTwoRoots");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestZeroRoot, "TestZeroRoot");

  // добавьте сюда свои тесты
  return 0;
}
