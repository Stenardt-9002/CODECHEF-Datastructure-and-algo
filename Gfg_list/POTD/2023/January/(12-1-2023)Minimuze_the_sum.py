import heapq
class Solution:
    def minimizeSum(self, N, arr):
        # Code here
        heapq.heapify(arr)
        sum_1 = 0
        while(len(arr)>1):
            ele1 = heapq.heappop(arr)
            ele2 = heapq.heappop(arr) 
            sum_1+=(ele1+ele2)
            heapq.heappush(arr,ele1+ele2)
        return sum_1
            
            