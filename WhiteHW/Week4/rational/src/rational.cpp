#include <iostream>
#include <sstream>
#include <string>


using namespace std;

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

int main() {
	int r1n, r1d, r2n, r2d;
	char sign;
	cin >> r1n;
	cin.ignore(1);
	cin >> r1d >> sign >> r2n;
	cin.ignore(1);
	cin >> r2d;
	Rational r1;
	Rational r2;
	try {
		r1 = Rational(r1n, r1d);
		r2 = Rational(r2n, r2d);
	}
	catch (invalid_argument &ex) {
		cout << ex.what();
		return 0;
	}
	Rational res;
	switch (sign) {
		case '+':
			res = r1 + r2;
			break;
		case '-':
			res = r1 - r2;
			break;
		case '*':
			res = r1 * r2;
			break;
		case '/':
			try {
				res = r1 / r2;
			} catch (domain_error &ex) {
				cout << ex.what();
				return 0;
			}
			break;
		default:
			break;
	}
	cout << res;
    return 0;
}
