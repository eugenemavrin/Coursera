#include <iostream>
#include <string>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		_s = "";
	}
	ReversibleString(const string& s) {
		_s = s;
	}
	void Reverse() {
		string temp = "";
		for (int i = _s.size() - 1; i >= 0; --i) {
			temp += _s[i];
		}
		_s = temp;
	}
	string ToString() const{
		return _s;
	}
private:
	string _s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
