# """ Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

class Solution:
    #Function to find first node if the linked list has a loop.
    def findFirstNode(self, head):
        #code here
        if head==None or head.next==None:
            return -1
        
        slow = head 
        fast = head
        slow = slow.next 
        fast = fast.next.next 
        while fast and fast.next:
            if slow==fast:
                break 
            slow = slow.next 
            fast = fast.next.next 
        if slow!=fast:
            return -1
        slow = head
        while slow!=fast:
            slow = slow.next 
            fast = fast.next 
        return slow.data
