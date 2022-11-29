


def countSetBits(n):
    count = 0
    while (n):
        count += n & 1
        n >>= 1
    return count
 
def compare_val(arr1 , arr2):#true if arr1 is greater else false (smaller and equal)
    length_var = len(arr1)
    for i in range(length_var-1,-1,-1):
        if(arr1[i]!=arr2[i]):
            if(arr1[i]==1):
                return True 
            else :
                return False
    return True


def recursive_fun(dp1 , num_bits , set_bits,original_value_array ,ans1 ):
    if(set_bits==0):
        # print(dp1)
        if(compare_val(dp1,original_value_array)==False):
            # print(original_value_array)

            # print(dp1)
            ans1[0]+=1
        return 
    if(num_bits<1):
        # print(dp1)
        return 
    dp1[num_bits-1] = 1
    recursive_fun(dp1 ,num_bits-1 , set_bits-1 , original_value_array , ans1 )
    dp1[num_bits-1] = 0
    recursive_fun(dp1 ,num_bits-1 , set_bits , original_value_array , ans1 )



# def count ( N):
#     if(N==1):
#         return 0
#     num_bits = N.bit_length()
#     set_bits = countSetBits(N)
#     if(num_bits==set_bits):
#         return 0
#     dp1 = [0]*num_bits 
#     original_value_array = [0]*num_bits 
#     N_copy = N 
#     for i in range(num_bits):
#         original_value_array[i] = N_copy%2 
#         N_copy = N_copy//2 
#     ans1 = [0] 
#     recursive_fun(dp1 , num_bits,set_bits , original_value_array , ans1)
#     # bruh(ans1)
#     return ans1[0] 
    

    # code here 


def count ( N):
    if(N==1):
        return 0
    bits = 0
    cnt = 0 
    v1 = []
    ones = []
    N_copy = N 
    while(N_copy):
        if(N_copy%2==1):
            cnt+=1 
            ones.append(cnt)
            v1.append(bits)
        bits+=1
        N_copy = N_copy//2 
    dp1 = [ [0]*(bits+1) ]*(bits+1)
    dp1[0][0] = 1 
    for i in range(1,bits+1):
        for j in range(0,i+1):
            if(j==0 or j==i):
                dp1[i][j] = 1
            else:
                dp1[i][j]+=(dp1[i-1][j]+dp1[i-1][j-1])

    ans1 = 0 
    for i in range(len(ones)):
        ans1+=dp1[v1[i]][ones[i]]
    # bruh(ans1)
    return ans1 
    

    # code here 



























def ncr_fun(n,r):
    if(r>n):
        return 0 

    ans = 1 
    for i in range(r):
        ans *= (n-i)
        ans /= (i+1)

    return ans 


def get_sol(n,k,i):
    if(i==0):
        return 0 
    mask = 1<<i 
    ans1 = 0
    if((n&mask)==0):
        ans1 = get_sol(n,k,i-1)
    else:
        sol1 = get_sol(n,k-1,i-1)
        sol2 = ncr_fun(i,k)
        ans1 = sol1+sol2 

    return ans1 




def count ( N):
    if(N==1):
        return 0
    set_bits = 0 

    N_copy = N 
    while(N_copy):
        if(N_copy%2==1):
            set_bits+=1 
        N_copy = N_copy//2 
    ans1 = get_sol(N,set_bits,63)
    # bruh(ans1)
    return ans1 
    

    # code here 





print(count(8))
# print(count(10))

