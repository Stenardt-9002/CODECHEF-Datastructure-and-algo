#User function Template for python3

class Solution:
    def CountWays(self, str):
        # Code here
        MOPD1 = 1000000000+7
        n = len(str)
        if n==1 :
            if (int)(str)>0 and (int)(str)<27:
                return 1
            return 0 
        if str[0]=='0':
            return 0
        dp1 = [0]*n 
        dp1[0] = 1
        if (int)(str[0:2])<27 and (str[1]!='0'):
            dp1[1] = 2
        else:
            dp1[1] = 1
    
        
        for i in range(2,n):
            val = (int)(str[i])
            val2 = (int)(str[i-1:i+1])
            if(val>0):
                dp1[i]+=dp1[i-1]
            if val2<27 and str[i-1]!='0':
                dp1[i]+=dp1[i-2]
            dp1[i] = dp1[i]%MOPD1
        
        return dp1[n-1]%MOPD1
        
