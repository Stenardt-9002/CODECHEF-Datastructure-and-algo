
class Node
{
  int data;
  Node left,right;

}

class CF1G
{
  Node root;
  int dahmetr = Integer.MIN_VALUE;

  Node newNode(int daat)
  {
    Node node = new Node();
    node.data = daat;
    node.left = null;
    node.right = null;

    return node;
  }
  int hegt(Node n1)
  {
    if (n1==null)
    {
        return 0;
    }
    int lh = hegt(n1.left);
    int rh = hegt(n1.right);

    this.dahmetr = Math.max(this.dahmetr,1+lh+rh);
    // return (1+Math.max(hegt(n1.left),hegt(n1.right)));
    return (1+Math.max(lh,rh));


  }


    public static void main(String[] args)
    {
      CF1G obj1 = new CF1G();

      Node root1 = obj1.newNode(1);
    root1.left = obj1.newNode(2);
    root1.right = obj1.newNode(3);
    root1.left.left = obj1.newNode(4);
    root1.left.right = obj1.newNode(5);
    obj1.root = root1;
    obj1.hegt(root1);
    System.out.println("you got some height "+ obj1.dahmetr);


    }
}
