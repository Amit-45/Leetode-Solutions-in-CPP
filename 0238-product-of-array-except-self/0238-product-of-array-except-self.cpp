class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> rightProd(n);
        vector<int> leftProd(n);


        //right part prefix product
        int prod=1;
        for(int i=0;i<n;i++)
        {
            rightProd[i]=prod;
            prod*=nums[i];
        }

        //left part prefix product
        prod=1;
        for(int i=n-1;i>=0;i--)
        {
            leftProd[i]=prod;
            prod*=nums[i];
        }

        //answer vector
        vector<int> answer(n);
        for(int i=0;i<n;i++)
        {
            answer[i]=leftProd[i]*rightProd[i];
        }

        return answer;

    }
};