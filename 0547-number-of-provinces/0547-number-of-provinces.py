# -----Alterative solution (riddhi)--------------
class Solution:
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        visited = [False] * n
        provinces = 0

        for i in range(n):
            if not visited[i]:
                provinces += 1
                self.dfs(i, isConnected, visited)

        return provinces

    def dfs(self, node, isConnected, visited):
        visited[node] = True
        for neighbor in range(len(isConnected)):
            if isConnected[node][neighbor] == 1 and not visited[neighbor]:
                self.dfs(neighbor, isConnected, visited)
