# https://practice.geeksforgeeks.org/problems/af49b143a4ead583e943ca6176fbd7ea55b121ae/1



class Solution: 
    def minLaptops(self, N, start, end):
        dict_1 = {}
        max_ans = 0 
        for i in range(N):
            if start[i] in dict_1.keys():
                dict_1[start[i]]+=1
            else :
                dict_1[start[i]]=1
            if end[i] in dict_1.keys():
                dict_1[end[i]]-=1
            else :
                dict_1[end[i]]=-1
            
            
        sum1 = 0 
        keys_list = sorted(dict_1.keys())
        for key in keys_list:
            sum1+=dict_1[key]
            # print(sum1)
            max_ans = max(sum1,max_ans)
        
        return max_ans 
        # Code here

