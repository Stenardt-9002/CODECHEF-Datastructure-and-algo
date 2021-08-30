import queue 


class Node :
    def __init__(self,val):
        self.val = val 
        self.left = None 
        self.right = None



def topview(root):

    dic = {}
    mi = 99999
    if not root:
        return {}
    q = queue.deque([(root,0)])

    while q:
        cur = q.popleft()
        if cur[1] not in dic:
            dic[cur[1]] = cur[0].val
        
        if cur[0].left:
            q.append((cur[0].left,cur[1]-1))

        if cur[0].right:
            q.append((cur[0].right,cur[1]+1))
    # lits = []
    # while mi in dic:
    #     lits.append(dic[mi])
        

    # return [dic.values()]
    print(dic)





    pass 


if __name__=='__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.left.right.right = Node(5)
    root.left.right.right.right = Node(6)


    print(topview(root))



    pass 














