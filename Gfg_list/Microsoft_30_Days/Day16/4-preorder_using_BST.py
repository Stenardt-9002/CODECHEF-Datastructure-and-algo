class Solution:
    def canRepresentBST(self, arr, N):
        stack_1 = []
        cur_root = -99999 
        for i in arr:
            if(i<cur_root):
                return False 
            while (len(stack_1)>0 and stack_1[-1]<i):
                cur_root = stack_1.pop()
            
            stack_1.append(i)
        return True 

        # code here

