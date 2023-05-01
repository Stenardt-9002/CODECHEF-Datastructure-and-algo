# // https://practice.geeksforgeeks.org/problems/1ccf56f107bcb24242469ea45c02f852165a2184/1



from typing import List


class Solution:
    def minimumInteger(self, N : int, A : List[int]) -> int:
        # code here
        sum1 = 0
        for i in A:
            sum1+=i 
        mean_1 = sum1/N 
        ans = 99999999999
        for i in A:
            if i>=mean_1 and i<ans:
                ans = i 
        return ans 
    



























