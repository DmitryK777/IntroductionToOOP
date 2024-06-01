//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Matrix;
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);

Matrix operator/(const Matrix& left, const Matrix& right);

class Matrix
{
private:
	int rows;
	int cols;
	double** matrix;

public:
	// Access Methods:
	int get_rows()const { return this->rows; }
	int get_cols()const { return this->cols; }
	double** get_matrix()const { return this->matrix; }
	double get_elem(int i, int j)const { return this->get_matrix()[i][j]; }
	

	void set_rows(int rows) { this->rows = rows; }
	void set_cols(int cols) { this->cols = cols; }
	void set_elem(int i, int j, double value) { this->get_matrix()[i][j] = value; }
	void set_matrix()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				cout << "Значение элемента " << i << "." << j << ": ";
				cin >> this->matrix[i][j];
			}
			cout << endl;
		}
	}

	// Constructors:
	Matrix(int rows = 1, int cols = 1)
	{
		this->rows = rows;
		this->cols = cols;
		this->matrix = new double* [rows];
		for (int i = 0; i < rows; i++) this->matrix[i] = new double[cols] {};

		cout << "Constructor:\t" << this << endl;
	}

	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new double* [other.rows];
		for (int i = 0; i < other.rows; i++) this->matrix[i] = new double[other.cols] {};
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.cols; j++)
			{
				this->set_elem(i, j, other.get_elem(i, j));
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}

	Matrix(Matrix&& other)
	{
		// Shallow Copy
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;
		//MoveConstructor работает противоположно CopyConstructor

		for (int i = 0; i < other.get_rows(); i++) other.get_matrix()[i] = nullptr;
		other.matrix = nullptr;
		other.rows = 0;
		other.cols = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	

	~Matrix()
	{
		for (int i = 0; i < rows; i++) delete[] matrix[i];
		delete[] matrix;
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators:
	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < rows; i++) delete[] this->matrix[i];
		delete[] this->matrix;
		
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new double* [other.rows];
		for (int i = 0; i < other.rows; i++) this->matrix[i] = new double[other.cols] {};
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.cols; j++)
			{
				this->set_elem(i, j, other.get_elem(i, j));
			}
		}
		cout << "AssignmentConstructor:\t" << this << endl;
		return *this;
	}
	
	/*
	Matrix& operator=(Matrix&& other)
	{
		for (int i = 0; i < rows; i++) delete[] this->matrix[i];
		delete[] this->matrix;
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;

		for (int i = 0; i < other.get_rows(); i++) other.get_matrix()[i] = nullptr;
		other.matrix = nullptr;
		other.rows = 0;
		other.cols = 0;

		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}
	*/

	Matrix& operator+=(const Matrix& other)
	{
		return *this = *this + other;
	}

	Matrix& operator-=(const Matrix& other)
	{
		return *this = *this - other;
	}

	Matrix& operator*=(const Matrix& other)
	{
		Matrix result;
		result = *this * other;

		for (int i = 0; i < this->get_rows(); i++) delete[] this->matrix[i];
		delete[] this->matrix;

		this->rows = result.get_rows();
		this->cols = result.get_cols();
		this->matrix = new double* [this->rows];
		for (int i = 0; i < this->rows; i++) this->matrix[i] = new double[this->cols];
		
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->set_elem(i, j, result.get_elem(i, j));
			}
		}

		return *this;
	}

	Matrix& operator/=(const Matrix& other)
	{
		Matrix result;
		result = *this / other;

		for (int i = 0; i < this->get_rows(); i++) delete[] this->matrix[i];
		delete[] this->matrix;

		this->rows = result.get_rows();
		this->cols = result.get_cols();
		this->matrix = new double* [this->rows];
		for (int i = 0; i < this->rows; i++) this->matrix[i] = new double[this->cols];

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->set_elem(i, j, result.get_elem(i, j));
			}
		}

		return *this;
	}
	
	// Methods:
	void print()
	{
		cout << "Значения элементов матрицы:" << endl;
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				cout << this->matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

Matrix operator+(const Matrix& left, const Matrix& right)
{
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		int rows = left.get_rows();
		int cols = left.get_cols();
		Matrix temp(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				temp.set_elem(i, j, (left.get_elem(i, j) + right.get_elem(i, j)));
			}
		}
		return temp;
	}
	else
	{
		cout << "Так дело не пойдёт!!!" << endl;
		return left;
	}
}

Matrix operator-(const Matrix& left, const Matrix& right)
{
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		int rows = left.get_rows();
		int cols = left.get_cols();
		Matrix temp(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				temp.set_elem(i, j, (left.get_elem(i, j) - right.get_elem(i, j)));
			}
		}
		return temp;
	}
	else
	{
		cout << "Так дело не пойдёт!!!" << endl;
		return left;
	}
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() == right.get_rows())
	{
		int rows = right.get_rows();
		int cols = left.get_cols();
		Matrix temp(rows, cols);

		for (int i = 0; i < left.get_rows(); i++)
		{
			for (int j = 0; j < right.get_cols(); j++)
			{
				temp.set_elem(i, j, 0);
				for (int k = 0; k < left.get_cols(); k++)
				{
					temp.set_elem(i, j, (temp.get_elem(i, j) + (left.get_elem(i, k) * right.get_elem(k, j))));
				}
			}
		}
		
		return temp;
	}
	else
	{
		cout << "Так дело не пойдёт!!!" << endl;
	}
}

Matrix inverse(const Matrix& matr)
{
	if (matr.get_rows() == matr.get_cols())
	{
		int size = matr.get_rows();

		Matrix clone(size, size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) clone.set_elem(i, j, matr.get_elem(i, j));
				
		Matrix buffer(size, size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j) buffer.set_elem(i, j, 1);
				else buffer.set_elem(i, j, 0);
			}
		}

		int temp = 0;
		for (int k = 0; k < size; k++)
		{
			temp = clone.get_elem(k, k);
			for (int j = 0; j < size; j++)
			{
				clone.set_elem(k, j, clone.get_elem(k, j)/temp);
				buffer.set_elem(k, j, buffer.get_elem(k, j)/temp);
			}
			for (int i = k + 1; i < size; i++)
			{
				temp = clone.get_elem(i, k);
				for (int j = 0; j < size; j++)
				{
					clone.set_elem(i, j, (clone.get_elem(i, j) - clone.get_elem(k, j) * temp));
					buffer.set_elem(i, j, (buffer.get_elem(i, j) - buffer.get_elem(k, j) * temp));
				}
			}
		}

		for (int k = size - 1; k > 0; k--)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				temp = clone.get_elem(i, k);
				for (int j = 0; j < size; j++)
				{
					clone.set_elem(i, j, (clone.get_elem(i, j) - clone.get_elem(k, j) * temp));
					buffer.set_elem(i, j, (buffer.get_elem(i, j) - buffer.get_elem(k, j) * temp));
				}
			}
		}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) clone.set_elem(i, j, buffer.get_elem(i, j));

		return clone;
	}
	else
	{
		cout << "Ни чего не получится!!!" << endl;
	}
}

Matrix operator/(const Matrix& left, const Matrix& right)
{
	return left * inverse(right);
}


bool operator==(Matrix left, Matrix right)
{
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		for (int i = 0; i < left.get_rows(); i++)
		{
			for (int j = 0; j < left.get_cols(); j++)
			{
				if (left.get_elem(i, j) != right.get_elem(i, j)) return false;
			}
		}
		return true;
	}
	else return false;
}

bool operator!=(const Matrix& left, const Matrix& right)
{
	return !(left == right);
}


void main()
{
	setlocale(LC_ALL, "");

	Matrix A(2, 2);
	A.set_matrix();
	A.print();

	Matrix B(2, 2);
	B.set_matrix();
	B.print();

	//Matrix C;
	//C = A * B;
	//C.print();

	//Matrix C;
	//C= A / B;
	//C.print();

	A /= B;
	A.print();
} 