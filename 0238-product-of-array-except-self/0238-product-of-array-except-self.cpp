class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> leftProd(size);
        vector<int> rightProd(size);

        int prod=1;
        for(int i=0;i<size;i++)
        {
            rightProd[i]=prod;
            prod*=nums[i];
        }

        cout<<prod<<endl;

         prod=1;
        for(int i=size-1;i>=0;i--)
        {
            leftProd[i]=prod;
            prod*=nums[i];
        }

        vector<int> answer(size);
        for(int i=0;i<size;i++)
        {
            answer[i]=leftProd[i]*rightProd[i];
        }

        return answer;
    }
};