#define NNMBER 3
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <map>
using namespace std;

class Solution {
public:
	Solution() {}

	Solution(const string& p, const string& b) {
		_words = Parse(p);
		_banned = Parse(b);
	}
	vector<string> ResVector();

private:
	vector <string> _banned;
	vector <string> _words;
	vector <string> Parse(const string& s);
	vector <string> Eraser();

};
vector<string> Solution::ResVector() {
	map<int, vector<string>> vec2map;
	vector<string> res;
	vector<string> erased = Eraser();
	for (const auto& s : erased) {
		vec2map[count(erased.begin(), erased.end(), s)].push_back(s);
	}
	int counter = 0;
	for (auto& l : vec2map) {
		for (auto& s : l.second) {
			if (counter < NNMBER) {
				res.push_back(s);
				counter++;
			}
			else return res;
		}
	}
	return res;
}

vector <string> Solution::Parse(const string& s) {
	vector <string> v;
	string temp;
	for (char c : s) {
		c = tolower(c);
		if(isalpha(c)) {
			temp += c;
		}
		else {
			if (temp.size() > 0) {
				v.push_back(temp);
			}
			temp = "";
		}
	}
	if (temp.size() > 0) {
		v.push_back(temp);
	}
	return v;
}

vector <string> Solution::Eraser() {
	vector<string> v = _words;
	for (int i = 0; i < v.size(); ++i) {
		if(count(_banned.begin(), _banned.end(), v[i]) > 0) {
			v.erase(v.begin() + i);
			i--;
		}
	}
	return v;
}

void PrintVector(vector<string> v) {
	for (string& s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	string paragraph = "bob hit hit ball Bob hit a a ball, the flew hit ball flew";
	//getline(cin, paragraph);
	string banned = "hit ball";

	//getline(cin, banned);
	Solution data(paragraph, banned);

	//сортировка по порядку и по количеству вхождений
	PrintVector(data.ResVector());

	return 0;
}
