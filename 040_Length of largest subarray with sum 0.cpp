===========================BRUTE FORCE=====================================================================================================
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
    int  maxi = 0;
	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = i; j < n; ++j){
			sum += A[j];
			if(sum == 0){
				maxi = max(maxi, j-i+1);
			}
		}
	}
	return maxi;
    }
};

  
  
====================== CHECK IF SUBARRAY OF SUM 0 EXISTS=====================================================================================
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int f = 0;
    for (int i = 0; i < n; i++)
    {
      int s = 0;
      for (int j = i; j < n; j++)
      {
        s = s + a[j];
        if (s == 0)
        {
          f = 1;
          break;
        }
      }
      if (f == 1)
        break;
    }
    if (f == 1)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
