# https://practice.geeksforgeeks.org/problems/a7a4da81b20f4a05bbd93f5786fcf7478298f4f5/1







def hcf_u(L , B):
    if B==0:
        return L ;
    
    if(B>L):
        return hcf_u(B,L)
    return hcf_u(B ,L%B )
    
    





class Solution:
    def minimumSquares(self, L, B):
        
        # code here
        hcf_val = hcf_u(L,B)
        return [(int)((L*B)/(hcf_val*hcf_val)) , hcf_val]




