

def recursive_func(arr , n):
    returnlist = []
    for i in range(n):
        returnlist.append(arr[i])

    return returnlist 




def UniquePartitions(self, n):
    arr = [0]*n 
    k_val = 0 
    arr[k_val] = n 
    answer = []
    while True :
        answer.append(recursive_func(arr,k_val+1))
        rem_val = 0
        while k_val>=0 and arr[k_val] == 1:
            rem_val += arr[k_val]
            k_val-=1 

        if(k_val<0):
            return answer 

        arr[k_val]-=1 
        rem_val+=1 
        while rem_val>arr[k_val]:
            arr[k_val+1]  = arr[k_val]
            rem_val = rem_val-arr[k_val]
            k_val+=1 


        arr[k_val+1] = rem_val 
        k_val+=1 



    

		# Code here
