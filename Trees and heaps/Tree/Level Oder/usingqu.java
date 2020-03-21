import java.util.*;

class Node {
  int data ;
  Node left,right;
  public Node (int item)
  {
    data  = item;
    left = null;
    right = null;
  }

}

class BinaryTree
{
  Node root;
  void printLebelOrder()
  {
      Queue<Node> qu1 = new LinkedList<Node>();
      qu1.add(root);
      while (!qu1.isEmpty())
      {
        Node tempNode = qu1.poll();

        System.out.print(tempNode.data+" ");
        if (tempNode.left!=null)
        {
            qu1.add(tempNode.left);
        }

        if (tempNode.right!=null)
        {
            qu1.add(tempNode.right);
        }


      }


  }









  public static void main(String[] args)
  {
      BinaryTree tree_lel = new BinaryTree();
      tree_lel.root = new Node(1);
      tree_lel.root.left = new Node(2);
      tree_lel.root.right = new Node(3);
      tree_lel.root.left.left = new Node(4);
      tree_lel.root.left.right = new Node(5);
      tree_lel.root.right.left = new Node(7);
      tree_lel.root.right.right = new Node(6);
      System.out.println("Level Order\n");
      tree_lel.printLebelOrder();
  }




}
