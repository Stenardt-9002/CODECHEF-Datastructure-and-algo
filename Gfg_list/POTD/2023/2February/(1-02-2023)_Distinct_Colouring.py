class Solution:
    def distinctColoring (self, N, r, g, b):
        
        # code here 
        arr1 = [0]*3
        arr2 = [0]*3
        arr1[0] = r[0]
        arr1[1] = g[0]
        arr1[2] = b[0]
        for i in range(1,N):
            arr2[0] = r[i]+min(arr1[1],arr1[2]);
            arr2[1] = g[i]+min(arr1[0],arr1[2]);
            arr2[2] = b[i]+min(arr1[0],arr1[1]);
            
            arr1[0] = arr2[0];
            arr1[1] = arr2[1];
            arr1[2] = arr2[2];
            
        return min(arr1[0],arr1[1],arr1[2]);