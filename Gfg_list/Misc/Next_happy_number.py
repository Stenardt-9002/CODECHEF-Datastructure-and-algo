
class Solution:


    def square_sum(self , num):
        sqaure_sum1 = 0
        while num!=0:
            sqaure_sum1+=((num%10)**2)
            num//=10 
        return sqaure_sum1

    def check_indv_num(self,num):
        slow_ptr = num 
        fast_ptr = num 
        while True:
            slow_ptr = self.square_sum(slow_ptr)
            fast_ptr = self.square_sum(self.square_sum(fast_ptr))
            if(slow_ptr==fast_ptr):
                break 
        return slow_ptr==1 
    def nextHappy (self, N):
        for i in range(N+1 ,N+100):
            if self.check_indv_num(i):
                return i 

        return -1
        # code here

obj1 = Solution()
print(obj1.square_sum(10))


