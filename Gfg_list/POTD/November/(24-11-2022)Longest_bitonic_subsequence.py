
# https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


def LongestBitonicSequence(nums):
    n = len(nums)
    dp1 = [1]*n
    dp2 = [1]*n 
    for i in range(1,n):
        for j in range(i):
            if(nums[j]<nums[i] and dp1[i]<dp1[j]+1):
                dp1[i] = dp1[j]+1

    for i in range(n-2,-1,-1):
        for j in range(n-1,i,-1):
            if(nums[j]<nums[i] and dp2[i]<dp2[j]+1):
                dp2[i] = dp2[j]+1

    sum1 = dp1[0]+dp2[0]-1
    for i in range(1,n):
        sum1 = max(sum1 , dp1[i]+dp2[i]-1)
    return sum1 

    
    # Code here
# print(LongestBitonicSequence([1,2,5,3,2]))
print(LongestBitonicSequence([15,6,2,1,29,7,16,2,29,29,19,7,6,25,19]))



