class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int x=nums[i];
            int y = target - x;
            
            if (mp.find(y) != mp.end()) {
                return { mp[y], i };
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
