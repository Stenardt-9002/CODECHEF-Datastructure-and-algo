class Solution:
    
    #Function to remove pair of duplicates from given string using Stack.
    def removePair(self,s):
        # code here
        stack_1 = []
        for c in s:
            if len(stack_1)>0 and stack_1[-1]==c:
                stack_1.pop(-1)
            else:
                stack_1.append(c)
        ans = ""
        for c in stack_1:
            ans+=c
        if ans=="":
            return -1
        return ans
                