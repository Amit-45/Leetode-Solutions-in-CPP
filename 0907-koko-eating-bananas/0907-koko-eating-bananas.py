#Using linear serach . TC: O(max_pile * n).
# import math
# class Solution:
#     def minEatingSpeed(self, piles, h):
#         max_pile = max(piles)
#         res = max_pile
        
#         for k in range(1, max_pile + 1):
#             totalTime = 0
#             for p in piles:
#                 totalTime += math.ceil(float(p) / k)
#             if totalTime <= h:
#                 res = k
#                 break
        
#         return res


#Using Binary search TC: O(log(max_pile) * n)
import math
class Solution:
    def minEatingSpeed(self, piles, h) :
        l, r = 1, max(piles)
        res = r

        while l <= r:
            k = (l + r) // 2

            totalTime = 0
            for p in piles:
                totalTime += math.ceil(float(p) / k)
            if totalTime <= h:
                res = k
                r = k - 1
            else:
                l = k + 1
        return res


