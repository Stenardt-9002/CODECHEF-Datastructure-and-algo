#User function Template for python3
MOD = 1000000007
class Solution:
    def uniquePaths(self, n, m, grid):
        dp1 = []
        for i in range(n) :
            temp = [0]*m 
            dp1.append(temp)
        dp1[0][0] = grid[0][0]
        for i in range(1,n):
            if grid[i][0]==1:
                dp1[i][0]+=dp1[i-1][0]
        for i in range(1,m):
            if grid[0][i]==1:
                dp1[0][i]+=dp1[0][i-1]
                
        for i in range(1,n):
            for j in range(1,m):
                if grid[i][j]==1:
                    dp1[i][j]+=(dp1[i-1][j]+dp1[i][j-1])
                    dp1[i][j] = dp1[i][j]%MOD
        
        return dp1[n-1][m-1]
        