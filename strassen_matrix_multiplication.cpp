#include <iostream>
#include <conio.h>

using namespace std;

int **Matrix(int n)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

void insert(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
}

void display(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int **add(int **A, int **B, int n)
{
    int **C = Matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int **subtract(int **A, int **B, int n)
{
    int **C = Matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

int **Strassen(int **A, int **B, int n)
{
    if (n == 1)
    {
        int **C = Matrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int **C = Matrix(n);
    int k = n / 2;
    int **A11 = Matrix(k);
    int **A12 = Matrix(k);
    int **A21 = Matrix(k);

    int **A22 = Matrix(k);
    int **B11 = Matrix(k);
    int **B12 = Matrix(k);
    int **B21 = Matrix(k);
    int **B22 = Matrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    int **P1 = Strassen(A11, subtract(B12, B22, k), k);
    int **P2 = Strassen(add(A11, A12, k), B22, k);
    int **P3 = Strassen(add(A21, A22, k), B11, k);
    int **P4 = Strassen(A22, subtract(B21, B11, k), k);
    int **P5 = Strassen(add(A11, A22, k), add(B11, B22, k), k);

    int **P6 = Strassen(subtract(A12, A22, k), add(B21, B22, k), k);
    int **P7 = Strassen(subtract(A11, A21, k), add(B11, B12, k), k);

    int **C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    int **C12 = add(P1, P2, k);
    int **C21 = add(P3, P4, k);
    int **C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    return C;
}

int main(){

    int size;
    cout << "\n Enter the size of matrix (power of 2): ";
    cin >> size;

    int **A = Matrix(size);
    int **B = Matrix(size);
    int **C = Matrix(size);

    cout << "\n Enter elements for matrix A: \n";
    insert(A, size);

    cout << "\n Enter elements of matrix B: \n";
    insert(B, size);
    
    C = Strassen(A, B, size);
    cout << "\n Matrix C: \n";
    display(C, size);
    
    return 0;
}