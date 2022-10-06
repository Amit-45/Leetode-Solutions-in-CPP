https://leetcode.com/problems/rotate-array/description/
//normal program 

#include <bits/stdc++.h>
using namespace std;
int main()

{

  // k is number of rotations
  int n, k;
  cin >> n >> k;

  int nums[n];
  // taking input
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  // temp array
  int temp[n];

  // formula for operations in nums array but stored in temp
  for (int i = 0; i < n; i++)
    temp[(i + k) % n] = nums[i];

  // copying back temp array elements to nums array
  for (int i = 0; i < n; i++)
    nums[i] = temp[i];

  // printing array elements
  for (int i = 0; i < n; i++)
    cout << nums[i] << " ";
}







//leetcode solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      //size of nums array   
      int n=nums.size();
      //temp vector created to prevent any type of over writes
         vector<int> temp(n);
      //using the % formula
      //remember we are performing operations in nums array but storing in temp
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n]=nums[i];
        }
      //finally copying all the temp array elements into the nums array 
        nums=temp;

        
    }
};




