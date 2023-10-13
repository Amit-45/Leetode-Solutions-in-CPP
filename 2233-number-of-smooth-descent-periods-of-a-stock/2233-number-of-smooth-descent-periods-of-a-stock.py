class Solution:
    def getDescentPeriods(self, A):
        res = count = 1
        for i in range(1,len(A)):
            if A[i] == A[i-1] - 1: count += 1
            else: count = 1
            res += count
        return res
        