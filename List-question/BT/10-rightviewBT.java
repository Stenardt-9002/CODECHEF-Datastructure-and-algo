

import java.util.LinkedList; 
import java.util.Queue;


import java.io.* ;
import java.util.* ;


class Node{
    int data ;
    

    Node left,right ;
    Node(int data)
    {
        this.data = data ;
        left = right = null ;
    }


}


class BinaryTree{
    Node root ;
    // void printLevelOrder(){
    ArrayList<Integer> rightView(Node node) 
    {
        
        Queue<Node> queue = new LinkedList<Node>() ; 
        queue.add(root) ;
        ArrayList<Integer> gdata =new ArrayList<Integer>() ;
        Integer sizeoflevel ;
        // Node node = new Node(10);
        // node.left = new Node(20);
        // node.right = new Node(30);
        // node.left.left = new Node(40);
        // node.left.right = new Node(60);
        Node temp1 = null ;
        while (!queue.isEmpty()) 
        {
            sizeoflevel = queue.size() ;
            
            while (sizeoflevel-->0) 
            {
                temp1 = queue.poll() ;
                if (sizeoflevel==0) {
                    gdata.add(temp1.data) ;
                }
                if (temp1.left!=null) 
                {
                    queue.add(temp1.left)     ;
                }

                if (temp1.right!=null) 
                {
                    queue.add(temp1.right)     ;
                }
                
            }
            

        }


    }

}

// public static void main(String[] args) 
// {
//     Binar        




// }



