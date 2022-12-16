# https://practice.geeksforgeeks.org/problems/f04fd67b26b4828b6180715d8b1700426b637247/1




class Solution:
    def verify(self ,cur_sum , arr , N , K ):
        count_1 = 1 
        _sum = 0 
        i = 0
        while i<N:
            if arr[i]>cur_sum:
                return False 
            if _sum+arr[i]<=cur_sum:
                _sum+=arr[i]
                i+=1
            else:
                _sum = 0
                count_1+=1 
            if count_1>K:
                return False 
            
        return count_1<=K



    def splitArray(self, arr, N, K):
        low_sum = max(arr)
        high_sum = 0 
        for i in arr:
            high_sum+=i 
        if(N==K):
            return low_sum
        subarray_sum = 0 
        while (low_sum<=high_sum):
            mid = (low_sum+high_sum)//2
            if (self.verify(mid , arr , N , K)):
                subarray_sum = mid 
                high_sum = mid-1
            else:
                low_sum = mid+1 
        return subarray_sum 
        # code here 

