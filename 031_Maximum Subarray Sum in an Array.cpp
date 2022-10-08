============================
Brute force using 3 for loops  - Iterate over all sub arrays -Try to find the maximum subarray sum by using these  3 loops (i loop and j loop to form subarrays)(k loop just to store the sum)
=============================

#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums, vector<int> &subarray)
{

  if (nums.empty() == 1 || nums.size() == 0)  //edge case that if vector is empty 
    return 0;

  int maxSum = INT_MIN;

  for (int i = 0; i < nums.size(); i++)      //let i value be 0  
  {
    for (int j = i; j < nums.size(); j++)    //j moves to 1st index, then 2nd,then 3rd 
                                             //each time j moves a subarray is generated (subarray of size[i.......j])
    {
      
      //--------------this third loop finds the sum reqd-------------------------------------------------------------------
      int currSum = 0;

      for (int k = i; k <= j; k++)          // now we use this third loop to find the sum
      {
        currSum += nums[k];
      }
      //---------------now we update max----------------------------------------------------------------------------------

      maxSum = max(maxSum, currSum);
    }
  }

  return maxSum;
}

int main()
{
  vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> subarray;
  int lon = maxSubArray(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++)
  {
    cout << arr[i] << " ";
  }
}




============================
Better approach using 2 for loops  - Iterate over all sub arrays - (i loop and j loop to form subarrays)(k loop just to store the sum)
=============================
  int maxSubArray2(vector<int> &nums, vector<int> &subarray)
{

  if (nums.empty() == 1 || nums.size() == 0)
    return 0;

  int maxSum = INT_MIN;

  for (int i = 0; i < nums.size(); i++)    //let i value be 0  
  {
    int currSum = 0;
//-------------------- j loop allows j to shift for creating sub arrays and simultaneously keeps finding the sum that is req-------------------------------------
    for (int j = i; j < nums.size(); j++) //j moves to 1st index, then 2nd,then 3rd 
                                            //each time j moves a subarray is generated (subarray of size[i.......j])
    {
      //instead of again running a third loop and iterate over the subarray again , we can just update the sum value when we were shifting j and generating sub arrays
      currSum += nums[j];
      maxSum = max(maxSum, currSum);
    }
  }

  return maxSum;
}

================================KADANES ALGO ====================================================================================================
//sliding window cant be used in this case because it fails for negative numbers
//but Kadanes algo takes negative numbers into cosideration as well
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KADANES ALGO 
        int sum = 0;
        int maxi=nums[0]; //because atleast there is one solution

        for(int i=0;i<nums.size();i++)
        {
            //STEP1
            sum=sum+nums[i];
            //STEP2
            maxi=max(maxi,sum);
            //STEP3
            if(sum<0) sum=0;
        }
       
        return maxi;
    }
};
//Refer - Love babbar video

