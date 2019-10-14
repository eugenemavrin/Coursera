#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;


// Предварительное объявление шаблонных функций
template <typename F, typename S> pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2);
template <typename key, typename value> map<key, value> operator * (const map<key, value> t1, const map<key, value>t2);
template<typename T> vector<T> operator * (const vector<T>& v1, const vector<T>& v2);
template <typename T> auto Sqr(T x);


// Объявляем шаблонные функции
template <typename F, typename S>
pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2) {
	F f = p1.first * p2.first;
	S s = p1.second * p2.second;
	return make_pair(f, s);
}

template <typename key, typename value>
map<key, value> operator * (const map<key, value> t1, const map<key, value>t2) {
	map<key, value> res;
	for (auto& l : t1) {
		res.insert(make_pair(l.first, l.second * l.second));
	}
	return res;
}

template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {
	vector<T> res;
	for (auto& v : v1) {
		res.push_back(v * v);
	}
	return res;
}
/*
template <typename T>
vector<T> Sqr(vector<T> X) {
	vector<T> res;
	for (auto& x : X) {
		res.push_back(x * x);
	}
	return res;
}

template <typename F, typename S>
map<F, S> Sqr(map<F, S> M) {
	map<F, S> res;
	for (auto& m : M) {
		res.insert(make_pair(m.first, m.second * m.second));
	}
	return res;
}
*/

template <typename T>
auto Sqr(T x) {
	return x * x;
}

int main() {
	cout << Sqr(2.5) << endl;

	// Пример вызова функции
	vector<int> v;
	v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs;
	map_of_pairs = {{4, {2, 2}}, {8, {4, 8}}};

	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
//	map_of_pairs= { { {2, { 3, 4,5,6.8 }}}, { {5, {6, 7,0.01}} } };


/*
 * Compile error: b"/tmp/tmpky74l7o2.cpp:130:15: fatal error:
 * invalid operands to binary expression
 * ('const std::__cxx11::basic_string<char, std::char_traits<char>,
 * std::allocator<char> >' and 'const std::__cxx11::basic_string
 * <char, std::char_traits<char>, std::allocator<char> >')\n
 * res[m.first * m.first] = m.second * m.second;\n
 * ~~~~~~~ ^ ~~~~~~~\n/tmp/tmpky74l7o2.cpp:168:19: note: in instantiation of
 * function template specialization '
 * Sqr<std::__cxx11::basic_string<char, std::char_traits<char>,
 * std::allocator<char> >, int>' requested here\n    auto result = Sqr(test);\n                  ^\n/tmp/tmpky74l7o2.cpp:112:12: note: candidate template ignored: could not match 'pair' against 'basic_string'\npair<F, S> operator* (pair<F, S> p1, pair<F, S> p2) {\n           ^\n1 error generated.\n" (Time used: 0.00/1.00, preprocess time used: 0/None, memory used: 9592832/536870912.)
 *
 *
 *
 *Compile error: b"/tmp/tmpppe0g6ax.cpp:130:32: fatal error:
 *Compile invalid operands to binary expression
 *Compile ('const std::__cxx11::basic_string<char, std::char_traits<char>,
 *Compile  std::allocator<char> >' and 'const std::__cxx11::basic_string
 *Compile  <char, std::char_traits<char>, std::allocator<char> >')\n
 *Compile res.insert(make_pair(m.first * m.first , m.second * m.second);\n                                     ~~~~~~~ ^ ~~~~~~~\n/tmp/tmpppe0g6ax.cpp:183:19: note: in instantiation of function template specialization 'Sqr<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>' requested here\n    auto result = Sqr(test);\n                  ^\n/tmp/tmpppe0g6ax.cpp:112:12: note: candidate template ignored: could not match 'pair' against 'basic_string'\npair<F, S> operator* (pair<F, S> p1, pair<F, S> p2) {\n           ^\n1 error generated.\n" (Time used: 0.00/1.00, preprocess time used: 0/None, memory used: 9605120/536870912.)

 * Compile error: b"/tmp/tmpzg7grnzh.cpp:121:5: fatal error: no viable overloaded '*='\n                x *= x;\n                ~ ^  ~\n/tmp/tmpzg7grnzh.cpp:193:19: note: in instantiation of function template specialization 'Sqr<std::map<int, std::vector<double, std::allocator<double> >, std::less<int>, std::allocator<std::pair<const int, std::vector<double, std::allocator<double> > > > > >' requested here\n    auto result = Sqr(test);\n                  ^\n1 error generated.\n" (Time used: 0.00/1.00, preprocess time used: 0/None, memory used: 9625600/536870912.)

 *
 */
