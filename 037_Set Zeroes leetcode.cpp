Refer - https://leetcode.com/problems/set-matrix-zeroes/solutions/2525398/all-approaches-from-brute-force-to-optimal-with-easy-explanation/?page=2

=============BRUTE FORCE====================================================================================================
1. crate a new matrix 
2. copy all the elements of matrix1 to matrix2 ,  
3. if we find zero in any row or column of matrix2, then change all the elements of that row or column to 0
4. copying back elements of matrix2 to the matrix1


void setRowColumnToZero(int matrix[][100], int m, int n)
{

  int matrix2[m][n]; // matrix2

  // copying elements of matrix1 to the matrix2
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      matrix2[i][j] = matrix[i][j];
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // if we find zero in any row or column of matrix2,
      // then change all the elements of that row or column to 0
      if (matrix[i][j] == 0)
      {
        for (int k = 0; k < n; k++)
          matrix2[i][k] = 0;

        for (int k = 0; k < m; k++)
          matrix2[k][j] = 0;
      }
    }
  }
  // copying back elements of matrix2 to the matrix1
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      matrix[i][j] = matrix2[i][j];
  }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[100][100];
  int m, n;
  cout << "Enter m and n value :" << endl;
  cin >> m >> n;
  cout << "Enter matrix elements:" << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  setRowColumnToZero(arr, m, n);
  cout << " " << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
