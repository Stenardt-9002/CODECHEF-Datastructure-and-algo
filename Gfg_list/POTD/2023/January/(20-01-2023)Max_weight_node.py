#User function Template for python3

class Solution():
    def maxWeightCell(self, N, Edge):
        #your code goes here
        if(N==1):
            return 0 
        list_1 = [0]*N 
        for i in range(N):
            if Edge[i]!=-1:
                list_1[Edge[i]]+=i
        index = 0
        ans = 0
        for i in range(N):
            if(list_1[i]>=ans):
                ans = list_1[i]
                index = i
        return index
        # for i in Edge:
        #     if i!=-1:
        #         list_1[i]+=1

        # queue_1 = []
        # for i in range(len(list_1)):
        #     if list_1[i]==0:
        #         queue_1.append(i)
        # cur_nodes = 0

        # while len(queue_1)>0:
        #     cur_nodes+=1
        #     size = len(queue_1)
        #     for i in range(size):
        #         node = queue_1.pop(0)
        #         if Edge[node]!=-1:
        #             list_1[Edge[node]]-=1 
        #             if list_1[Edge[node]]==0:
        #                 queue_1.append(Edge[node])
        # max_ans = -1 
        
        # for i in range(N):
        #     if list_1[i]>0:
        #         max_ans = max(max_ans , i)
        # if(max_ans==-1):
        #     return node

        # return max_ans
