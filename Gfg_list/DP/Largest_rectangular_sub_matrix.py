from collections import defaultdict
from typing import List

def zerosumgame(temp_array,row):
    dictionary = defaultdict(int)
    cur_sum = 0 
    max_length = 0 
    starti = 0 
    endj = 0
    for i in range(row):
        cur_sum+=temp_array[i]
        if temp_array[i]==0 and max_length ==0 :
            starti = i 
            endj = i 
            max_length = 1
        if cur_sum == 0:
            if max_length<=i:
                starti = 0
                endj = i 
            max_length = i+1 
        if cur_sum in dictionary:
            cur = max_length 
            max_length = max(max_length , i-dictionary[cur_sum])
            if cur<max_length:
                endj = i 
                starti = dictionary[cur_sum]+1 
        else:
            dictionary[cur_sum] = i

    if max_length!=0:
        return True ,starti , endj
    
    return False ,starti , endj


class Solution:


    def sumZeroMatrix(self, a : List[List[int]]) -> List[List[int]]:
        # code here
        row = len(a)
        col = len(a[0])
        ansupx = 0
        ansupy = 0
        ansdownx = 0
        ansdowny = 0
        max_ans = -999

        for left in range(col):
            temp_array = [0]*row 
            for right in range(left , col):
                for i in range(row):
                    temp_array[i]+=a[i][right]
                
                cur_sum , up ,down = zerosumgame(temp_array,row)
                cur_dim = (down-up+1)*(right-left+1)

                if cur_sum and cur_dim>max_ans:
                    max_ans = cur_dim 
                    ansupy = up 
                    ansdowny = down 
                    ansupx = left 
                    ansdownx = right


        ans = []
        for i in range(ansupy , ansdowny+1):
            temp = []
            for j in range(ansupx , ansdownx+1):
                temp.append(a[i][j])
            ans.append(temp)
        return ans 
