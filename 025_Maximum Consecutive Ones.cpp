https://leetcode.com/problems/max-consecutive-ones/submissions/817284700/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;
        for(int i = 0;i<nums.size();i++) {  
            //is we find 1 increase the count (because another consecutive 1 may be there)
            if(nums[i] == 1) {
                cnt++; 
            }
          //if we find 0 then initialise back the count to 0 because consecutive ones are no more there 
            else {
                cnt = 0;   
            }
            // if count>max then update it to max
            maxi = max(maxi, cnt); 
        }
        return maxi; 
    }
};
