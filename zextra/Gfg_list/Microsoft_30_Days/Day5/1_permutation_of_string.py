# https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/permutations-of-a-given-string2041

def permute(S , l1 ,r1,ans1):
    if(l1==r1):
        ans1.append(''.join(S))
    else :
        for i in range(l1,r1):
            S[l1] , S[i] = S[i],S[l1]
            permute(S,l1+1 , r1 , ans1)
            S[l1] , S[i] = S[i],S[l1]



class Solution:
    def find_permutation(self, S):
        # Code here
        ans1 = []
        n = len(S)
        S = list(S)
        permute(S , 0 , n,ans1)
        ans1 =set(ans1)
        ans1 = list(ans1)
        ans1.sort()
        return ans1 
        






