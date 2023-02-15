
'''
class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None
'''


class Solution:
    def verticallyDownBST(self, root, target):
        #code here
        node = root 
        while node is not None and node.data!=target:
            if node.data>target:
                node = node.left 
            elif node.data<target:
                node = node.right 
        
        if node is None:
            return -1 
        dict_1 = {}
        def dfs_u(node ,index_1):
            if node is None:
                return 
            if index_1 in dict_1.keys():
                dict_1[index_1] += node.data
            else:
                dict_1[index_1] = node.data
            
            dfs_u(node.left , index_1-1)
            dfs_u(node.right , index_1+1)
        # print(node.data)
        dfs_u(node , 0)
        # print(dict_1)
        return dict_1[0]-node.data