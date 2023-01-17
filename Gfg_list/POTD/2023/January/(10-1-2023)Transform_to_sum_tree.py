# https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1






class Solution:
    def toSumTree(self, root) :
        #code here
        
        def dfs_u(node):
            if node.left is None and node.right is None:
                vdata = node.data 
                node.data = 0
                return vdata 
            left = 0
            right = 0
            if node.left is not None:
                left = dfs_u(node.left)
            if node.right is not None:
                right = dfs_u(node.right)
            orig = node.data 
            node.data = left+right 
            return orig+left+right
            
        dfs_u(root)
        




















