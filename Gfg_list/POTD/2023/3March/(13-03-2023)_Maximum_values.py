# // https://practice.geeksforgeeks.org/problems/2d3fc3651507fc0c6bd1fa43861e0d1c43d4b8a1/1






#User function Template for python3
class Solution:
    def maxPossibleValue(self, N, A, B): 
        #code here
        ans = 0
        count_stick = 0
        min_required = 999999999
        for i in range(N):
            unit = (B[i]//2)*2
            count_stick += unit
            ans += (unit*A[i])
            if(unit):
                min_required = min(min_required , A[i])
                #save minimum if not divisiuble by 4 remove it
        if(count_stick%4):
            return ans-(min_required*2)
        return ans 
                
































































