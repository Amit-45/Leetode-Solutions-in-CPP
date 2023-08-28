
class Solution {
public:
    int n;
    int solve(int i, int prev, vector<int> &a , vector<vector<int>> &dp) {
        if(i == n-1) {
            return 1;
        }
        if(dp[i][prev] != -1) return dp[i][prev];
        int k = a[i] - a[prev];
        int ans = 0;
        for(int j = k-1 ; j <= k+1 ; j++) {
            int nextPos = lower_bound(a.begin(),a.end(),a[i]+j) - a.begin();
            if(nextPos < n && (a[nextPos] == a[i] + j) && nextPos > i) {
                ans |= solve(nextPos,i,a,dp);
            }
        }
        return dp[i][prev] = ans;
    }
    bool canCross(vector<int>& stones) {
        n = (int)stones.size();
        vector<vector<int>>dp(n+3,vector<int>(n+3,-1));
        if(stones[1] != 1) {
            return 0;
        }
        return solve(1,0,stones,dp);
    }
};