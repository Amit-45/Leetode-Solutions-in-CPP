-----------Print 1 to N using recursion(Using global variable)----------------------------------------------------------------------
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
----------------------Print 1 to N using recursion(Without using global variable)(using parameters )---------------------------------------------------
 #include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // int count = 1;
  void printNos(int count, int N)
  {
    if (count == N + 1)
      return;
    cout << count << " ";
    // count++;
    printNos(count + 1, N);
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
    ob.printNos(1, N);
    cout << "\n";
  }
  return 0;
}

----------------------Print name N times using recursion(using global variable)------------------------------------------------------------

 #include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int count = 1;
  void printGfg(int N)
  {
    if (count == N + 1)
      return;
    cout << "GFG ";
    count++;
    printGfg(N);
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
    ob.printGfg(N);
    cout << "\n";
  }
  return 0;
}
----------------------Print name N times using recursion(Without using global variable)(using parameters )---------------------------------------------------
  #include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // int count = 1;
  void printGfg(int count, int N)
  {
    if (count == N + 1)
      return;
    cout << "GFG ";
    // count++;
    printGfg(count + 1, N);
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
    ob.printGfg(1, N);
    cout << "\n";
  }
  return 0;
}

-------------------------Print from N to 1(using parameters )-------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void printNos(int count, int N)
  {
    if (count == 0)
      return;
    cout << count << " ";
    printNos(count - 1, N);
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
    ob.printNos(N, N);
    cout << "\n";
  }
  return 0;
}
-------------------------Print from N to 1(using global variable)-------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int count = 0;
  void printNos(int N)
  {
    if (count == N)
      return;
    cout << N << " ";

    N--;
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
