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

bool IsPalindrom(const string& str) {
	string reverse;
	for (int i = str.length() - 1; i >=0; i--) {
		reverse += str[i];
	}
	return str == reverse;
}
void Test1() {
	Assert(IsPalindrom(""), "empty string is Paindrome");
	Assert(IsPalindrom("a"), "letter a is Paindrome");
	Assert(IsPalindrom("aa"), "aa is Paindrome");
	Assert(IsPalindrom(" aa "), "_aa_ is Paindrome");
	Assert(IsPalindrom("ava"), "ava is Paindrome");
	Assert(IsPalindrom("abba"), "abba is Paindrome");
	Assert(IsPalindrom("kayak"), "kayak is Paindrome");
	Assert(IsPalindrom("asd =+l+= dsa"), "asd =+l+= dsa is Paindrome");
	AssertEqual(IsPalindrom("Aa"), false, "Aa isn't a Palindrome");
	AssertEqual(IsPalindrom("ab"), false, "ab isn't a Palindrome");
	AssertEqual(IsPalindrom("aa "), false, "aa_ isn't a Palindrome");
	AssertEqual(IsPalindrom(" aa"), false, "_aa isn't a Palindrome");
	AssertEqual(IsPalindrom(" aa"), false, "_aa isn't a Palindrome");
	AssertEqual(IsPalindrom(" aaaa"), false, "_aa isn't a Palindrome");
	AssertEqual(IsPalindrom("aabba"), false, "aabba isn't a Palindrome");
	AssertEqual(IsPalindrom("baa aa "), false, "baa aa  isn't a Palindrome");
	AssertEqual(IsPalindrom(" aa aab"), false, " aa aab isn't a Palindrome");
	AssertEqual(IsPalindrom(" aa aa"), false, " aa aa isn't a Palindrome");
	AssertEqual(IsPalindrom("akayakv"), false, "akayakv isn't a Palindrome");
	AssertEqual(IsPalindrom("akay akv"), false, "akay akv isn't a Palindrome");
	AssertEqual(IsPalindrom("kay ak"), false, "kay ak isn't a Palindrome");
	AssertEqual(IsPalindrom("aka ak"), false, "aka ak isn't a Palindrome");
	AssertEqual(IsPalindrom("asdlabs"), false, "asdlabs isn't a Palindrome");
}
void Test2() {
	string s8 = "aaaaaaaa";
	string s9 = "aaaaaaaaa";
	string msg;
	for (auto &c: s8) {
		c = ' ';
		msg = s8 + " isn't a Palindrome";
		AssertEqual(IsPalindrom(s8), false, msg);
		c = 'a';
	}
	int count = 0;
	for (auto &c: s9) {
		c = ' ';
		count++;
		msg = s9 + " isn't a Palindrome";
		if (count * 2 - 1 != s9.length())
			AssertEqual(IsPalindrom(s9), false, msg);
		c = 'a';
	}
	Assert(IsPalindrom(""), "empty string is Paindrome");
	Assert(IsPalindrom("a"), "letter a is Paindrome");
	Assert(IsPalindrom("aa"), "aa is Paindrome");
	Assert(IsPalindrom(" aa "), "_aa_ is Paindrome");

}


int main() {
  TestRunner runner;
  runner.RunTest(Test1, "Test1");
  runner.RunTest(Test2, "Test2");
  // добавьте сюда свои тесты
  return 0;
}
