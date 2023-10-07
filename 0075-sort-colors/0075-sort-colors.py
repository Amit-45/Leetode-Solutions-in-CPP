#Easy solution : Merge sort or quick sort 
#better solution : Bucket sort (2 pass solution)
#Best solution: DNF algo (1 pass solution)
#Two pointers: low, high at the start and at the end and i pointer that is goining to itereate through the array till it passes the right pointer 
#So while i<=r 
#We have two cases Either the value will be 0 otherwise the value will be 2 (for left case the value will be 0 and for right it will be 2) 
#In both of the case we do a swap
#If case is left increment left by 1
#If case is right increment left by 1
#Remember we have to not increment i in case i is pointig to 2 
# To handle tha case for the right what we will do is  : mid+=1 in default and mid-=1 inside right case .These will cancel each other and we get our answer 

class Solution(object):
    def sortColors(self, nums):
        low = 0
        high = len(nums) - 1
        mid = 0

        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
            if nums[mid] == 2:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1
                mid-=1
            mid+=1
                
        return nums


# Bucket sort solution
class Solution(object):
    def sortColors(self, nums):
        # Initialize three buckets for colors 0, 1, and 2
        bucket0, bucket1, bucket2 = 0, 0, 0
        
        # Count the number of occurrences of each color
        for num in nums:
            if num == 0:
                bucket0 += 1
            elif num == 1:
                bucket1 += 1
            elif num == 2:
                bucket2 += 1
        
        # Fill the original list with the sorted colors
        for i in range(bucket0):
            nums[i] = 0
        for i in range(bucket0, bucket0 + bucket1):
            nums[i] = 1
        for i in range(bucket0 + bucket1, bucket0 + bucket1 + bucket2):
            nums[i] = 2
        
        return nums

