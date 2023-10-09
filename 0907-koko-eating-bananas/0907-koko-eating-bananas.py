#Using linear serach . TC: O(max_pile * n).
import math
class Solution:
    def minEatingSpeed(self, piles, h):
        max_pile = max(piles)
        res = max_pile
        
        for k in range(1, max_pile + 1):
            totalTime = 0
            for p in piles:
                totalTime += math.ceil(float(p) / k)
            if totalTime <= h:
                res = k
                break
        
        return res


#Using Binary search TC: O(log(max_pile) * n)
#Take l and r pointer l=1 and r to the max of array or pile
#We need to finf the minimum. So we start from r which is our max possible answer and then gradually check which will be our minimum possible answer 
#We have to calculate k first : k = (l + r) // 2
#Then we calculate for this value k , how many hours will it take to eat all bananas : totalTime = 0
#Now we go through all the piles and find the ceil value for each : for p in piles
#Ih hours <= given input h Update the result to the current speed k.
# Narrow the search range to the left :  r = k - 1
#In other case : else part (hours > given input h )
# Narrow the search range to the right : l = k + 1
#Finally return the result 
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


