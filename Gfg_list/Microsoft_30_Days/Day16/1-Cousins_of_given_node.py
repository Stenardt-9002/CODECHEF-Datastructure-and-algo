class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None





class Solution:
    def printCousins(self, root, node_to_find):
        if root is None:
          return [-1]

    
        queue_list = []
        queue_list.append(root)
        ans = []
        flag_var = 0 
        while len(queue_list)>0:
            size = len(queue_list)
            while size>0 :
                size-=1 
                node_o = queue_list.pop(0)
                if (node_o.left is not None and node_o.left == node_to_find) or (node_o.right is not None and node_o.right == node_to_find) :
                    flag_var = 1
                    
                else:
                    if node_o.left is not None:
                        queue_list.append(node_o.left)
                    if node_o.right is not None:
                        queue_list.append(node_o.right)
            if(flag_var==1):
                break 
    
    
        for i in queue_list:
            ans.append(i.data)
    
        if(len(ans)==0):
            return [-1]
        return ans
        #code here


