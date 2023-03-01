from bisect import bisect_left 
class Solution:
    def removeStudents(self, H, N):
        # code here
        dp1 = [H[0]]
        for i in range(1,N):
            if H[i]>dp1[-1]:
                dp1.append(H[i])
            else:
                dp1[bisect_left(dp1,H[i])] = H[i]
        return N-len(dp1)



#{ 