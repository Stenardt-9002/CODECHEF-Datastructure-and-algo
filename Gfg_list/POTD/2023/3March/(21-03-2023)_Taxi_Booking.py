class Solution:
    def minimumTime(self, N : int, cur : int, pos : List[int], time : List[int]) -> int:
        ans = 9999999999
        for i in range(N):
            ans = min(ans , abs(pos[i]-cur)*time[i] )
        return ans
        # code here
        
