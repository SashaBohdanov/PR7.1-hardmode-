#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void CalcSum(int** a, const int rowCount, const int colCount, int& S, int i, int j);
void Zero(int** a, const int rowCount, const int colCount, int i, int j);
void CalcN(int** a, const int rowCount, const int colCount, int& k, int i, int j);

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int Low = -42;
    int High = 51;
    int rowCount = 7;
    int colCount = 6;
    int** T = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High, 0, 0);
    Print(T, rowCount, colCount, 0, 0);
    Sort(T, rowCount, colCount, 0, 0);
    Print(T, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    CalcSum(T, rowCount, colCount, S, 0, 0);
    CalcN(T, rowCount, colCount, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Zero(T, rowCount, colCount, 0, 0);
    Print(T, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++) {
        delete[] T[i];
    }

    delete[] T;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << a[i][j];
            if (j < colCount - 1) {
                Print(a, rowCount, colCount, i, j + 1);
            }
            else {
                cout << endl;
                Print(a, rowCount, colCount, i + 1, 0);
            }
        }
        else {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
    }
    else {
        cout << endl << endl;
    }
}

void Change(int** a, const int row1, const int row2, const int colCount, int j) {
    if (j < colCount) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
        Change(a, row1, row2, colCount, j + 1);
    }
}

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if (a[i1][0] > a[i1 + 1][0] ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] > a[i1 + 1][2])) {
                Change(a, i1, i1 + 1, colCount, 0);
            }
            Sort(a, rowCount, colCount, i0, i1 + 1);
        }
        else {
            Sort(a, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void CalcSum(int** a, const int rowCount, const int colCount, int& S, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (!(a[i][j] > 0 && a[i][j] % 5 == 0)) {
                S += a[i][j];
            }
            CalcSum(a, rowCount, colCount, S, i, j + 1);
        }
        else {
            CalcSum(a, rowCount, colCount, S, i + 1, 0);
        }
    }
}

void Zero(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (!(a[i][j] > 0 && a[i][j] % 5 == 0)) {
                a[i][j] = 0;
            }
            Zero(a, rowCount, colCount, i, j + 1);
        }
        else {
            Zero(a, rowCount, colCount, i + 1, 0);
        }
    }
}

void CalcN(int** a, const int rowCount, const int colCount, int& k, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (!(a[i][j] > 0 && a[i][j] % 5 == 0)) {
                k++;
            }
            CalcN(a, rowCount, colCount, k, i, j + 1);
        }
        else {
            CalcN(a, rowCount, colCount, k, i + 1, 0);
        }
    }
}


