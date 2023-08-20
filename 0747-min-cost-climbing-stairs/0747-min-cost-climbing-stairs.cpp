class Solution {
public:
    int dp[1000];
    int rec(int level, vector<int>& n) {

        if (level >= n.size()) {
            return 0;
        }

        // Base case
        if (level == n.size() - 1) {
            return n[level];
        }

        if (dp[level] != -1) {
            return dp[level];
        }

        int choice1 = n[level] + rec(level + 1, n);
        int choice2 = n[level] + rec(level + 2, n);

        

        return dp[level] = min(choice1, choice2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
           
        int choice1 = rec(0, cost);
        int choice2 = rec(1, cost);
        return min(choice1, choice2);
    }
};