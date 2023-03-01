
import sys
sys.setrecursionlimit(150000)

class Solution():
    def largestSumCycle(self, N, Edge):
        #your code goes here

        visited = [False]*N 
        dp_sum = [-1]*N 
        ans = [0]
        def dfs_u( src , cur_sum ):
            # global ans 
            if(dp_sum[src]!=-1):
                ans[0] = max(ans[0] , cur_sum-dp_sum[src]+src)
                return 
            if visited[src]:
                return 
            visited[src] = True 
            dp_sum[src] = cur_sum+src 
            if Edge[src]!=-1:
                dfs_u(Edge[src] , cur_sum+src)
            
            dp_sum[src] = -1
        
        for i in range(N):
            if not visited[i]:
                dfs_u(i , 0)
        return ans[0]



s1 = Solution()
# print(s1.largestSumCycle(4,[1,2,3,2]))
n = int(input())
list_1 = list(map(int,input().split()))


print(s1.largestSumCycle(n,list_1))




