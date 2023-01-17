# // https://practice.geeksforgeeks.org/problems/649205908e04ac00f303626fa845261318adfa8f/1






from typing import List
from functools import cmp_to_key


class Job:
    def __init__(self , start , end , profit ):
        self.start = start 
        self.end = end 
        self.profit = profit 
def Jobcomparator(s1 , s2):
    return s1.finish<s2.finish 


def lastSubset(arr,i):
    for j in range(i-1 , -1 , -1):
        if arr[j].finish<=arr[i-1].start:
            return j 
    return -1


class Solution:
    def maximum_profit(self, n : int, intervals : List[List[int]]) -> int:
        # code here
        arr = []
        for i in intervals:
            arr.append(Job(i[0],i[1],i[2]))
        arr = sorted(arr , key=cmp_to_key(Jobcomparator))
        dp1 = [None]*n 
        dp1[0] = arr[0].profit 
        for i in range(1,n):
            first_porfit = arr[i].profit 
            preindex = lastSubset(arr,i)
            if preindex!=-1:
                first_porfit+=dp1[preindex]
            dp1[i]=max(first_porfit , dp1[i-1])
        return dp1[n-1]
    
        









































