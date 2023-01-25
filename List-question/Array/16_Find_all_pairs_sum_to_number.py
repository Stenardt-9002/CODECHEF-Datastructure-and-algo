class Solution:
    def getPairsCount(self, arr, n, k):
        # code here
        pos_arr = [0]*(k+1)
        for i in arr:
            if(i<=k):
                pos_arr[i]+=1
        limit = k//2 if k%2==1 else (k//2)-1
        ans = 0
        for i in range(limit+1):
            ans+=(pos_arr[i]*pos_arr[k-i])
        if k%2==0:
            ans+=((pos_arr[k//2]*(pos_arr[k//2]-1))/2)
        return (int)(ans)
        
                