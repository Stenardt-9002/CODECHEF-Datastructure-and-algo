# https://practice.geeksforgeeks.org/problems/e0059183c88ab680b2f73f7d809fb8056fe9dc43/1





class Solution:
    def countPairs (self, n, arr, k):
        list_1 = [0]*k 
        for i in arr:
            list_1[i%k]+=1
        ans_1 = 0 
        for i in list_1:
            ans_1+=(((i)*(i-1))//2)
        return ans_1
        # code here

















