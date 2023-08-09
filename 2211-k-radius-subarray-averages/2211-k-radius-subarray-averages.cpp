class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        int n = (int)a.size();
        vector<long long>pref(n+1,0);
        for(int i = 0 ; i < n ; i++) {
            pref[i+1] = pref[i] + a[i];
        }
        vector<int>ans(n,-1);
        for(int i = k+1 ; i + k <= n ; i++) {
            long long sum = pref[i+k] - pref[i-k-1];
            ans[i-1] = sum/(2*k+1);
        }
        return ans;
    }
};