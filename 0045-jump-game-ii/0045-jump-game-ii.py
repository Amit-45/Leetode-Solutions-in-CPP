class Solution(object):
    def jump(self, nums):
        n = len(nums)
        q = deque([(0, 0)])
        visited = set([0])

        while q:
            cur, jumps = q.popleft()
            if cur == n - 1:
                return jumps
            for i in range(cur + 1, min(cur + nums[cur] + 1, n)):
                if i not in visited:
                    visited.add(i)
                    q.append((i, jumps + 1))

        