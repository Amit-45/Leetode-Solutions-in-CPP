https://leetcode.com/problems/rotate-array/description/

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
