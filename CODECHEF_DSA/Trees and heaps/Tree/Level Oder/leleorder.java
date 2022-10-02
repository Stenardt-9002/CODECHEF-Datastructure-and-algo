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
    public BinaryTree()
    {
      root = null;
    }



    void printLebelOrder()
    {
      int hght=height(root);
      for (int i=1;i<=hght ;i++ )
      {
        printGibenLebel(root,i);
        System.out.println();

      }
    }


    int height(Node toot)
    {
      if (toot == null)
      {
        return 0;

      }

      else
      {
        int lheight = height(toot.left);
        int rhieght = height(toot.right);
        if (lheight>rhieght)
        {
          return lheight+1;
        }
        else
        {
          return rhieght+1;
        }

      }

    }


    void printGibenLebel(Node rpoot,int levl)
    {
      if (rpoot==null)
      {
        return;

      }
      if (levl==1)
      {
        System.out.println(rpoot.data + " ");

      }
      else
      {
        printGibenLebel(rpoot.left,levl-1);
        printGibenLebel(rpoot.right,levl-1);
      }


    }


    public static void main(String[] args)
    {
        BinaryTree t1 = new BinaryTree();
        t1.root = new Node(1);
        t1.root.left = new Node(2);
        t1.root.right = new Node(3);
        t1.root.left.left = new Node(4);
        t1.root.left.right = new Node(5);
        t1.root.right.left = new Node(6);
        t1.root.right.right = new Node(7);

        System.out.println("LEVEL Order\n");
        t1.printLebelOrder();

    }



}
