

# https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1



#User function Template for python3

class Solution:
    def inSequence(self, A, B, C):
        # code here
        if C==0:
            return (int)(A==B) 
        return (int)(((B-A)%C==0 and((C>0 and B>=A)or(C<0 and B<=A))))
