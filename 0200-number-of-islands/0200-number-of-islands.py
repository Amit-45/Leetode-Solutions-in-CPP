#I will start from first cell o to no. of rows
#I will start from first cell o to no. of columns
#Then I will take a visited array of boolean type visited arr=[r][c]
#Now I will check if my matrix is starting from land [or] 1(there is no point of starting from 0)
# And along with that is land is not visited
#Then I will simply do a dfs
#And from that particular cell I will try to traverse all the adjacent nodes 
#Then I will increase the no. of components by doing islands++
#At last i will return the number of comnnected components
# Till now code:-
# class Solution(object):
#     def numIslands(self, grid):
#         islands = 0
#         for r in range(len(grid)):
#             for c in range(len(grid[0])):
#                 if grid[r][c] == '1':
#                     dfsdfs(i, j, visited, grid)
#                     islands += 1
#                    
#         return islands

class Solution(object):
    def numIslands(self, grid):
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for _ in range(n)]
        islands = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.dfs(i, j, visited, grid)
                    islands += 1

        return islands

    def dfs(self, i, j, visited, grid):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0' or visited[i][j]:
            return

        visited[i][j] = True

        # Explore adjacent cells
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dir_i, dir_j in directions:
            self.dfs(i + dir_i, j + dir_j, visited, grid)




        