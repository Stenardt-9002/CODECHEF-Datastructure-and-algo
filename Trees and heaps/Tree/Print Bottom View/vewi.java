
import java.util.*;
import java.util.Map.*;
class Node
{
    int data ;
    int hd ;
    Node left,right;
    public Node(int key)
    {
      data = key ;
      hd = Integer.MAX_VALUE;
      left = right = null;
    }
}

class T1ree
{

  Node root;
  public T1ree(Node n1)
  {
    root = n1;
  }


  public void bottoom1viwe()
  {

    if (root==null)
    {
        return ;
    }



    int hd = 0;
    Map<Integer,Integer> map = new TreeMap<>()  ;


    Queue<Node> q1 = new LinkedList<Node>();
    root.hd = 0;
    q1.add(root);

    // same shiz as kind of level order traersal data
    while (!q1.isEmpty())
    {
      Node temp = q1.remove();
      hd = temp.hd;

      map.put(hd,temp.data);

      if (temp.left!=null)
      {
          temp.left.hd = hd-1;
          q1.add(temp.left);
      }

      if (temp.right!=null)
      {
          temp.right.hd = hd+1;
          q1.add(temp.right);
      }


    }


    Set<Entry<Integer,Integer>> se1 = map.entrySet();
    Iterator<Entry<Integer,Integer>> it1era = se1.iterator();

    while (it1era.hasNext())
    {
        Map.Entry<Integer,Integer> tp1 = it1era.next();
        System.out.print(tp1.getValue()+" ");
    }


  }


    public static void main(String[] args)
    {
        Node root1 = new Node(20);
        root1.left = new Node(8);
        root1.right = new Node(22);
        root1.left.left = new Node(5);
        root1.left.right = new Node(3);
        root1.right.left = new Node(4);
        root1.right.right = new Node(25);
        root1.left.right.left = new Node(10);
        root1.left.right.right = new Node(14);
        T1ree t1obj = new T1ree(root1);
        t1obj.bottoom1viwe();


    }










}
