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
