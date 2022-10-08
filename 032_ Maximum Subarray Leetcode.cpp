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
