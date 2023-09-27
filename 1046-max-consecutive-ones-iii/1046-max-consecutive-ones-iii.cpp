class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0 ;
        int j=0 ;
        int n=nums.size();

        int maxi =0;
        for(int j=0 ;j<n;j++){
            if(nums[j] ==0)k--;
            while(k<0){
               if(nums[i] ==0)k++; 
               i++;
            }
            maxi =max(maxi,j-i+1);
        }
        return max(maxi,j-i);
    }
};