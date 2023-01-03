# https://practice.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1


from typing import Optional
from collections import deque

def compare(list1 ,list2):
    if(len(list1)!=len(list2)):
        return False 
    list1.sort()
    list2.sort()
    for i in range(len(list1)):
        if(list1[i]!=list2[i]):
            return False 

    return True 

class Solution:
    def areAnagrams(self, node1 : Optional['Node'], node2 : Optional['Node']) -> bool:
        if node1 is None and node2 is None :
            return True
        if node1 is None or node2 is None :
            return False 

        queue1 = []
        queue2 = []
        queue1.append(node1)
        queue2.append(node2) 

        while (len(queue1)>0 and len(queue2)>0):
            list1level = []
            list2level = []
            for i in range(len(queue1)):
                noden1 = queue1.pop(0)
                if(node1.left is not None):
                    queue1.append(node1.left)

                if(node1.right is not None):
                    queue1.append(node1.right)
                    
                list1level.append(noden1.data)
            
            for i in range(len(queue2)):
                noden2 = queue2.pop(0)
                if(node2.left is not None):
                    queue1.append(node2.left)

                if(node2.right is not None):
                    queue1.append(node2.right)
                    
                list2level.append(noden2.data)

            if(list1level!=list2level):
                return False 
            

        if(compare(list1level,list2level)==False):
            return False 

        return True 



        # code here
   