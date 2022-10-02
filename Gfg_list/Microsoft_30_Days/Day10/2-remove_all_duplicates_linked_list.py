
class Node :
    def __init__(self, val):
        self.data = val
        self.next = None

def removeAllDuplicates(self, head):
    temp = head 

    if temp is None:
        return 
    while temp.next is not None:
        if (temp.data == temp.next.data):
            nextnode = temp.next.next 
            temp.next = None 
            temp.next = nextnode
            
        else :
            temp = temp.next 
    return head     
        #code here