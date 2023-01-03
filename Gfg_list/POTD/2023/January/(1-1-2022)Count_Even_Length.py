import math 

class Solution:
	def compute_value(self, n):
	    MOD_VAL = 1000000000+7
	    def NCR(n,r):
	        func = math.factorial
	        return func(n)//func(r)//func(n-r)
	    return NCR(2*n,n)%MOD_VAL