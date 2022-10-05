
class Solution:
    def catchThieves(self, arr, n, k): 
        police_arr = []
        thieves_arr = []
        for i in range(n):
            if(arr[i]=='P'):
                police_arr.append(i)
            else :
                thieves_arr.append(i)
        ans1 = 0
        i = 0 
        r = 0
        while i<len(thieves_arr) and r<len(police_arr):
            if(abs(thieves_arr[i]-police_arr[r])<=k):#is in range
                ans1+=1 ;i+=1 ;r+=1 ;
            elif thieves_arr[i]<police_arr[r]:
                i+=1 ;#thieves are out of range 
            else:
                r+=1 ;# get police in range 


        return ans1 
        # code here 