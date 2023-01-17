

class Solution:
    def nextLargerElement(self,arr,n):
        #code here
        stack_1 = []
        ans = [-1]*n
        stack_1.append(0)
        for i in range(1,n):
            if len(stack_1)==0:
                stack_1.append(arr[i])
            else:
                while len(stack_1)>0 and arr[stack_1[-1]]<arr[i]:
                    ans[stack_1[-1]] = arr[i]
                    stack_1.pop()
                stack_1.append(i)
        return ans 


