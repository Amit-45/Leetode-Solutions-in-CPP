https://codeforces.com/problemset/problem/610/A

include <bits/stdc++.h>
using namespace std;
int main()
{
  int sticks;
  cin >> sticks;
 
  // if sticks are odd
  if (sticks % 2 != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  // diving into two parts
  sticks = sticks / 2;
 
  // even half
  if (sticks % 2 == 0)
  {
    cout << sticks / 2 - 1 << endl;
  }
  else
  {
    cout << sticks / 2 << endl;
  }
}
