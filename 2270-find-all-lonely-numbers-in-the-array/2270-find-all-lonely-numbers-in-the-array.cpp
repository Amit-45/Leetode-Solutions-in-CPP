class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto x : mp) {
            if(x.second == 1) {
                if((mp.find(x.first-1) == mp.end()) && (mp.find(x.first+1) == mp.end())) ans.push_back(x.first);
            }
        }
        return ans;
    }
};