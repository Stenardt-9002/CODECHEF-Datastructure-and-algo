class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None



def recursive(root , X , ans):
    if root is None:
        return 0 
    data = root.data+recursive(root.left,X , ans)+recursive(root.right,X , ans)
    if data==X:
        ans[0]+=1

    return data 


#Function to count number of subtrees having sum equal to given sum.
def countSubtreesWithSumX(root, x):
    ans = [0]
    sum_val = recursive(root , x, ans)
    # if (sum_val==x):
    #     ans[0]+=1
    return ans[0]
    
    # code here











