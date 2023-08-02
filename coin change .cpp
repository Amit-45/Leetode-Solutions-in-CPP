class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = 2e5+79;
        int dp[N];
        int inf = 1e6;
        dp[0] = 0;
        for(int i = 1 ; i < N ; i++) {
            dp[i] = inf;
            for(auto c : coins) {
                if(i - c >= 0) {
                    dp[i] = min(dp[i-c]+1,dp[i]);
                }
            }
        }
        if(dp[amount] == inf) return -1;
        return dp[amount];
    }
};
