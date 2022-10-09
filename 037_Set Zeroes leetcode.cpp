Refer - https://leetcode.com/problems/set-matrix-zeroes/solutions/2525398/all-approaches-from-brute-force-to-optimal-with-easy-explanation/?page=2

=============BRUTE FORCE====================================================================================================Time: O((mn)*(m+n))==============
1. crate a new matrix 
2. copy all the elements of matrix1 to matrix2 ,  
3. if we find zero in any row or column of matrix2, then change all the elements of that row or column to 0
4. copying back elements of matrix2 to the matrix1

#include <bits/stdc++.h>
using namespace std;
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
===============================BETTER APPROACH========================================================================Time: O(mn)========================
#include <bits/stdc++.h>
using namespace std;

void setRowColumnToZero(int matrix[][100], int m, int n)
{

  int rowsArray[m];
  fill_n(rowsArray, m, 1); // fill rowsArray with 1
  int colsArray[n];
  fill_n(rowsArray, m, 1); // fill colsArray with 1

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // if any row or column of our matrix is 0,
      // then we poplate that particular index of  rowsArray as well as colsArray to 0
      if (matrix[i][j] == 0)
      {
        rowsArray[i] = 0;
        colsArray[j] = 0;
      }
    }
  }
  // again we traverse the matrix elements
  // for any (i,j), if rowsArray[i] or colsArray[j] is 0 then update matrix[i][j] to 0.
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (rowsArray[i] == 0 || colsArray[j] == 0)
        matrix[i][j] = 0;
    }
  }
}

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
