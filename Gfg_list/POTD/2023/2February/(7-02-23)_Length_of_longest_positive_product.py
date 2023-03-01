
class Solution:
    def maxLength(self,arr,n):
        #code here
        Positive_length = 0
        Negative_length = 0
        ans = 0 

        for i in arr:
            if i==0:
                Positive_length = 0
                Negative_length = 0
            elif i>0:
                Positive_length+=1 
                if Negative_length!=0:
                    Negative_length+=1 
                ans = max(ans, Positive_length)
            else:
                Positive_length , Negative_length = Negative_length , Positive_length 
                Negative_length+=1  
                if Positive_length!=0:
                    Positive_length+=1 
                ans = max(ans , Positive_length)


        return ans 
