#Initially maintain a k pointer pointing to 0 that will tell at what position the element needs to be 
#Iterate the input array using pointer i
#if we see a non 2 value : we put in place of k pointer
#If we see a 2 character: ignore because we need to bring only non 2 characters to the beginning

class Solution(object):
    def removeElement(self, nums, val):
        k=0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k]=nums[i]
                k+=1
        return k


