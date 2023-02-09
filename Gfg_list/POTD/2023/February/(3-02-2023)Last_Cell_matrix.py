
class Solution:
    def endPoints(self, matrix, R, C):
        #code here
        right = True
        left = False 
        up = False
        down = False
        ans = [0,0]        
        pos_init = [0,0]
        while  pos_init[0]>=0 and pos_init[1]>=0 and pos_init[0]<R and pos_init[1]<C:
            ans = [pos_init[0] ,pos_init[1]]
            if matrix[pos_init[0]][pos_init[1]]==1:
                matrix[pos_init[0]][pos_init[1]] = 0
                if right:
                    right = False
                    down = True 
                elif down:
                    down = False
                    left = True 
                elif left:
                    left = False 
                    up = True 
                elif up:
                    up = False 
                    right = True
            if right:
                pos_init[1]+=1
            elif down:
                pos_init[0]+=1
            elif left:
                pos_init[1]-=1
            else:
                pos_init[0]-=1

        return ans 
