Refer - https://leetcode.com/problems/set-matrix-zeroes/solutions/2525398/all-approaches-from-brute-force-to-optimal-with-easy-explanation/?page=2

=============BRUTE FORCE===================================================================Time: O((mn)*(m+n))============== Space: O(mn)=======================
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
===============================BETTER APPROACH============================================Time: O(mn)======================== Space: O(m+n)================
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
=================================OPTIMAL APPROACH=================================================Time: O(mn)===========Space:O(1)======================
 1. first we will traverse the 0th row and 0th column of the given matrix and if we encounter any 0 
 2. then we will set the isRow0/isCol0 variable to true which indicates that the 0th row/0th column of the given matrix will become 0
 3 next we will traverse the remaining matrix except 0th row and 0th column 
  and if we encounter any 0, we will make the corresponding row no. and column no. equal to 0 in the 0th column and 0th row respectively
 4. Now we will update the values of the matrix except first row and first column to 0 if matrix[i][0]=0 or matrix[0][j]=0 for any (i,j).
 5.finally we will traverse the 0th row and 0th column and if we find any 0, we will make the whole row and whole column equal to 0
   

 void setRowColumnToZeroOptimal(int matrix[][100], int m, int n)
{

  bool isRow0 = false, isCol0 = false;

  for (int j = 0; j < n; j++)
  {
    if (matrix[0][j] == 0)
      isRow0 = true;
  }

  for (int i = 0; i < m; i++)
  {
    if (matrix[i][0] == 0)
      isCol0 = true;
  }

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (matrix[i][j] == 0)
      {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (matrix[0][j] == 0 || matrix[i][0] == 0)
        matrix[i][j] = 0;
    }
  }

  if (isRow0)
  {
    for (int j = 0; j < n; j++)
      matrix[0][j] = 0;
  }

  if (isCol0)
  {
    for (int i = 0; i < m; i++)
      matrix[i][0] = 0;
  }
}
