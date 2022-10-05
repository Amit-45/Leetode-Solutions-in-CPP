https://www.codingninjas.com/codestudio/problems/swap-alternate_624941?leftPanelTab=0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void swapAlternate(int arr[], int size)
{
  if (size % 2 == 0)
  {
    for (int i = 0; i < size; i = i + 2)
    {

      swap(arr[i], arr[i + 1]);
    }
  }
  else
  {
    for (int i = 0; i < size - 1; i = i + 2)
    {

      swap(arr[i], arr[i + 1]);
    }
  }
}
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}
int main()
{
  int arr[4] = {1, 8, 7, 5};

  int size = sizeof(arr) / sizeof(int);

  swapAlternate(arr, size);
  printArray(arr, size);
}
