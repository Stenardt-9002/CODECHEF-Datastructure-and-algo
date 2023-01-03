class Solution:
    def maxDistance (self, arr, n) : 
        #Complete the function
        max1 = -9999
        max2 = -9999
        min1 = 9999
        min2 = 9999
        for i in range(n):
            max1 = max(max1,arr[i]+i)
            min1 = min(min1 ,arr[i]+i)
            max2 = max(max2,arr[i]-i)
            min2 = min(min2 ,arr[i]-i)
        return max(max1-min1 , max2-min2)