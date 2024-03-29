class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> answer(n);

        int prod=1;
        for(int i=0;i<n;i++)
        {
            answer[i]=prod;
            prod*=nums[i];
        }

        int suffixProd=1;
        for(int i=n-1;i>=0;i--)
        {
            answer[i] *= suffixProd;
            suffixProd*=nums[i];
        }

        return answer;

    }
};