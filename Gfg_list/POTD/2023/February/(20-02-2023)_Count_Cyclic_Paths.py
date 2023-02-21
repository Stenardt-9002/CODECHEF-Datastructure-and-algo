
# https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1





MOD = 1000000007

class Solution:
    def countPaths (self, N):
        # code here 
        if(N==0):
            return 1
    
        dp_cur = [0]*4 
        dp_pre = [0]*4 

        dp_pre[0] = 1 
        prev_Row_Sum = 1 
        for n in range(N):
            cur_row_sum = 0 
            for j in range(4):
                dp_cur[j] = (prev_Row_Sum+MOD-dp_pre[j])%MOD
                cur_row_sum = (cur_row_sum+dp_cur[j])%MOD
            prev_Row_Sum = cur_row_sum 
            dp_pre = dp_cur
        
        return dp_pre[0]



