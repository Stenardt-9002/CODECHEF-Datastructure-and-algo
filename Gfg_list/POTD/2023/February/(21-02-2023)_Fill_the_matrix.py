# https://practice.geeksforgeeks.org/problems/2145720aebf8ea0b07f76b17217b3353a0fbea7f/1
class Solution:
    def minIteration(self, N, M, x, y):
        #code here
        if(N==1 and M==1):
            return 0 
    
        return max(x+y-2,N-x+y-1,x-1+M-y , N-x+M-y)

