#Hashmap approach -> TC: O(n) SC: O(n)
#Steps :-
#1. Create a hashmap that will store (element : index):             prevMap = {}
#2. Iterate through the list with both index (i) and value (n) 
#          for i, n in enumerate(nums):  
#3. Calculate the diff that is nothing but Y
#4. If y is present in map -> Return(Index of Y in hash, Index of X in array) :  return [prevMap[diff], i]
#5. # Store the current number's index in the dictionary
class Solution:
    def twoSum(self, nums, target):
        prevMap = {}  # val -> index

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i  

