class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = (int)nums.size();
        for(int i = 0 ; i < (1 << n) ; i++) {
            vector<int>b;
            for(int j = 0 ; j < n ; j++) {
                int x = (1 << j);
                if(i & x) {
                    b.push_back(nums[j]);
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};