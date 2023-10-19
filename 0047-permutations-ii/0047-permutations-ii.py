class Solution:
    def permuteUnique(self, nums):
        res=[]
        n=len(nums)
        def dfs(path,k):
            if k==n-1:
                res.append(path)
                return
            for i in range(k,n):
                if i>k and path[i]==path[k]:
                    continue
                if i>k:
                    path[i],path[k]=path[k],path[i]
                    dfs(path[:],k+1)
                    #path[i],path[k]=path[k],path[i]
                elif i==k:
                    dfs(path[:],k+1)
        nums=sorted(nums)       
        dfs(nums,0)
        return res