# https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day14/problem/stock-span-problem-1587115621



def calculateSpan(self,a,n):

    ans1 = [0]*n
    stack_var = []
    stack_var.append(0)
    ans1[0] = 1
    for i in range(1,n):
        while(len(stack_var)>0 and a[stack_var[-1]]<=a[i]):
            stack_var.pop()
        if len(stack_var)==0:
            ans1[i] = i+1 
        else:
            ans1[i] = i-stack_var[-1]

        stack_var.append(i)


    return ans1 
    #code here





















