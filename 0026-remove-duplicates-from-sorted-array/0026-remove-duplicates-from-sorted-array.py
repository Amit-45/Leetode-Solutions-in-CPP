#we must start at index 1 . So left pointer is at index 1
#Right pointer will be iterating the whole input array 
#Instead of starting at 0, i will start at 1 because both left and right pointer will start at 1
#We will simply check if element is unique by comparing with prev element
#If the value is unique we put it at place of left pointer 
#We only increment the left pointer if we do the opeartion.Otherwise we don't increment the left pointer 
class Solution(object):
    def removeDuplicates(self, nums):
        l=1
        for r in range(1,len(nums)):
            if nums[r-1]!=nums[r]:
                nums[l]=nums[r]
                l+=1
        return l




 