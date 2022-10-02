class Node
{
  Node left,right;
  int daat;
  public Node(int daat)
  {
    this.daat = daat;
    left=right=null;
  }

}

class BinaryT
{
  Node root;
  static int max_level = 0;


  void viewLeftoftree(Node node1,int levl)
  {
    if (node1 == null)
    {
        return ;
    }

    if (max_level<levl)
    {
      System.out.println(" "+node1.daat);
      max_level = levl;

    }

    viewLeftoftree(node1.left,levl+1);
    viewLeftoftree(node1.right,levl+1);


  }

  void leftView()
  {
    viewLeftoftree(root,1);
  }







    public static void main(String[] args)
    {
      BinaryT teer = new BinaryT();
      teer.root = new Node(12);
      teer.root.left = new Node(10);
      teer.root.right = new Node(33);
      teer.root.left.left = new Node(9);
      teer.root.left.right = new Node(11);
      teer.root.right.left = new Node(29);
      teer.root.right.right = new Node(37);

      teer.leftView();
    }
}
