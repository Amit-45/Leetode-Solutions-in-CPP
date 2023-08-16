class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int>AND((1 << 16)+7,0);
        int n = (int)nums.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                AND[nums[i]&nums[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < (1 << 16) + 2 ; j++) {
                if((nums[i] & j) == 0) {
                    ans += AND[j];
                }
            }
        }
        return ans;
    }
};