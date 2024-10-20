#include <iostream>
using namespace std;
void printMatrix(int matrix[20][20], int n) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cout << matrix[i][j] << "\t";
 }
 cout << endl;
 }
}
void upperTriangular(int matrix[20][20], int n) {
 int upper[20][20];
 // Copy original matrix to upper triangular form
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 upper[i][j] = (i <= j) ? matrix[i][j] : 0;
 }
 }
 cout << "Upper Triangular Matrix:" << endl;
 printMatrix(upper, n);
}
void lowerTriangular(int matrix[20][20], int n) {
 int lower[20][20];
 // Copy original matrix to lower triangular form
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 lower[i][j] = (i >= j) ? matrix[i][j] : 0;
 }
 }
 cout << "Lower Triangular Matrix:" << endl;
 printMatrix(lower, n);
}
void diagonalMatrix(int matrix[20][20], int n) {
 int diagonal[20][20];
 // Copy original matrix to diagonal matrix form
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 diagonal[i][j] = (i == j) ? matrix[i][j] : 0;
 }
 }
 cout << "Diagonal Matrix:" << endl;
 printMatrix(diagonal, n);
}
void triDiagonalMatrix(int matrix[20][20], int n) {
 int triDiagonal[20][20];
 // Copy original matrix to tri-diagonal matrix form
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 triDiagonal[i][j] = (i == j || i == j + 1 || i == j - 1) ? matrix[i][j] : 0;
 }
 }
 cout << "Tri-Diagonal Matrix:" << endl;
 printMatrix(triDiagonal, n);
}
void rowMajorOrder(int matrix[20][20], int n) {
 cout << "Row-Major Order:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cout << matrix[i][j] << "\t";
 }
 }
 cout << endl;
}
void columnMajorOrder(int matrix[20][20], int n) {
 cout << "Column-Major Order:" << endl;
 for (int j = 0; j < n; j++) {
 for (int i = 0; i < n; i++) {
 cout << matrix[i][j] << "\t";
 }
 }
 cout << endl;
}
int main() {
 int i, j, n;
 int matrix[20][20];
 cout << "Enter size of 2D matrix (n x n): " << endl;
 cin >> n;
 cout << "Enter all elements of the matrix:" << endl;
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 cin >> matrix[i][j];
 }
 }
 // Display the original matrix
 cout << "Original Matrix:" << endl;
 printMatrix(matrix, n);
 // Display different matrix forms
 upperTriangular(matrix, n);
 lowerTriangular(matrix, n);
 diagonalMatrix(matrix, n);
 triDiagonalMatrix(matrix, n);
 rowMajorOrder(matrix, n);
 columnMajorOrder(matrix, n);
 return 0;
}
