class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        int j = 0;
        int len = 0;
        int count = 0; // it will keep account of number of times 0 has occured till ith index
        for(int i = 0 ; i < nums.size() ;){
            if(!nums[i])count++;
            while(count>1){
                if(!nums[j]){
                    count-=1;
                }
                j++;
            }
            len = max(len,i-j);
            i++;
        }
        return len;
    }
};