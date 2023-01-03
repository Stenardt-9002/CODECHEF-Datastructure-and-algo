# https://practice.geeksforgeeks.org/problems/lcm-triplet1501/1
class Solution:
    def lcmTriplets(self,N):
        if(N<=2):
            return N
        if(N%2==1):
            return N*(N-1)*(N-2)
        else :
            if(N%3==0):
                return (N-1)*(N-2)*(N-3)
            return N*(N-1)*(N-3)
        #code here





