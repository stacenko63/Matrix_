#include "Matrix.h"
#include <iostream>
#include <windows.h>
using namespace std;
int CheckTypeInt()
{
    char per[100]{ 0 };
    gets_s(per);
    while (strlen(per) == 0)
    {
        printf("An incorrect value was entered. Please try again: ");
        gets_s(per);
    }
    for (int i = 0; i < (int)strlen(per); i++)
    {
        if (per[i] == '-' && i == 0) i++;
        if (per[i] < '0' || per[i] > '9')
        {
            printf("An incorrect value was entered. Please try again: ");
            gets_s(per);
            while (strlen(per) == 0)
            {
                printf("An incorrect value was entered. Please try again: ");
                gets_s(per);
            }
            i = -1;
        }
    }
    int result = atoi(per);
    return result;
}
double CheckTypeDouble()
{
    char per[100]{ 0 };
    gets_s(per);
    int kol_t = 0;
    while (strlen(per) == 0)
    {
        printf("An incorrect value was entered. Please try again: ");
        gets_s(per);
    }
    for (int i = 0; i < (int)strlen(per); i++) 
    {
        if (per[i] == '-' && i == 0) i++;
        if (per[i] == '.')
        {
            kol_t++;
            i++;
        }
        if (per[i] < '0' || per[i] > '9' || kol_t > 1)
        {
            printf("An incorrect value was entered. Please try again: ");
            gets_s(per);
            kol_t = 0;
            while (strlen(per) == 0)
            {
                printf("An incorrect value was entered. Please try again: ");
                gets_s(per);
            }
            i = -1;
        }
    }
    double result = atof(per);
    return result;
}
void CreatingMatrix(int& row, int& col, double& point)
{
    cout << "Enter the number of rows of the matrix: ";
    row = CheckTypeInt();
    while (row <= 0)
    {
        cout << "The number of rows must be a positive number. Repeat the input: ";
        row = CheckTypeInt();
    }
    cout << "Enter the number of columns of the matrix: ";
    col = CheckTypeInt();
    while (col <= 0)
    {
        cout << "The number of columns must be a positive number. Repeat the input: ";
        col = CheckTypeInt();
    }
    cout << "Enter the value that you would like to fill in the matrix with: ";
    point = CheckTypeDouble();
}
void ReadingOrWritingElements(int& row, int& col, Matrix& matrix)
{
    int menu = 1;
    do
    {
        system("cls"); 
        cout << "Enter the row number of the element: ";
        int RowIndex = CheckTypeInt();
        while (RowIndex < 0 || RowIndex >= row)
        {
            cout << "The row number of the element mustn't be out of range of the matrix. Repeat the input: ";
            RowIndex = CheckTypeInt();
        }
        cout << "Enter the column number of the element: ";
        int ColIndex = CheckTypeInt();
        while (ColIndex < 0 || ColIndex >= col)
        {
            cout << "The column number of the element mustn't be out of range of the matrix. Repeat the input: ";
            ColIndex = CheckTypeInt();
        }
        cout << "Matrix[" << RowIndex << "][" << ColIndex << "] = " << matrix(RowIndex, ColIndex) << endl;
        cout << "Do you want to change value of Matrix[" << RowIndex << "][" << ColIndex << "]?" << endl;
        cout << "1 - Yes" << endl;
        cout << "0 - No" << endl;
        cout << "Enter your choice : ";
        menu = CheckTypeInt();
        while (menu < 0 || menu > 1)
        {
            cout << "There is no such item in the menu. Repeat the input: ";
            menu = CheckTypeInt();
        }
        if (menu == 1)
        {
            cout << "Enter a new value for the element: ";
            matrix(RowIndex, ColIndex) = CheckTypeDouble();
        }
        cout << "1 - Repeat" << endl;
        cout << "0 - Back" << endl;
        cout << "Enter your choice : ";
        menu = CheckTypeInt();
        while (menu < 0 || menu > 1)
        {
            cout << "There is no such item in the menu. Repeat the input: ";
            menu = CheckTypeInt();
        }
    } while (menu != 0);
}
void DoingArithmeticOperations(Matrix& matrix1, Matrix& matrix2)
{
    int menu = 1;
    do
    {
        system("cls");
        cout << "1 - Matrices addition" << endl;
        cout << "2 - Matrices subtraction" << endl;
        cout << "3 - Matrices multiplication" << endl;
        cout << "4 - Matrix multiplication by a scalar" << endl;
        cout << "5 - Matrix division by a scalar" << endl;
        cout << "0 - Back" << endl;
        cout << "Enter your choice : ";
        menu = CheckTypeInt();
        while (menu < 0 || menu > 5)
        {
            cout << "There is no such item in the menu. Repeat the input: ";
            menu = CheckTypeInt();
        }
        if (menu == 0) break;
        else if ((menu == 1 || menu == 2) && (matrix1.GetM() != matrix2.GetM() || matrix1.GetN() != matrix2.GetN()))
        {
            cout << "The matrices must be of the same dimension!";
        }
        else if (menu == 1 && (matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetN()))
        {
            cout << matrix1 + matrix2;
        }
        else if (menu == 2 && (matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetN()))
        {
            cout << "1 - Subtract the second matrix from the first one" << endl;
            cout << "2 - Subtract the first matrix from the second one" << endl;
            cout << "Enter your choice : ";
            menu = CheckTypeInt();
            while (menu < 1 || menu > 2)
            {
                cout << "There is no such item in the menu. Repeat the input: ";
                menu = CheckTypeInt();
            }
            if (menu == 1) cout << matrix1 - matrix2;
            else cout << matrix2 - matrix1;
        }
        else if (menu == 3)
        {
            cout << "1 - Multiplying the first matrix by the second" << endl;
            cout << "2 - Multiplying the second matrix by the first" << endl;
            cout << "Enter your choice : ";
            menu = CheckTypeInt();
            while (menu < 1 || menu > 2)
            {
                cout << "There is no such item in the menu. Repeat the input: ";
                menu = CheckTypeInt();
            }
            if ((menu == 1 && (matrix1.GetM() != matrix2.GetN())) || (menu == 2 && (matrix2.GetM() != matrix1.GetN())))
            {
                cout << "The number of columns of the first matrix must be equal to the number of rows of the second matrix!";
            }
            else if (menu == 1) cout << matrix1 * matrix2;
            else if (menu == 2) cout << matrix2 * matrix1;
        }
        else if (menu == 4 || menu == 5)
        {
            cout << "Write a number: ";
            double number = CheckTypeDouble();
            cout << "Select the matrix that you would like to work with: (1 or 2) " << endl;
            cout << "Enter your choice : ";
            int MatrixNumber = CheckTypeInt();
            while (MatrixNumber < 1 || MatrixNumber > 2)
            {
                cout << "There is no such item in the menu. Repeat the input: ";
                MatrixNumber = CheckTypeInt();
            }
            if (menu == 4 && MatrixNumber == 1) cout << matrix1 * number; 
            if (menu == 4 && MatrixNumber == 2) cout << matrix2 * number;
            if (menu == 5 && MatrixNumber == 1) cout << matrix1 / number;
            else if (menu == 5 && MatrixNumber == 2) cout << matrix2 / number;
        }
        cout << "1 - Repeat" << endl;
        cout << "0 - Back" << endl;
        cout << "Enter your choice : ";
        menu = CheckTypeInt();
        while (menu < 0 || menu > 1)
        {
            cout << "There is no such item in the menu. Repeat the input: ";
            menu = CheckTypeInt();
        }
    } while (menu != 0);
}
int main()
{
    try
    {
        setlocale(LC_ALL, "RUS"); 
        int row1 = 0, col1 = 0, row2 = 0, col2 = 0, menu = 1;
        double point = 0;
        cout << "Laboratory work ¹1. Option ¹2" << endl;
        cout << "Creating the first matrix:" << endl;
        CreatingMatrix(row1, col1, point);
        Matrix matrix1(row1, col1, point);
        cout << "Creating the second matrix: " << endl;
        CreatingMatrix(row2, col2, point);
        Matrix matrix2(row2, col2, point);
        do
        {
            system("cls");
            cout << "Laboratory work #1. Option #2" << endl;
            cout << "1 - Reads/writes of the matrix element by the indexes" << endl;
            cout << "2 - Performing arithmetic operations" << endl;
            cout << "3 - Calculating the trace of the matrix" << endl;
            cout << "4 - Matrix comparison" << endl;
            cout << "0 - Exit" << endl;
            cout << "Enter your choice : ";
            menu = CheckTypeInt();
            while (menu < 0 || menu > 4)
            {
                cout << "There is no such item in the menu. Repeat the input: ";
                menu = CheckTypeInt();
            }
            if (menu == 1 || menu == 3)
            {
                int MatrixNumber;
                system("cls");
                cout << "Reads/writes of the matrix element by the indexes (1 or 2)" << endl;
                cout << "Enter your choice : ";
                MatrixNumber = CheckTypeInt();
                while (MatrixNumber < 1 || MatrixNumber > 2)
                {
                    cout << "Only 2 matrices are available. Repeat the input: ";
                    MatrixNumber = CheckTypeInt();
                }
                if (MatrixNumber == 1 && menu == 1) ReadingOrWritingElements(row1, col1, matrix1);
                else if (MatrixNumber == 2 && menu == 1) ReadingOrWritingElements(row2, col2, matrix2);
                else if (MatrixNumber == 1 && menu == 3)
                {
                    cout << "Matrix trace = " << matrix1.MatrixTrace();
                    Sleep(2000);
                }
                else 
                {
                    cout << "Matrix trace = " << matrix2.MatrixTrace();
                    Sleep(2000);
                }
            }
            else if (menu == 2) DoingArithmeticOperations(matrix1, matrix2);
            else if (menu == 4 && matrix1 == matrix2)
            {
                cout << "The matrices are equal";
                Sleep(2000);
            }
            else if (menu == 4 && matrix1 != matrix2)
            {
                cout << "The matrices are not equal";
                Sleep(2000);
            }
        } while (menu != 0);
    }
    catch (const char* exception)
    {
        cout << exception;
    }
    return 0;
}