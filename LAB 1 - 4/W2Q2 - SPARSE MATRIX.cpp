#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 0, j = 0, k = 0, n, m;
    int a[20][20], b[3][20];
    
    cout << "Enter size of 2D matrix (rows and columns):" << endl;
    cin >> m >> n;
    
    cout << "Enter all elements:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cout << "Original Matrix:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Convert to sparse matrix representation
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                b[0][k] = i;    // Row index
                b[1][k] = j;    // Column index
                b[2][k] = a[i][j]; // Value
                k++;
            }
        }
    }

    // Print the sparse matrix representation
    cout << "Sparse Matrix Representation:" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < k; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }

    // Reconstruct the matrix from sparse representation
    int c[20][20] = {0};  // Initialize with zeros
    cout << "Reconstructed Matrix:" << endl;
    for (i = 0; i < k; i++)
    {
        int row = b[0][i];
        int col = b[1][i];
        int value = b[2][i];
        c[row][col] = value;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
