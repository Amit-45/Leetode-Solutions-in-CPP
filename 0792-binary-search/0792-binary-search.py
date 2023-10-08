#Binary search (iterative):
#TC: O(log n)
#First thing that the input array is sorted 
#Target value can exist anywhere within the array or might not exist at all
#We are considering the entire array. How are we going to do that? We take two pointers l and r that allows us to consider the whole array
#l= pointer at index 0 or leftmost index, r= pointer at last index or rightmost index : l, r = 0, len(nums) - 1
#We will do it until any possibility is left or we have found the result. In other words we can tell is we have to do it till we have no search space. So what we will do is : while l<=r 
#Then find mid. If mid is == target why to search more. Simply return the answer's index. 
#If element is less than target : Target is in the right half : Shift l 
#else : Target is in the left half  : Shift r 


class Solution(object):
    def search(self, nums, target):
        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] == target:
                return m
            elif nums[m] <target:
                l = m + 1
            else:
                r = m - 1      
        return -1
#Binary search (recursive):

# class Solution(object):
#     def recursiveBS(self,nums,l,r,target):
#         #base case 
#         if l>r: 
#             return -1
#         m=(l+r)//2
#         if target==nums[m]:
#             return m
#         elif nums[m] <target:
#            return self.recursiveBS(nums,m+1,r,target)
#         else:
#             return self.recursiveBS(nums,l,m-1,target)

#     def search(self, nums, target):
#         l, r = 0, len(nums) - 1
#         return self.recursiveBS(nums,l,r,target)
  
