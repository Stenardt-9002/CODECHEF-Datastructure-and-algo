import heapq 
class Node:
    def __init__(self , val) -> None:
        self.right = None 
        self.left = None 
        self.data = val





class Solution:
    def shortestRange(self, root):
        # Return pair/tuple of range
        # Your code goes here
        level_order_traversal = []
        queue_1 = [root]
        while(len(queue_1)>0):
            qsize = len(queue_1) 
            cur = []
            while qsize>0:
                qsize-=1 
                pop_node = queue_1.pop(0)
                if pop_node.left is not None:
                    queue_1.append(pop_node.left)
                if pop_node.right is not None:
                    queue_1.append(pop_node.right)
                
                cur.append(pop_node.data)

            level_order_traversal.append(cur)
            pass 
        return level_order_traversal 


root = Node(8)
root.left = Node(3)
root.right = Node(10)
root.left.left = Node(2)
root.left.right = Node(6)
root.left.right.left = Node(4)
root.left.right.right = Node(7)


root.right.right = Node(14)
root.right.right.left = Node(12)
root.right.right.left.left = Node(11)
root.right.right.left.right = Node(13)





obj1 = Solution()
print(obj1.shortestRange(root))
