=========USING RECURSION===========================================Time: O(N!xN)=========Space:O(1)
  1. Find all possible combinations using recursion and stor 
  2. Search the input (that we gave ) in the combination
  3. Print the very next permutation after that 
 ======USING INBUILT FUNCTION======================================Time:O(N!xN) =========Space:O(1)
  1. Function name : next_permutation(arr,arr+size)
 =======OPTIMAL: Using inflation point and toSwap concept=================Time:O(N)========Space:O(1)
 class Solution {
public:
    void nextPermutation(vector<int>& nums)
 {
    int infpt = 0;
    int n = nums.size() - 1;
    for (int i = n; i > 0; i--)
    {
      if (nums[i] > nums[i - 1])
      {
        infpt = i;
        break;
      }
    }
    if (infpt == 0)
    {
      sort(nums.begin(), nums.end());
    }
    else
    {
      int toSwap = nums[infpt - 1];
      for (int j = infpt; j <= n; j++)
      {
        if (nums[j] - toSwap > 0 )
        {
          swap(nums[j], nums[infpt - 1]);
        }
      }

      sort(nums.begin() + infpt, nums.end());
    }     
 }
};
  
  
