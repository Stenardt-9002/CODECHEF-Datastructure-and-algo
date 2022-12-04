class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None





class Solution:
    def recursive_func(self , root , ans):
        if root is None:
            return 0 , ans 
        
        l , ans = self.recursive_func(root.left , ans)
        r , ans = self.recursive_func(root.right , ans)

        ans += abs(l)+abs(r)

        return root.data + l+r-1 , ans 
    def distributeCandy(self, root):
        
        #code here
        ans = 0 
        tmp , ans  = self.recursive_func(root , ans)
        return ans 










