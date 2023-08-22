class Solution {
public:
    int n;

    int solve(int i , int k , vector<vector<int>> &a , vector<vector<int>> &dp) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int ans = 0;
        vector<int>e = {a[i][1]+1,INT_MIN,INT_MIN};
        int id = lower_bound(a.begin(),a.end(),e) - a.begin();
        if(k > 0) {
            ans = max(ans , a[i][2] + solve(id,k-1,a,dp));
        }
        ans = max(ans,solve(i+1,k,a,dp));
        return dp[i][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        n = (int)events.size();
        vector<vector<int>>dp(n+2,vector<int>(k+2,-1));
        return solve(0,k,events,dp);
    }
};