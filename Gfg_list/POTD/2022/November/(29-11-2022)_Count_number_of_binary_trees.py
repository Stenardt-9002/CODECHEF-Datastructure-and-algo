# https://practice.geeksforgeeks.org/problems/count-the-number-of-full-binary-trees2525/1

def binary_search(arr, low, high, x):
    if high >= low:
 
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        return -1
class Solution:
    def numoffbt(self, arr, n):
        MOD1 = 1000000007
        arr = list(set(arr))
        n = len(arr)
        diction_dp = {}
        for i in range(n):
            diction_dp[arr[i]] = 1 
        arr.sort()
        for i in range(n):
            for j in range(i):
                if(arr[i]%arr[j]==0):
                    quotient = arr[i]//arr[j] 
                    # if(arr[i]==90):
                    #     print("debug ",quotient)
                    if(binary_search(arr, 0 , len(arr)-1 , quotient)!=-1):
                        diction_dp[arr[i]]+=(diction_dp[arr[j]]*diction_dp[quotient] )
                        diction_dp[arr[i]] = diction_dp[arr[i]]%MOD1
        
        sum1 = 0 
        # print(diction_dp)
        for i in diction_dp.values():
            sum1 = sum1+i
            sum1 = sum1%MOD1
    
        return sum1 
     # Your code goes here



# 14
class Solution:
    def numoffbt(self, arr, n):
        MOD1 = 1000000007
        max_var = max(arr)
        min_var = min(arr)
        dp1 = [0]*(max_var+1)
        for i in arr:
            dp1[i] = 1
        ans1 = 0 
        for i in range(min_var , max_var+1):
            if(dp1[i]!=0):
                j = 2*i
                while (j<=max_var and (j//i)<=i):
                    if dp1[j]!=0:
                        dp1[j]+=(dp1[i]*dp1[j//i])
                        if(j//i!=i):
                            dp1[j]+=(dp1[i]*dp1[j//i])
                    j+=i 
                ans1+=dp1[i]
                ans1 = ans1%MOD1
        return ans1                
     # Your code goes here
arr = [9,91,115,8,67,9,10,21,7,109,78,90,71,104]
arr.sort()
print(arr)