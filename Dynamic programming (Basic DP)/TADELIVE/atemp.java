import java.util.*;


class Setester
{

//greedy method



  public static void main(String[] args)
  {

      Scanner obj1 = new Scanner(System.in);
      int n,x,y,i;
      n = obj1.nextInt();
      x = obj1.nextInt();
      y = obj1.nextInt();
      // int []ar1 = new int[n];//a tips
      // int []ar2 = new int[n];//b tips
      ArrayList<Integer> ar1 = new ArrayList<Integer> ();
      ArrayList<Integer> ar2 = new ArrayList<Integer> ();
      ArrayList<Integer> litin = new ArrayList<Integer> ();
      int difference1 ;//b tips
      for (i=0;i<n ;i++ )
      {
        difference1 = obj1.nextInt();
        ar1.add(difference1);

      }
      for (i=0;i<n ;i++ )
      {
        difference1 = obj1.nextInt();
        ar2.add(difference1);

        difference1 =(ar1.get(i) -ar2.get(i));
        if (difference1<0)
        {
          difference1*=-1;
        }
        litin.add(difference1);

      }

      // List<int> CopyyUpon = Arrays.asList()

      //
      System.out.println("TEst");

      for (i=0;i<litin.size() ;i++ )
      {
        System.out.println(litin.get(i));
      
      }
      System.out.println("TEst");

      for (i=0;i<n ;i++ )
      {
        System.out.println(ar1.get(i));
      
      }
      System.out.println("TEst");

      Collections.sort(ar1,(left, right) -> -litin.get(ar1.indexOf(left))+litin.get(ar1.indexOf(right)));
      Collections.sort(ar2,(left, right) -> -litin.get(ar2.indexOf(left))+ litin.get(ar2.indexOf(right)));

      for (i=0;i<n ;i++ )
      {
        System.out.println(ar1.get(i));
      
      }

      System.out.println("TEst");


  }


}




