# https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day15/problem/8c8f95810b05b4cab665f2997d36991bd58308a2





def Reduced_String(self, k, s):
    if(k==1):
        return ""
    stack_1 = []
    for i in s :
        if(len(stack_1)==0) or stack_1[-1][0]!=i:
            stack_1.append([i , 1])
        elif stack_1[-1][0]==i:
                freq = stack_1[-1][1]+1 
                stack_1.pop()
                if(freq < k):
                    stack_1.append([i,freq])
    ans1 = ""
    for i in range(len(stack_1)) :
        char_var = stack_1[i][0]
        freq = stack_1[i][1]
        while(freq>0):
            freq-=1 
            ans1+=char_var 

                
    return ans1
    # Your code goes here
    # return the reduced string





