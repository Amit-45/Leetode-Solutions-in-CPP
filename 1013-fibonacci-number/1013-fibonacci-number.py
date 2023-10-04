#Recursive approach
class Solution(object):
    def fib(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.fib(n-1) + self.fib(n-2)
# TC: O(2^N)
# SC: O(N)


#Using DP to optimise 
class Solution:
    def helperFunc(self, N, dp):
        if N <= 1:
            return N

        if dp[N] == -1:
            dp[N] = self.helperFunc(N - 1, dp) + self.helperFunc(N - 2, dp)
        
        return dp[N]

    def fib(self, N):
        dp = [-1] * (N + 1)
        return self.helperFunc(N, dp)
# TC: O(N)
# SC O(N)