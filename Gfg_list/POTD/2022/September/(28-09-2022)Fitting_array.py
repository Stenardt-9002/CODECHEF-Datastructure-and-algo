def isFit (self,arr, brr, n) : 
    arr.sort()
    brr.sort()
    for i in range(n):
        if(brr[i]<arr[i]):
            return False 
    
    return True
    #Complete the function

