def countTriplets(self, nums):
    n = len(nums)
    ans1 = 0
    for i in range(n-1):
        for j in range(i+1,n):
            if(nums[j]>nums[i]):
                for k in range(j+1,n):
                    if(nums[k]>nums[j]):
                        ans1+=1
        
    return ans1



def countTriplets(self, nums):
    n = len(nums)
    nge = [0]*n
    for i in range(n-1):
        count1 = 0
        for j in range(i+1,n):
            if nums[j]>nums[i]:
                count1+=1
        nge[i] = count1 
    ans1 = 0

    for i in range(n-2):
        for j in range(i+1,n-1):
            if(nums[j]>nums[i]):
                ans1+=nge[j]
        
    return ans1
    # Code here

