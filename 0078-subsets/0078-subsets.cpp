class Solution {
    
    void solve(vector<int>nums,int index,vector<int>out,vector<vector<int>>&ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(out);
            return;
        }
        solve(nums,index+1,out,ans);
        out.push_back(nums[index]);
        solve(nums,index+1,out,ans);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>out;
        vector<vector<int>>ans;
        int index=0;
        solve(nums,index,out,ans);
        return ans;
    }
};