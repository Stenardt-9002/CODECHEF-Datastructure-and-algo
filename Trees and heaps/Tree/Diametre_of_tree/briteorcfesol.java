
class Node
{
    int data;
    Node left,right;
    public Node(int item)
    {
      data = item;
      left = right = null;
    }
}


class BinaryTree
{
  Node root;

    int diamtre(Node root)
    {
      if (root == null)
      {
        return 0;

      }


      int lh = hegt(root.left);
      int rh = hegt(root.right);

      int ld1 = diamtre(root.left);
      int rd1 = diamtre(root.right);

      return Math.max(lh+rh+1,Math.max(ld1,rd1));

    }

    int hegt(Node n1)
    {
      if (n1==null)
      {
          return 0;
      }

      return (1+Math.max(hegt(n1.left),hegt(n1.right)));

    }

    public static void main(String[] args)
    {
      BinaryTree tee = new BinaryTree();
    
     System.out.println("\nDiametre binary : "+tee.diamtre(tee.root));
    }
}
