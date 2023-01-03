class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        new_Array = [capacity[i]-rocks[i] for i in range(len(capacity))]
        new_Array.sort()
        ans = 0

        while (additionalRocks-new_Array[ans]>0):
            additionalRocks-=new_Array[ans]
            ans+=1
            
        return ans 