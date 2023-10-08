#Approach: (Searching in array using BS normal)  TC:
#The question specifies that each row in the given matrix is sorted. Therefore, to determine if the target is present in a specific row, we don’t need to search column by column. Instead, we can efficiently use the binary search algorithm.
#If the target lies between the first and last element of the row, i (i.e. matrix[i][0] <= target && target <= matrix[i][m-1]), we can conclude that the target might be present in that specific row.
# Once we locate the potentially relevant row containing the ‘target’, we need to confirm its presence. To accomplish this, we will utilize the Binary search algorithm, effectively reducing the time complexity.

#Code:
#We will use a loop(say i) to select a particular row at a time : for i in range(n):
# Next, for every row, i, we will check if it contains the target.
# If matrix[i][0] <= target && target <= matrix[i][m-1]: If this condition is met, we can conclude that row i has the possibility of containing the target.
# So, we will apply binary search on row i, and check if the ‘target’ is present. If it is present, we will return true from this step. Otherwise, we will return false. : return self.binarySearch(matrix[i], target)
# Otherwise, after completing the traversal, we will return false.
#Then simply complete the binary search function

# class Solution(object):
#     def binarySearch(self, nums, target):
#         n = len(nums)
#         low, high = 0, n - 1

#         while low <= high:
#             mid = (low + high) // 2
#             if nums[mid] == target:
#                 return True
#             elif nums[mid]< target:
#                 low = mid + 1
#             else:
#                 high = mid - 1
#         return False

#     def searchMatrix(self, matrix, target):
#         n = len(matrix)
#         m = len(matrix[0])

#         for i in range(n):
#             if matrix[i][0] <= target <= matrix[i][m - 1]:
#                 return self.binarySearch(matrix[i], target)
#         return False
#Flattening an array approach:
class Solution(object):
    def binarySearch(self, nums, target,m):
        n = len(nums)
        low, high = 0, n - 1

        while low <= high:
            mid = (low + high) // 2
            row = mid // m
            col = mid % m
            if nums[mid] == target:
                return True
            elif nums[mid]< target:
                low = mid + 1
            else:
                high = mid - 1
        return False

    def searchMatrix(self, matrix, target):
        n = len(matrix)
        m = len(matrix[0])

        for i in range(n):
            if matrix[i][0] <= target <= matrix[i][m - 1]:
                return self.binarySearch(matrix[i], target,m)
        return False

