#gfg artcile

# https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/


class Node:
    def __init__(self , val):
        self.left = self.right = None 
        self.data = val 


#root , parent , original graph_variable
def build_graph(root ,parent , dictionary_graph ):
    if (root == None):
        return 
    if(parent!=None):
        #adding parent connection to child
        if parent in dictionary_graph.keys():
            dictionary_graph[parent].append(root)   
        else :
            dictionary_graph[parent] = [root]
        #adding child connection to parent
        if root in dictionary_graph.keys():
            dictionary_graph[root].append(parent)   
        else :
            dictionary_graph[root] = [parent]
            
    #recursive call for children
    build_graph(root.left , root ,dictionary_graph)
    build_graph(root.right , root ,dictionary_graph)



def burntree(root,target):
    #no node
    if root is None:
        return -1

    #single node 
    if root.left is None and root.right is None:
        if root.data == target:
            print(root.data)
            return 0 #target is the only root
        return -1 #target not found

    #new graph variable where each node is connected to parent as well as its children
    graph_dictionary = {}
    build_graph(root ,None ,graph_dictionary)


    visisted_array = {}
    for i in graph_dictionary.keys():
        visisted_array[i] = False 

    if(target is None):#target not found
        return -1

    queue_var = []
    queue_var.append(target)
    visisted_array[target] = True 
    #BFS
    while len(queue_var)>0:
        cur_size = len(queue_var)
        while cur_size>0:
            cur_size-=1 
            cur_node = queue_var.pop(0)
            print(cur_node.data ,end =" ")
            for child in graph_dictionary[cur_node]:
                if child is not None and visisted_array[child]==False:
                    visisted_array[child] = True 
                    queue_var.append(child)
        print()


    return 1 #success

#main
root = Node(12)
root.left = Node(13)
root.right = Node(10)
root.right.left = Node(14)
root.right.right = Node(15)
left1 = root.right.left
right1 = root.right.right
left1.left = Node(21)
left1.right = Node(24)
right1.left = Node(22)
right1.right = Node(23)


burntree(root , left1)
print()



root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.left.right.left = Node(7)
root.left.right.right = Node(8)
target = root.left.right.right

root.right.right = Node(6)
root.right.right.right = Node(9)
root.right.right.right.right = Node(10)


burntree(root , target)




# root = Node(1)
# root.left = Node(2)
# root.right = Node(3)
# root.left.left = Node(4)
# root.left.right = Node(5)
# root.left.left.left = Node(8)
# root.left.right.left = Node(10)


# target = root.left.right.left

# root.right.right = Node(7)





# obj1 = Solution()
# print(obj1.burntree(root , 8))










