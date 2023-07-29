class Solution {
public:
    int n;
    long long solve(int i,vector<vector<int>>&a, vector<long long>&dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = 0;
        ans = max(ans,solve(i+1,a,dp));
        ans = max(ans,a[i][0] + solve(i+a[i][1]+1,a,dp));
        return dp[i] = ans;
    }

    long long mostPoints(vector<vector<int>>& a) {
       n = (int)a.size();
       vector<long long>dp(n+2,-1);
       return solve(0,a,dp);
    }
};
