


# https://practice.geeksforgeeks.org/problems/maximum-sum-lcm3025/1


import math


def maxSumLCM (self, n):
    if(n==1):
        return 1
    sqrt = (int)(math.sqrt(n))+1 
    ans1 = 0 
    for i in range(1,sqrt):
        if(n%i==0):
            ans1+=i 
            if(n//i != i):
                ans1+=(n//i)
    return ans1 
    # code here 














