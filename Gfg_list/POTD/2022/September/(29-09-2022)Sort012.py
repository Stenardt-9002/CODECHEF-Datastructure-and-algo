def sort012(self,arr,n):
    # code here
    low1 = 0 
    mid1 = 0
    high = n-1
    while(mid1<=high):
        if(arr[mid1]==0):
            arr[mid1] ,arr[low1] = arr[low1],arr[mid1]
            mid1 = mid1+1
            low1 = low1+1
        elif(arr[mid1]==1):
            mid1+=1
        elif(arr[mid1]==2):
            arr[mid1],arr[high] = arr[high] ,arr[mid1]
            high-=1
        
        