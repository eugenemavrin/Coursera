#include <iostream>
#include <vector>
using namespace std;

class FunctionPart {
public:
	FunctionPart(const char& c, const double x) {
		_operand = c;
		_x = x;
	}
	double Apply(double s) const {
		if (_operand == '+') {
			return s + _x;
		}
		else if (_operand == '*') {
			return s *= _x;
		}
		else if (_operand == '/') {
			return s /= _x;
		}
		else if (_operand == '-') {
			return s - _x;
		}
		else return -1;
	}
	void Invert() {
		if (_operand == '+') {
			_operand = '-';
		}
		else if (_operand == '-') {
			_operand = '+';
		}
		else if (_operand == '/') {
			_operand = '*';
		}
		else if (_operand == '*') {
			_operand = '/';
		}
		else _operand = '\n';
	}
private:
	char _operand;
	double _x;
};

class Function {
public:
	Function() {};
	void AddPart (const char& c, const double x) {
		_operations.push_back(FunctionPart(c, x));
	}
	double Apply(double y) const{
		for (auto& o : _operations) {
			y = o.Apply(y);
		}
		return y;
	}
	void Invert() {
		for (auto & o : _operations) {
			o.Invert();
		}
		reverse(_operations.begin(), _operations.end());
	}

private:
	vector<FunctionPart> _operations;
};

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}


