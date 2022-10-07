//By hashing
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {

          // create an array with size n+1 and then populating it with zeroes
  int n = nums.size() + 1;
  vector<int> freq(n, 0);

  vector<int> ans; // answer  nums .

  // traversing through the first array and increasing the values at freq array based on that
  for (int i = 0; i < nums.size(); i++)
  {
    freq[nums[i]]++;
  }

  // trvaersing the freq array from index 1 to N
  for (int i = 1; i <= nums.size(); i++)
  {
    if (freq[i] == 0)
    {
      ans.push_back(i);
    }
  }
  return ans; //getting error while return
  

    }
};

//Optimised approach (Sum and sum square approach)(Codestudio link -https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_873366)
#include <bits/stdc++.h>
typedef long long int ll;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{

  ll len = arr.size();

  ll  S= (len * (len + 1)) / 2;
  ll  P = (len * (len + 1) * (2 * len + 1)) / 6;
  ll  missingNumber = 0, repeating = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    S -= (ll )arr[i];
    P -= (ll )arr[i] * (ll )arr[i];
  }

  missingNumber = (S + P / S) / 2;

  repeating = missingNumber - S;

  return {missingNumber, repeating};
}
//Optimised approach (XOR approach)
