# # https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day16/problem/burning-tree


# class Node:
#     def __init__(self , val):
#         self.left = self.right = None 
#         self.data = val 


# def graph_builder_recursive(root ,parent , dictionary_graph ):
#     if (root == None):
#         return 

#     # if (root.left is not None):
#     #     if root in dictionary_graph.keys():
#     #         dictionary_graph[root].append(root.left)   
#     #     else :
#     #         dictionary_graph[root] = [root.left]

    

#     # if (root.right is not None):
#     #     if root in dictionary_graph.keys():
#     #         dictionary_graph[root].append(root.right)   
#     #     else :
#     #         dictionary_graph[root] = [root.right]

    



#     if(parent!=None):
#         if parent in dictionary_graph.keys():
#             dictionary_graph[parent].append(root)   
#         else :
#             dictionary_graph[parent] = [root]

#         if root in dictionary_graph.keys():
#             dictionary_graph[root].append(parent)   
#         else :
#             dictionary_graph[root] = [parent]
            

#     graph_builder_recursive(root.left , root ,dictionary_graph)
#     graph_builder_recursive(root.right , root ,dictionary_graph)

    

#     pass 

# class Solution:
#     def minTime(self, root,target):
#         dictionary_graph = {}
#         parent = None
#         graph_builder_recursive(root ,parent ,dictionary_graph)
#         # print(dictionary_graph)


#         # # print graph
#         # for i in dictionary_graph.keys():
#         #     list_1 = dictionary_graph[i]
#         #     print("Key  ", i.data , end = " ")
#         #     for child in list_1:
#         #         print(child.data ,end=" ")
#         #     print()


#         visiste_array = {}
#         for i in dictionary_graph.keys():
#             visiste_array[i] = False 
#         queu = []
#         queu.append(target)
#         visiste_array[target] = True 
#         distance =0 
#         while len(queu)>0:
#             cur_size = len(queu)
#             while cur_size>0:
#                 cur_size-=1 
#                 cur_node = queu.pop(0)
#                 for child in dictionary_graph[cur_node]:
#                     if child is not None and visiste_array[child]==False:
#                         visiste_array[child] = True 
#                         queu.append(child)

#             distance +=1 


#         return distance
#         # code here











































































# https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day16/problem/burning-tree


class Node:
    def __init__(self , val):
        self.left = self.right = None 
        self.data = val 



def build_graph(root ,parent , dictionary_graph ):
    if (root == None):
        return 
    if(parent!=None):
        if parent in dictionary_graph.keys():
            dictionary_graph[parent].append(root)   
        else :
            dictionary_graph[parent] = [root]

        if root in dictionary_graph.keys():
            dictionary_graph[root].append(parent)   
        else :
            dictionary_graph[root] = [parent]
            

    build_graph(root.left , root ,dictionary_graph)
    build_graph(root.right , root ,dictionary_graph)

    

def search_node(root , target):
    if root==None:
        return None
    if (root.data == target):
        return root 
    l = search_node(root.left , target)
    r = search_node(root.right , target)
    if l==None and r==None:
        return None
    elif (l==None):
        return r
    return l




class Solution:
    def minTime(self, root,target):
        # code here
        if root is None:
            return -1
        if root.left is None and root.right is None:
            if root.data == target:
                return 0 
            return -1 #target not found

        graph_dictionary = {}
        build_graph(root ,None ,graph_dictionary)

        #         # # print graph
        # for i in graph_dictionary.keys():
        #     list_1 = graph_dictionary[i]
        #     print("Key  ", i.data , end = " ")
        #     for child in list_1:
        #         print(child.data ,end=" ")
        #     print()

        visisted_array = {}
        for i in graph_dictionary.keys():
            visisted_array[i] = False 
        target_node = search_node(root , target)
        if(target_node is None):#target not found
            return -1


        queu = []
        queu.append(target_node)
        visisted_array[target_node] = True 
        distance =0 
        #BFS
        while len(queu)>0:
            cur_size = len(queu)
            while cur_size>0:
                cur_size-=1 
                cur_node = queu.pop(0)
                for child in graph_dictionary[cur_node]:
                    if child is not None and visisted_array[child]==False:
                        visisted_array[child] = True 
                        queu.append(child)
            distance +=1 


        return distance-1


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


obj1 = Solution()
print(obj1.minTime(root , 14))



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


obj1 = Solution()
print(obj1.minTime(root , 8))


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
# print(obj1.minTime(root , 8))










