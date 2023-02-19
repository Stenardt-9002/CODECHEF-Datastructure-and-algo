
class Solution:
    def goodStones(self, n, arr) -> int:
        #code here
        visited = [-1]*n 
        def dfs_u(src):
            if src>=n or src<0:
                return 1 
            if visited[src]!=-1:
                return visited[src] 
            visited[src] = 0 
            visited[src] = dfs_u(src+arr[src])
            return visited[src]
        for i in range(n):
            if visited[i]==-1:
                visited[i] = dfs_u(i)
        return sum(visited)
    