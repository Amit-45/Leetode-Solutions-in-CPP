//Print 1 to N using recursion
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int count = 1; //count must be public
  void printNos(int N)
  {
    //base case 
    if (count == N + 1)
      return;
    cout << count << " ";
    count++;
    printNos(N); 
  }
};

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;
    Solution ob;
    ob.printNos(N);
    cout << "\n";
  }
  return 0;
}
