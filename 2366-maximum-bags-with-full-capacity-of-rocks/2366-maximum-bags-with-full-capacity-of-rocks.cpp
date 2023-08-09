class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = (int)capacity.size();
        vector<int>b;
        for(int i = 0 ; i < n ; i++) {
          b.push_back(capacity[i] - rocks[i]);
        }
        sort(b.begin(),b.end());
        int ans = 0;
        for(auto x : b) {
            if(additionalRocks >= x) {
                ++ans;
                additionalRocks -= x;
            }
        }
        return ans;
    }
};