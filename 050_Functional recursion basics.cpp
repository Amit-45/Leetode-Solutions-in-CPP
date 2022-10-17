----------------Sum of N natural numbers(using functional recursion)--------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumOfSeriesTillN(int n)
  {
    if (n == 0)
      return 0;
    return n + (sumOfSeriesTillN(n - 1));
  }
};

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    long long N;
    cin >> N;
    Solution ob;
    cout << ob.sumOfSeriesTillN(N);
    cout << "\n";
  }
  return 0;
}
--------------------------------Fibonacci( using functional recursion)--------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int fibonacciUsingRecursion(int n)
  {
    if (n == 0)
      return 1;
    return n * (fibonacciUsingRecursion(n - 1));
  }
};

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    long long N;
    cin >> N;
    Solution ob;
    cout << ob.fibonacciUsingRecursion(N);
    cout << "\n";
  }
  return 0;
}
---------------------Sum of N cube numbers [O(N) solution](using recursion)----------------------------------------------------------------------------------
  #include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long sum = 0;
  long long sumOfNCubeSeries(long long N)
  {
    if (N == 0)
      return 0;

    sumOfNCubeSeries(N - 1);
    sum = (long)(sum + pow(N, 3));

    return sum;
  }
};

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    long long N;
    cin >> N;
    Solution ob;
    cout << ob.sumOfNCubeSeries(N);
    cout << "\n";
  }
  return 0;
}
---------------------Reverse array using recursion(using two pointees)---------------------------------------------------------------------------------
  #include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
void reverseArray(int arr[], int low, int high)
{
  if (low >= high)
    return;

  swap(arr[low], arr[high]);
  reverseArray(arr, low + 1, high - 1);
}
int main()
{
  int n, i;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  reverseArray(arr, 0, n - 1);
  printArray(arr, n);
}

---------------------Reverse array using recursion(using one pointer)---------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
void reverseArray(int arr[], int i, int n)
{
  if (i >= n / 2)
    return;

  swap(arr[i], arr[n - i - 1]);
  reverseArray(arr, i + 1, n);
}
int main()
{
  int n, i;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  reverseArray(arr, 0, n);
  printArray(arr, n);
}
