class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
        self.nextRight = None
'''
:param root: root of the given tree
:return: none, just connect accordingly.
{
    # Node Class:

}
'''

class Solution:
    def connect(self, root):
        # code here
        queue = [root]
        while len(queue)>0:
            n = len(queue)
            temp = []
            for i in range(n):
                node = queue.pop(0)
                if(node.left is not None):
                    queue.append(node.left)
                if(node.right is not None):
                    queue.append(node.right)
                temp.append(node)
            node = None
            if len(temp)>0:
                node = temp.pop(0)
            while not(node is None or len(temp)==0):
                node.nextRight = temp[0]
                node = temp.pop(0)
        
                
                
                
        
        
