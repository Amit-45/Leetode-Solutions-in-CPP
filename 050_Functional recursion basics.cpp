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
--------------------------------Fibonacci( using functional recursion)--------------------------------------------------------------------------------------------
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
