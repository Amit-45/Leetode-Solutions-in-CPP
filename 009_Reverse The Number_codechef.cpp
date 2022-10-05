Link-https://www.codechef.com/LRNDSA01/problems/FLOW007

#include <iostream>
using namespace std;
int main()
{
  int t;
  cin>>t;
  
  while(t--){
  int n;
  cin >> n;

  int rev = 0;
  while (n != 0)
  {
    int last = n % 10;
    rev = rev*10 + last;
    n = n / 10;
  }
  cout << rev << endl;
  }
}


