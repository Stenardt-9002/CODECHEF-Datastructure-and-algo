class Solution:
    def checkCompressed(self, S, T):
        # code here 
        i = 0 
        j = 0
        while j<len(T):
            charac = T[j]
            if charac.isdigit():
                num = (int)(charac)
                while j+1<len(T) and T[j+1].isdigit():
                    num*=10
                    num = num+(int)(T[j+1])
                    j+=1

                i+=num
            elif S[i]==charac:
                i+=1
            else :
                return 0
            if(i>len(S)):
                return 0
            j+=1
        return 1



