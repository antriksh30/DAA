#include<bits/stdc++.h>
using namespace std;

int **Matrix(int n)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

int **DivideAndConquer(int **A, int **B, int n){
    if(n == 1){
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


    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    int **P1 = DivideAndConquer(A11,B11,k);
    int **P2 = DivideAndConquer(A12,B21,k);
    int **P3 = DivideAndConquer(A11,B12,k);
    int **P4 = DivideAndConquer(A12,B22,k);
    int **P5 = DivideAndConquer(A21,B11,k);
    int **P6 = DivideAndConquer(A22,B21,k);
    int **P7 = DivideAndConquer(A21,B12,k);
    int **P8 = DivideAndConquer(A22,B22,k);

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            C[i][j] = P1[i][j] + P2[i][j];
            C[i][j+k] = P3[i][j] + P4[i][j];
            C[i+k][j] = P5[i][j] + P6[i][j];
            C[i+k][j+k] = P7[i][j] + P8[i][j];
        }
    }

    return C;
}

int main(){
    int size;
    cout << "Enter the size of matrix(in powers of 2): ";
    cin >> size;

    int **A = Matrix(size);
    int **B = Matrix(size);
    int **C = Matrix(size);


    cout << "Enter the elements of matrix A: " << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix B: " << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> B[i][j];
        }
    }

    C = DivideAndConquer(A,B,size);

    cout << "The product of matrix A and B is: " << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}