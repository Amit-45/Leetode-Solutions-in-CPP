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


//Optimised approach (Sum and sum square approach) GFG(https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating)
//have to return in int * 

typedef long long int ll;
class Solution{
public:
    int *findTwoElement(int *arr, int n)
    
    {
     
     ll len = n;

  ll  S= (len * (len + 1)) / 2;
  ll  P = (len * (len + 1) * (2 * len + 1)) / 6;
  ll  missingNumber = 0, repeating = 0;

  for (int i = 0; i < n; i++)
  {
    S -= (ll )arr[i];
    P -= (ll )arr[i] * (ll )arr[i];
  }

  missingNumber = (S + P / S) / 2;

  repeating = missingNumber - S;

  
    
    int *ans=new int(2);
    ans[0]=repeating;
    ans[1]=missingNumber;
       
     return ans ;   
    }
};
//Optimised approach (XOR approach)
