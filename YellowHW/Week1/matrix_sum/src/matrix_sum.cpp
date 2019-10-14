#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;
class Matrix {
public:
	Matrix(){
		_num_rows = 0;
		_num_cols = 0;
		vector<vector<int> > s(0, vector<int>(0, 0));
		_matrix = s;

	}
	Matrix(const int& rows, const int& cols) {

		if (rows < 0 || cols < 0) {
			throw out_of_range("");
		}
		else if (rows == 0 || cols == 0) {
			_num_rows = 0;
			_num_cols = 0;
			vector<vector<int> > s(rows, vector<int>(cols, 0));
			_matrix = s;
		}
		else {
			_num_rows = rows;
			_num_cols = cols;
			vector<vector<int> > s(rows, vector<int>(cols, 0));
			_matrix = s;
		}
	}
	void Reset(const int& rows, const int& cols) {
		if (rows < 0 || cols < 0) {
			throw out_of_range("");
		}
		else if (rows == 0 || cols == 0) {
			_num_rows = 0;
			_num_cols = 0;
			vector<vector<int> > s(rows, vector<int>(cols, 0));
			_matrix = s;
		}
		else {
			_num_rows = rows;
			_num_cols = cols;
			vector<vector<int> > s(rows, vector<int>(cols, 0));
			_matrix = s;
		}
	}
	int At(const int& rows, const int& cols) const {
		if (rows < 0 || cols < 0 || rows > _num_rows - 1|| cols > _num_cols - 1) {
			throw out_of_range("");
		}
		else {
			return _matrix[rows][cols];
		}
	}
	int& At(const int& rows, const int& cols)  {
		if (rows < 0 || cols < 0 || rows > _num_rows - 1|| cols > _num_cols - 1) {
			throw out_of_range("");
		}
		else {
			return _matrix[rows][cols];
		}
	}
	int GetNumRows() const{
		return _num_rows;
	}
	int GetNumColumns() const{
		return _num_cols;
	}

private:
	int _num_rows;
	int _num_cols;
	vector<vector<int> > _matrix;

};
istream& operator>>(istream& stream, Matrix& m) {
		int row, col, buf;
		stream >> row >> col;
		m.Reset(row, col);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				stream >> buf;
				m.At(i, j) = buf;
			}
		}
	return stream;
}
ostream& operator<<(ostream& stream, Matrix m) {
	stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for(int i = 0; i < m.GetNumRows(); ++i) {
		for (int j = 0; j < m.GetNumColumns(); j++) {
			stream << m.At(i, j) << " ";
		}
		stream << endl;
	}

	return stream;
}

Matrix operator+(Matrix one, Matrix two) {
		if (one.GetNumRows() == two.GetNumRows() && one.GetNumColumns() ==  two.GetNumColumns())
		{
			throw out_of_range("");
		}
		Matrix res(one.GetNumRows(), one.GetNumColumns());
			for(int i = 0; i < one.GetNumRows(); ++i) {
				for (int j = 0; j < one.GetNumColumns(); j++) {
					res.At(i, j) = one.At(i, j) + two.At(i, j);
				}
			}
	return res;
}
/*
Matrix operator+(const Matrix& one, const Matrix& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    throw invalid_argument("Mismatched number of rows");
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    throw invalid_argument("Mismatched number of columns");
  }

  Matrix result(one.GetNumRows(), one.GetNumColumns());
  for (int row = 0; row < result.GetNumRows(); ++row) {
    for (int column = 0; column < result.GetNumColumns(); ++column) {
      result.At(row, column) = one.At(row, column) + two.At(row, column);
    }
  }

  return result;
}
*/
bool operator==(Matrix one, Matrix two) {
	if (one.GetNumColumns() != two.GetNumColumns() || one.GetNumRows() != two.GetNumRows()) {
		return false;
	}
	else {
		for(int i = 0; i < one.GetNumRows(); ++i) {
			for (int j = 0; j < one.GetNumColumns(); j++) {
				if(one.At(i, j) != two.At(i, j)) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two <<endl;
	return 0;
}


/*
 * Compile error: b'/tmp/submission4jfh95uf/tmp99plake5.cpp:142:3:
 * fatal error: static_assert failed due to requirement
 * \'std::is_convertible_v<belts::detected_t<Member2, const Matrix>, int>\' "
 * Member function int GetNumRows() const not found in Matrix"\n  CHECK_METHODC(Matrix, GetNumRows, int);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\ninclude/detector.h:143:3: note: expanded from macro \'CHECK_METHODC\'\n  __CHECK_METHOD_TYPE(                                                                    \\\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\ninclude/detector.h:105:3: note: expanded from macro \'__CHECK_METHOD_TYPE\'\n  __CHECK_METHOD_TYPE_IMPL(suffix, method, const, class, return_type, message, ##__VA_ARGS__)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\ninclude/detector.h:57:3: note: expanded from macro \'__CHECK_METHOD_TYPE_IMPL\'\n  static_assert(                                                                                        \\\n  ^\n1 error generated.\n'
 *
 */
