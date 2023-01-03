import math 
class Solution:
    def threeDivisors(self, query, q):
        
        max_val = max(query)
        max_val = (int)(math.sqrt(max_val))
        prime_nu_list = [True]*(max_val+1)
        # print(prime_nu_list)
        i = 2

        while ((i*i)<=max_val) :
            # print(i)
            if prime_nu_list[i]:
                for j in range(i*i,max_val+1,i):
                    prime_nu_list[j] = False 
            i+=1
        ans1 = []
        for i in query:
            count = 0 
            sqrt_v = (int)(math.sqrt(i)+1)
            for i in range(2,sqrt_v):
                if prime_nu_list[i]:
                    count+=1 
            ans1.append(count)

        return ans1 

		# code here


obj1 = Solution()
print(obj1.threeDivisors([6,10],2))

