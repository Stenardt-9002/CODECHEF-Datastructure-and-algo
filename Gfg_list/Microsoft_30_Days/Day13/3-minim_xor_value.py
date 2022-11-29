
class Node:
    def __init__(self) -> None:
        self.links = [None for _ in range(2)]
    
    def get(self, n):
        return self.links[n]
    def put(self,n, node):
        self.links[n] = node 

    def containskey(self, key):
        return self.links[key]!=None 
    

class Trie:
    def __init__(self) -> None:
        self.root = Node()
    def insert(self,num):
        traversal = self.root 
        for i in range(31,-1,-1):
            bit = (num>>i)&1 
            if(traversal.containskey(bit)==False):
                traversal.put(bit , Node())
            traversal = traversal.get(bit)

    def minimum_xor(self,val):
        ans1 = 0 
        traversal = self.root 
        for i in range(31,-1,-1):
            bit = (val>>i)&1 
            if(traversal.containskey(bit)):
                traversal = traversal.get(bit)
            else :
                traversal = traversal.get(1-bit)
                ans1 = ans1|(1<<i)
                
        return ans1 



class Solution:
    def minxorpair (self, N, arr):
        if(N==1):
            return 0 
        mainroot = Trie()
        mainroot.insert(arr[0])
        ans1 = 99999 
        for i in range(1,N):
            ans1 = min(ans1 , mainroot.minimum_xor(arr[i]))
            mainroot.insert(arr[i])

        return ans1 
        # code here 
        


