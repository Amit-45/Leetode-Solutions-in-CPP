https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
class Solution {
public:
    bool check(vector<int>& nums) {
      //4 cases -> sorted(1 pair satisfies the formula)   sortedAndRotated(1 pair)  randomArray(more than 1 pair)  arrayWithSameElements(0 pairs)
      //formula to check comparisons  ->  nums[i-1]>nums[i] 
               
      int n=nums.size();
      int count=0;
      
      //normal array element comparisions(mormal check)
      for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]) 
            count++;
        }
      //last and first element comparisions(cyclic check)
        if(nums[n-1]>nums[0])
        count++;
      
      //return true for O or 1 pairs 
      return count<=1;
    }
};
