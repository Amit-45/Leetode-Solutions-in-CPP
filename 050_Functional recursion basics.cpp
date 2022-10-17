----------------Sum of N natural numbers(using recursion)--------------------------------------------------------------------------------------------
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
