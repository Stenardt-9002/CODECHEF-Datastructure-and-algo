# https://practice.geeksforgeeks.org/problems/build-the-smallest2841/1







class Solution:
    def buildLowestNumber(self, S,N):
        num = S 
        n = len(num)
        mystack = []
        for c in num:
            while (len(mystack) > 0 and k > 0 and ord(mystack[len(mystack)-1]) > ord(c)):
                mystack.pop()
                k -= 1
    
            if len(mystack) > 0 or c != '0' :
                mystack.append(c)
    
        while len(mystack) > 0 and k:
            mystack.pop()
            k -= 1
        if len(mystack) == 0:
            return "0"
    
        while(len(mystack) > 0):
            num = num.replace(num[n - 1],mystack[len(mystack) - 1])
            mystack.pop()
            n -= 1
        return num[n:]

        # code here











