class Sol1
{

  boolean Bstpass(Node node1,int leftmin,int rightmin)
  {

    if (root==null)
    {
        return true;
    }

    if (root.data<=leftmin || root.data>rightmin)
    {
      return false;
    }

    if (Bstpass(node1.left,leftmin,node1.data)&&Bstpass(node1.right,node1.data,rightmin))
    {
      return true;
    }
    return false;
  }




public static void main(String[] args) {
    tree.Bstpass
}




}


class Node {
  int data;
  Node left,right;

  public Node(int data)
  {
    this.data = data;
    left = right = null;
  }

}
