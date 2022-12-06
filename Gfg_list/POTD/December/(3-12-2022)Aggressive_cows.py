# https://practice.geeksforgeeks.org/problems/aggressive-cows/1



# def leastgreater(a,low, high, key):
#     ans = -1
#     while (low <= high):
#         mid = low + ((high - low + 1) // 2)
#         midVal = a[mid]
#         if (midVal < key):
#             low = mid + 1;
#         elif (midVal >= key) :
#             ans = mid;
#             high = mid - 1;

#     return ans
 



# def allowed(stalls , n , k , distance):
#     i = 0
#     j = 1
#     k-=1 
#     while i<n and j<n and k>0 :
#         j = leastgreater(stalls , i , n-1 , stalls[i]+distance )
#         # print("Debug " , distance , j)
#         if(j==-1):
#             j = n 
#         else :
#             k-=1 
#             i = j

#     return k<=0


class Solution:
    
    def allowed(self,stalls , n , k , distance):
        i = 0
        j = 1
        k-=1 
        while i<n and j<n and k>0 :
            if(stalls[j]-stalls[i]<distance):
                j+=1
            else :
                k-=1 
                i = j
        return k<=0

    def solve(self,n,k,stalls):
        l = 1 
        r = max(stalls)
        ans = -1
        stalls.sort()
        while(l<=r):
            mid = l+(r-l)//2 
            if (self.allowed(stalls , n , k , mid)):
                ans = mid 
                l = mid+1 
            else:
                r = mid-1 
        # print(ans)
        return ans 
        pass

stalls = [1,2,4,8,9]
k = 3
n = len(stalls)
stalls = [10,1,2,7,5]
k = 3
n = len(stalls)
# print(solve(n,k,stalls))
