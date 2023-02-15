#User function Template for python3

class Solution:
    def countSubArrayProductLessThanK(self, a, n, k):
        #Code here
        if k<=1:
            return 0 
        product_uptil_now = 1 
        ans = 0
        i = 0
        for j in range(n):
            product_uptil_now *= a[j]
            while product_uptil_now>=k:
                product_uptil_now = product_uptil_now//a[i]
                i+=1
            ans+=(j-i+1)
        return ans 
            
            
            
        
    
    
    
    
