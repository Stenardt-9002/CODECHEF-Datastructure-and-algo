# // https://practice.geeksforgeeks.org/problem-of-the-day




class Solution():
    def solve(self, N, A):
        #your code here
        n = N-1
        while A[n]==9:
            n-=1
        return n+1
        
