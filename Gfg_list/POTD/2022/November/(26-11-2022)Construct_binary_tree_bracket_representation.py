

class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None



class Solution:

    def findIndex_func(self ,str , start, end):
        if(start>end):
            return -1 

        
        array1 =[]
        for i in range(start,end+1):
            if(str[i]=='('):
                array1.append(str[i])
            elif (str[i]==')'):
                if (str[-1]=='('):
                    array1.pop(-1)

                    if(len(array1)==0):
                        return i 

        return -1

    def recursive_fun(self,str , start ,end):
        if(start>end):
            return None 
        root = Node(ord(str[start])-ord('0') )
        index = -1 
        if(start+1<=end and str[start+1]=='('):
            index = self.findIndex_func(str , start+1 , end)
        
        if(index!=-1):
            root.left = self.recursive_fun(str , start+2 , index-1)
            root.right = self.recursive_fun(str , index+1 ,end-1)

        return root 

        pass 

    def treeFromString(self, s : str) -> Optional['Node']:
        if(s==""):
            return None 

        return self.recursive_fun(s, 0 , len(s)-1)

        # code here
        





class newNode:
	def __init__(self, data):
		self.data = data
		self.left = self.right = None


def preOrder(node):
	if (node == None):
		return
	print(node.data, end=" ")
	preOrder(node.left)
	preOrder(node.right)


def treeFromStringHelper(si, ei, arr, root):

	if si[0] >= ei:
		return None

	if arr[si[0]] == "(":

		if arr[si[0]+1] != ")":
			if root.left is None:
				if si[0] >= ei:
					return
				new_root = newNode(arr[si[0]+1])
				root.left = new_root
				si[0] += 2
				treeFromStringHelper(si, ei, arr, new_root)

		else:
			si[0] += 2

		if root.right is None:
			if si[0] >= ei:
				return

			if arr[si[0]] != "(":
				si[0] += 1
				return

			new_root = newNode(arr[si[0]+1])
			root.right = new_root
			si[0] += 2
			treeFromStringHelper(si, ei, arr, new_root)
		else:
			return

	if arr[si[0]] == ")":
		if si[0] >= ei:
			return
		si[0] += 1
		return

	return


def treeFromString(string):

	root = newNode(string[0])

	if len(string) > 1:
		si = [1]
		ei = len(string)-1

		treeFromStringHelper(si, ei, string, root)

	return root

# Driver Code
if __name__ == '__main__':
	Str = "4(2(3)(1))(6(5))"
	root = treeFromString(Str)
	preOrder(root)

# This code is contributed by dheerajalimchandani
