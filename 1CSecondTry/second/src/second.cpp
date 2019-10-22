#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

ostream& operator<< (ostream &os, vector<int>& v) {
	for (auto &d : v) {
		os << d << " ";
	}
	return os;
}
istream& operator>> (istream &is, vector <int>& v) {
	int buf;
	while (!is.eof()) {
		is >> buf;
		v.push_back(buf);
	}
	return is;
}

int main() {
	//чтение данных
	string s = "1 -2";
	//getline (cin, s);
	if (s == "" ) {
		throw "string is empty!";
	}
	stringstream input(s);
	vector<int> my_array;
	input >> my_array;
	//сдвиг "влево" неотрицательных чисел
	int shift = 0;
	for (int i = 0; i < my_array.size(); ++i) {
		my_array[i - shift] = my_array[i];
		if (my_array[i] < 0) {
			shift++;
		}
	}

	//удалиение лишних чисел из вектора
	my_array.erase(my_array.end() - shift, my_array.end());
	cout << my_array;
	return 0;
}
