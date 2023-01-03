








class Solution:	
	def wineSelling(self, Arr, N):
		# code here
        queue_pos = []
        queue_neg = []
        ans = 0 
        for i in range(N):
            if(Arr[i]<0):
                queue_neg.append(i)
            else: 
                queue_pos.append(i)
        ptr1 = 0 
        ptr2 = 0 
        while ptr1<len(queue_pos) and ptr2<len(queue_neg):
            if(abs(Arr[queue_pos[ptr1]])>abs(Arr[queue_neg[ptr2]])):
                ans =ans+ abs(Arr[queue_neg[ptr2]])*(abs(queue_neg[ptr2]-queue_pos[ptr1]))
                Arr[queue_pos[ptr1]] = Arr[queue_pos[ptr1]]+Arr[queue_neg[ptr2]]
                Arr[queue_neg[ptr2]] = 0 
                ptr2+=1
            
            elif(abs(Arr[queue_pos[ptr1]])<abs(Arr[queue_neg[ptr2]])):
                ans = ans+ abs(Arr[queue_pos[ptr1]])*(abs(queue_neg[ptr2]-queue_pos[ptr1]))
                Arr[queue_neg[ptr2]] = Arr[queue_neg[ptr2]]+Arr[queue_pos[ptr1]]
                Arr[queue_pos[ptr1]] = 0
                ptr1+=1
            else :
                ans = ans+ abs(Arr[queue_pos[ptr1]])*(abs(queue_neg[ptr2]-queue_pos[ptr1]))
                Arr[queue_neg[ptr2]] = 0
                Arr[queue_pos[ptr1]] = 0
                ptr1+=1
                ptr2+=1
            # print(ans)
        return ans 




