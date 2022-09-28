# https://www.geeksforgeeks.org/factorial-large-number/




def multiply_1(lis_t , int_mul):
    new_list = []
    lis_t.reverse()
    carry = 0 
    for data in lis_t:
        val = data*int_mul + carry 
        carry = val//10 
        new_list.append(val%10)

    while(carry!=0):
        new_list.append(carry%10)
        carry = carry//10 
    
    new_list.reverse()
    return new_list



def factorial(self, N):
    res = [1]
    if(N==0 or N==1):
        return res 
    
    for i in range(2,N+1):
        res = multiply_1(res , i)

    return res 
        #code here
