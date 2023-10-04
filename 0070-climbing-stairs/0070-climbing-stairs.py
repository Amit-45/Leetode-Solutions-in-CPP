#RECURSION------------------------------------
class Solution:
    def recursion(self, index, dp):
        if index == 0:
            return 1
        if index == 1:
            return 1

        if dp[index] != -1:
            return dp[index]

        left = self.recursion(index - 1, dp)
        right = self.recursion(index - 2, dp)

        dp[index] = left + right
        return dp[index]

    def climbStairs(self, n):
        dp = [-1] * (n + 1)
        return self.recursion(n, dp)

# Time Complexity: O(n)
# Space Complexity: O(n)

#MEMOIZATION -----------------------------------
class Solution:
    def memoization(self, index, dp):
        if index == 0:
            return 1
        if index == 1:
            return 1

        if dp[index] != -1:
            return dp[index]

        left = self.memoization(index - 1, dp)
        right = self.memoization(index - 2, dp)

        dp[index] = left + right
        return dp[index]

    def climbStairs(self, n):
        dp = [-1] * (n + 1)
        return self.memoization(n, dp)

# Time Complexity: O(n)
# Space Complexity: O(n)



#SPACE OPTIMIZATION------------------------------------
class Solution:
    def spaceOptimization(self, index):
        prev1, prev2 = 1, 1

        for i in range(2, index + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr

        return prev1

    def climbStairs(self, n):
        return self.spaceOptimization(n)

# Time Complexity: O(n)
# Space Complexity: O(1)
