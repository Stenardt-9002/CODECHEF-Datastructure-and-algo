class Node
{
    int data;
    Node left, right;

    Node(int data)
    {
        this.data = data;
        left = right = null;
    }
}

class GetVertic
{
  int m1in = Integer.MAX_VALUE,m1ax =Integer.MIN_VALUE;
  Node root;
  void findgerth(Node node1,int gert)
  {
    if (node1==null)
    {
        return;
    }
    if (gert<m1in)
    {
      m1in = gert;
    }
    else if(gert>m1ax)
    {
      m1ax = gert;
    }

    findgerth(node1.left,gert-1);
    findgerth(node1.right,gert+1);


  }



  void printVrtical(Node node1,int currentno,int gert)
  {
    if (node1==null)
    {
      return;
    }

    if (gert == currentno)
    {
      System.out.print(node1.data+" ");
    }

      printVrtical(node1.left,currentno,gert-1);
      printVrtical(node1.right,currentno,gert+1);

  }


  void verticalOder(Node root1)
  {
    // traerse gerth
    findgerth(root1,0);
    // System.out.println(m1in);
    // System.out.println(m1ax);
    for (int strt = m1in;strt<=m1ax ;strt++ )
    {
      printVrtical(root1,strt,0);
      System.out.println();
    }

  }







  public static void main(String[] args)
  {
    GetVertic tree = new GetVertic();
    tree.root = new Node(1);
     tree.root.left = new Node(2);
     tree.root.right = new Node(3);
     tree.root.left.left = new Node(4);
     tree.root.left.right = new Node(5);
     tree.root.right.left = new Node(6);
     tree.root.right.right = new Node(7);
     tree.root.right.left.right = new Node(8);
     tree.root.right.right.right = new Node(9);
     System.out.println("This is a check");

     tree.verticalOder(tree.root);
  }
}
