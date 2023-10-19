
class Solution(object):
    def __init__(self):
        self.ans = []

    def subsets(self, nums):
        def sub(i, temp):
            if i == len(nums):
                self.ans.append(temp[:])  # Append a copy of 'temp' to the result
                return

            sub(i + 1, temp)  # Exclude the current element
            temp.append(nums[i])  # Small work: Include the current element
            sub(i + 1, temp)
            temp.pop()  # Backtrack by removing the current element

        temp = []
        sub(0, temp)
        return self.ans      