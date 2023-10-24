#Solution 1 : Brute force -> TC :O(N^2) SC: O(1)
#Steps for solution 1 :
# 1. First check if 1st element has a dupliacte in the array by comparing with every other element in array 
# 2. Then do it with the second element and continue till the end of the array 
# ---------------------------------------------------------
# Solution 2: Sorting -> TC : O(n log n ) SC:O(1)
# Steps for Solution 2:
# 1. Iterate the array once 
# 2. As we iterate do compare the 2 neighbours in array and check if they are duplicates 
# ---------------------------------------------------------
# Solution 3: Using a hashset ->TC :O(n) SC: O(n)
# Steps for solution 3:-
# 1.Use hashset (because insertion in hashset is O(1)) : hashset = set()
# 2.Check one by one if element is present in hashset ? : for n in nums:
#          - If yes -> return true  : if n in hashset: return True
#          - If no -> return false and then push the element into the hashset :  else: hashset.add(n)
# ---------------------------------------------------------
class Solution(object):
    def containsDuplicate(self, nums):
        hashset = set()
        for n in nums:
            if n in hashset:
                return True
            else:
                hashset.add(n)
        return False
        
        