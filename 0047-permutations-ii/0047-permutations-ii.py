class Solution(object):
    def permuteUnique(self, nums):
        def solve(idx, nums):
            # GOAL / Base case
            if idx == n-1:
                ans.append(nums)
                return

            for i in range(idx, n):
                if i > idx and nums[i] == nums[idx]:
                    continue  # Skip duplicates

                if i > idx:
                    nums[i], nums[idx] = nums[idx], nums[i]
                    solve(idx + 1, nums[:]) 
                    # nums[i], nums[idx] = nums[idx], nums[i]  # Swap back to the original state
                else:
                    solve(idx + 1, nums[:])

        n = len(nums)
        ans = []
        nums.sort()  # Sort the input list to group duplicates
        solve(0, nums)
        return ans
