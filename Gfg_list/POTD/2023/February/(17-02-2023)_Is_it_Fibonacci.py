
class Solution():
    def solve(self, N, K, GeekNum):
        #your code goes here
        dp1 = []
        sum1 = 0 
        index = 0
        for i in GeekNum:
            sum1+=i 
            dp1.append(sum1)
        first_ptr = 0 
        GeekNum.append(sum1)
        second_ptr = K
        while(second_ptr<N):
            sum1+=GeekNum[-1]
            dp1.append(sum1)
            GeekNum.append(dp1[second_ptr]-dp1[first_ptr])
            second_ptr+=1
            first_ptr+=1
            
    
        return GeekNum[-2]
         
