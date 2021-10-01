#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	int n, m;
	double** arr;
public:
	int GetN() const 
	{
		return n;
	}
	int GetM() const 
	{
		return m;
	}
	Matrix(const int n = 3, const int m = 3, const double value = 0)
	{
		if (n > 0 && m > 0)
		{
			this->n = n;
			this->m = m;
			arr = new double* [n];
			for (int i = 0; i < n; i++) {
				arr[i] = new double[m];
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					arr[i][j] = value;
				}
			}
		}
		else throw "Incorrect matrix sizes are specified!";
	}
	Matrix(const Matrix& other)
	{
		this->n = other.n;
		this->m = other.m;
		arr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new double[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = other.arr[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	double MatrixTrace() const 
	{
		double trace = 0;
		for (int i = 0, j = 0; i < n && j < m; i++, j++)
		{
			trace += arr[i][j];
		}
		return trace;
	}
	Matrix operator*(const double number)
	{
		Matrix temp(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.arr[i][j] = arr[i][j] * number;
			}
		}
		return temp;
	}
	Matrix operator/(const double number)
	{
		if (number != 0)
		{
			Matrix temp(n, m);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp.arr[i][j] = arr[i][j] / number;
				}
			}
			return temp;
		}
		else throw "Division by zero";
	}
	Matrix operator*(const Matrix& other)
	{
		if (this->m == other.n)
		{
			Matrix temp(this->n, other.m);
			for (int i = 0; i < this->n; i++)
			{
				for (int k = 0; k < other.m; k++)
				{
					for (int j = 0; j < this->m; j++)
					{
						temp.arr[i][k] += this->arr[i][j] * other.arr[j][k];
					}
				}
			}
			return temp;
		}
		throw "The number of columns of the first matrix must be equal to the number of rows of the second matrix!";
	}
	bool operator==(const Matrix& other)
	{
		if (this->n != other.n || this->m != other.m) return false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (this->arr[i][j] != other.arr[i][j]) return false;
			}
		}
		return true;
	}
	bool operator!=(const Matrix& other)
	{
		return (!(*this == other));
	}
	Matrix operator+(const Matrix& other)
	{
		if (other.n == this->n && other.m == this->m)
		{
			Matrix temp(other.n, other.m);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!";
	}
	Matrix operator-(const Matrix& other)
	{
		if (other.n == this->n && other.m == this->m)
		{
			Matrix temp(other.n, other.m);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp.arr[i][j] = this->arr[i][j] - other.arr[i][j];
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!";
	}
	double& operator()(const int row, const int col)
	{
		if (row >= 0 && col >= 0 && row < n && col < m)
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}
	double operator()(const int row, const int col) const 
	{
		if (row >= 0 && col >= 0 && row < n && col < m)
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}

};

ostream& operator <<(ostream& out, const Matrix& matrix)
{
	for (int i = 0; i < matrix.GetN(); i++)
	{
		for (int j = 0; j < matrix.GetM(); j++)
		{
			out << matrix(i, j) << " ";
		}
		out << endl;
	}
	return out;

}




