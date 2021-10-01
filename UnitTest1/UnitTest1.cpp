#include "pch.h"
#include "CppUnitTest.h"
#include "..\Matrix\Matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		public:
		TEST_METHOD(ConstructorTest)
		{
			Matrix matrix(2, 3, 5);
			Assert::IsTrue((matrix.GetN() == 2 && matrix.GetM() == 3 && matrix(0,0) == 5 && matrix(0,1) == 5 && matrix(1,0) == 5 && matrix(1,1) == 5), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			Matrix matrix7;
			Assert::IsTrue((matrix7.GetN() == 3 && matrix7.GetM() == 3 && matrix7(0, 0) == 0 && matrix7(0, 1) == 0 && matrix7(0, 2) == 0 && matrix7(1, 0) == 0 && matrix7(1, 1) == 0 && matrix7(1, 2) == 0 && matrix7(2, 0) == 0 && matrix7(2, 1) == 0 && matrix7(2, 2) == 0), L"Fail in constructor: Matrix matrix()");
			bool check = false;
			try
			{
				Matrix matrix1(-1, 9, 8);
			}
			catch (const char* ex) 
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix matrix2(4, -1, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix matrix3(-1, -1, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix matrix4(0, 7, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix matrix5(4, 0, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix matrix6(0, 0, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
		}

		TEST_METHOD(CopyConstructorTest)
		{
			Matrix matrix1(2, 2, 4);
			Matrix matrix2(matrix1);
			Assert::IsTrue(matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetM()), L"Fail: The matrices must be of the same dimension!";
			Assert::IsTrue(matrix1(0, 0) == matrix2(0, 0) && matrix1(0, 1) == matrix2(0, 1) && matrix1(1, 0) == matrix2(1, 0) && matrix1(1, 1) == matrix2(1, 1)), L"Fail: The matrices must have the same values";
			matrix2(0, 0) = 1;
			Assert::IsTrue(matrix1(0, 0) != matrix2(0, 0)), L"Fail: The matrices must have different references";
		}

		TEST_METHOD(MatrixTraceTest)
		{
			Matrix matrix1(3, 3, 4);
			Assert::IsTrue(matrix1.MatrixTrace() == 12), L"Fail: Incorrent Answer: matrix(3,3,4)";
			Matrix matrix2(5, 5, 7);
			Assert::IsTrue(matrix2.MatrixTrace() == 35), L"Fail: Incorrent Answer: matrix(5,5,7)";
			Matrix matrix3(2, 3, 5);
			Assert::IsTrue(matrix3.MatrixTrace() == 10), L"Fail: Incorrent Answer: matrix(2,3,5)";
			Matrix matrix4(3, 2, 7);
			Assert::IsTrue(matrix4.MatrixTrace() == 14), L"Fail: Incorrent Answer: matrix(3,2,7)";
		}

		TEST_METHOD(MatricesMultiplicationTest)
		{
			Matrix matrix1(3, 3, 3), matrix2(3, 3, 9);
			Matrix matrix3 = matrix1 * matrix2;
			Assert::IsTrue(matrix3.GetN() == 3 && matrix3.GetM() == 3 && matrix3(0, 0) == 81 && matrix3(0, 1) == 81 && matrix3(0, 2) == 81 && matrix3(1, 0) == 81 && matrix3(1, 1) == 81 && matrix3(1, 2) == 81 && matrix3(2, 0) == 81 && matrix3(2, 1) == 81 && matrix3(2, 2) == 81), L"Fail: Incorrect Answer: matrix(3,3,3) * matrix(3,3,9)";
			Matrix matrix4(2, 2, 2), matrix5(2, 2, 3);
			Matrix matrix6 = matrix4 * matrix5;
			Assert::IsTrue(matrix6.GetN() == 2 && matrix6.GetM() == 2 && matrix6(0, 0) == 12 && matrix6(0, 1) == 12 && matrix6(1, 0) == 12 && matrix6(1, 1) == 12), L"Fail: Incorrect Answer : matrix(2, 2, 2) * matrix(2, 2, 3)";
			Matrix matrix11(3, 3, 9), matrix12(3, 3, 3);
			matrix11(1, 1) = 5;
			matrix11(2, 2) = 6;
			matrix12(1, 0) = 1;
			matrix12(2, 2) = 2;
			Matrix matrix13 = matrix11 * matrix12;
			Assert::IsTrue(matrix13.GetN() == 3 && matrix13.GetM() == 3 && matrix13(0, 0) == 63 && matrix13(0, 1) == 81 && matrix13(0, 2) == 72 && matrix13(1, 0) == 59 && matrix13(1, 1) == 69 && matrix13(1, 2) == 60 && matrix13(2, 0) == 54 && matrix13(2, 1) == 72 && matrix13(2, 2) == 66), L"Fail: Incorrect Answer: matrix(3,3,3) * matrix(3,3,9)";
			Matrix matrix14(2, 2, 3), matrix15(2, 2, 2);
			matrix14(0, 0) = 4;
			matrix14(0, 1) = 7;
			matrix14(1, 0) = 9;
			matrix15(0, 0) = 1;
			matrix15(0, 1) = 3;
			matrix15(1, 0) = 9;
			Matrix matrix16 = matrix14 * matrix15;
			Assert::IsTrue(matrix16.GetN() == 2 && matrix16.GetM() == 2 && matrix16(0, 0) == 67 && matrix16(0, 1) == 26 && matrix16(1, 0) == 36 && matrix16(1, 1) == 33), L"Fail: Incorrect Answer : matrix(2, 2, 2) * matrix(2, 2, 3)";
			bool check = false;
			try
			{
				Matrix matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix matrix21 = matrix19 * matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail Matrices Multiplication (Unhandled exception: The number of columns of the first matrix must be equal to the number of rows of the second matrix!): matrix1(5,5,8)*matrix(4,5,2)";
			check = false;
		}

		TEST_METHOD(EqualityOperatorTest)
		{
			Matrix matrix1(2, 2, 2), matrix2(2, 2, 2);
			Assert::IsTrue((matrix1 == matrix2) == true);
			Assert::IsTrue((matrix2 == matrix1) == true);
			Matrix matrix3(2, 3, 2), matrix4(2, 2, 2);
			Assert::IsTrue((matrix3 == matrix4) == false);
			Assert::IsTrue((matrix4 == matrix3) == false);
			Matrix matrix5(3, 2, 2);
			Assert::IsTrue((matrix3 == matrix5) == false);
			Assert::IsTrue((matrix5 == matrix3) == false);
			Matrix matrix6(4, 4, 2);
			Assert::IsTrue((matrix6 == matrix4) == false);
			Assert::IsTrue((matrix4 == matrix6) == false);
			Matrix matrix7(2, 2, 3);
			Assert::IsTrue((matrix1 == matrix7) == false);
			Assert::IsTrue((matrix7 == matrix1) == false);
		}

		TEST_METHOD(NotEqualityOperatorTest)
		{
			Matrix matrix1(2, 2, 2), matrix2(2, 2, 2);
			Assert::IsTrue((matrix1 != matrix2) == false);
			Assert::IsTrue((matrix2 != matrix1) == false);
			Matrix matrix3(2, 3, 2), matrix4(2, 2, 2);
			Assert::IsTrue((matrix3 != matrix4) == true);
			Assert::IsTrue((matrix4 != matrix3) == true);
			Matrix matrix5(3, 2, 2);
			Assert::IsTrue((matrix3 != matrix5) == true);
			Assert::IsTrue((matrix5 != matrix3) == true);
			Matrix matrix6(4, 4, 2);
			Assert::IsTrue((matrix6 != matrix4) == true);
			Assert::IsTrue((matrix4 != matrix6) == true);
			Matrix matrix7(2, 2, 3);
			Assert::IsTrue((matrix1 != matrix7) == true);
			Assert::IsTrue((matrix7 != matrix1) == true);
		}

		TEST_METHOD(AdditionOperatorTest)
		{
			Matrix matrix1(3, 3, 4), matrix2(3, 3, 2);
			Matrix matrix3 = matrix1 + matrix2;
			Assert::IsTrue(matrix3.GetM() == 3 && matrix3.GetN() == 3 && matrix3(0, 0) == 6 && matrix3(0, 1) == 6 && matrix3(0, 2) == 6 && matrix3(1, 0) == 6 && matrix3(1, 1) == 6 && matrix3(1, 2) == 6 && matrix3(2, 0) == 6 && matrix3(2, 1) == 6 && matrix3(2, 2) == 6);
			Matrix matrix4(2, 2, 3), matrix5(2, 2, 4);
			Matrix matrix6 = matrix4 + matrix5;
			Assert::IsTrue(matrix6.GetM() == 2 && matrix6.GetN() == 2 && matrix6(0, 0) == 7 && matrix6(0, 1) == 7 && matrix6(1, 0) == 7 && matrix6(1, 1) == 7);
			bool check = false;
			try
			{
				Matrix matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix matrix19(4, 5, 8), matrix20(5, 4, 2);
				Matrix matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix matrix19(4, 4, 8), matrix20(5, 5, 2);
				Matrix matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(SubtractionOperatorTest)
		{
			Matrix matrix1(3, 3, 4), matrix2(3, 3, 2);
			Matrix matrix3 = matrix1 - matrix2;
			Assert::IsTrue(matrix3.GetM() == 3 && matrix3.GetN() == 3 && matrix3(0, 0) == 2 && matrix3(0, 1) == 2 && matrix3(0, 2) == 2 && matrix3(1, 0) == 2 && matrix3(1, 1) == 2 && matrix3(1, 2) == 2 && matrix3(2, 0) == 2 && matrix3(2, 1) == 2 && matrix3(2, 2) == 2);
			Matrix matrix4(2, 2, 3), matrix5(2, 2, 4);
			Matrix matrix6 = matrix4 - matrix5;
			Assert::IsTrue(matrix6.GetM() == 2 && matrix6.GetN() == 2 && matrix6(0, 0) == -1 && matrix6(0, 1) == -1 && matrix6(1, 0) == -1 && matrix6(1, 1) == -1);
			bool check = false;
			try
			{
				Matrix matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix matrix19(4, 5, 8), matrix20(5, 4, 2);
				Matrix matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix matrix19(4, 4, 8), matrix20(5, 5, 2);
				Matrix matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(MultiplicationByAScalarTest)
		{
			Matrix matrix1(3,3,4);
			Matrix matrix2 = matrix1 * 9;
			Assert::IsTrue(matrix2.GetM() == 3 && matrix2.GetN() == 3 && matrix2(0, 0) == 36 && matrix2(0, 1) == 36 && matrix2(0, 2) == 36 && matrix2(1, 0) == 36 && matrix2(1, 1) == 36 && matrix2(1, 2) == 36 && matrix2(2, 0) == 36 && matrix2(2, 1) == 36 && matrix2(2, 2) == 36);
			Matrix matrix4(3, 3, 5);
			Matrix matrix5 = matrix4 * 0;
			Assert::IsTrue(matrix5.GetM() == 3 && matrix5.GetN() == 3 && matrix5(0, 0) == 0 && matrix5(0, 1) == 0 && matrix5(0, 2) == 0 && matrix5(1, 0) == 0 && matrix5(1, 1) == 0 && matrix5(1, 2) == 0 && matrix5(2, 0) == 0 && matrix5(2, 1) == 0 && matrix5(2, 2) == 0);
		}

		TEST_METHOD(DivisionByAScalarTest)
		{
			Matrix matrix1(3, 3, 9);
			Matrix matrix2 = matrix1 / 9;
			Assert::IsTrue(matrix2.GetM() == 3 && matrix2.GetN() == 3 && matrix2(0, 0) == 1 && matrix2(0, 1) == 1 && matrix2(0, 2) == 1 && matrix2(1, 0) == 1 && matrix2(1, 1) == 1 && matrix2(1, 2) == 1 && matrix2(2, 0) == 1 && matrix2(2, 1) == 1 && matrix2(2, 2) == 1);
			Matrix matrix4(3, 3, 5);
			Matrix matrix5 = matrix4 / -2;
			Assert::IsTrue(matrix5.GetM() == 3 && matrix5.GetN() == 3 && matrix5(0, 0) == -2.5 && matrix5(0, 1) == -2.5 && matrix5(0, 2) == -2.5 && matrix5(1, 0) == -2.5 && matrix5(1, 1) == -2.5 && matrix5(1, 2) == -2.5 && matrix5(2, 0) == -2.5 && matrix5(2, 1) == -2.5 && matrix5(2, 2) == -2.5);
			bool check = false;
			try
			{
				Matrix matrix6 = matrix5 / 0;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(ReadAndWriteValueTest)
		{
			Matrix matrix1(3, 3, 1);
			bool check = false;
			try
			{
				matrix1(3,2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2,3);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(3, 3);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2, 4);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(4, 2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(4, 4);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2, -1);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(-1, 2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(-1, -1);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			matrix1(0, 0) = 3;
			Assert::IsTrue(matrix1(0, 0) == 3);
			matrix1(0, 1) = 7;
			Assert::IsTrue(matrix1(0, 1) == 7);
		}
	};
}
