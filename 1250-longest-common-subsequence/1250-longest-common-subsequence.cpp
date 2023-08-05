class Solution {
public:
    int dp[1007][1007];
    
    int solve(int i , int j , string &s , string &t) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = solve(i-1,j,s,t);
        res = max(res,solve(i,j-1,s,t));
        res = max(res,solve(i-1,j-1,s,t) + (s[i] == t[j]));
        return dp[i][j] = res;
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = (int)text1.size();
        int m = (int)text2.size();
        return solve(n-1,m-1,text1,text2);
    }
};