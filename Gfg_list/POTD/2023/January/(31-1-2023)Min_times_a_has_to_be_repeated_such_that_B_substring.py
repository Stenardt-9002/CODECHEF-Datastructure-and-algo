
class Solution:
    def minRepeats(self, A, B):
        n = len(A)
        m = len(B)
        ans = 9999
        for i in range(n):
            start = i 
            j = 0 
            while j<m :
                if A[start%n] != B[j]:
                    j==m+1 
                elif j==m-1:
                    count = start//n 
                    ans = min(ans, count)

                j+=1
                start+=1
        if ans==9999:
            return -1
        return ans 

        # code here 












