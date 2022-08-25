# https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/add-binary-strings3805

class Solution:
	def addBinary(self, A, B):
	    max_len = max(len(A),len(B))
        A = A.zfill(max_len)
        B = B.zfill(max_len)

        ans1 = ""
        carry = 0 
        for i in range(max_len-1 ,-1 ,-1):
            an = carry 
            an+=1 if A[i]=='1' else 0 
            an+=1 if B[i]=='1' else 0 
            ans1 = ('1' if an%2==1 else '0')+ans1 
            carry = 0 if an<2 else 1 
        if carry!=0 : 
            ans1 = '1'+ans1 
        
        ans1 = ans1.zfill(max_len)
        i = 0 
        while(i<len(ans1) and ans1[i]=='0'):
            i+=1
        if(i==len(ans1)):
            return "0"
        ans1 = ans1[i:]
        return ans1 
            
        



