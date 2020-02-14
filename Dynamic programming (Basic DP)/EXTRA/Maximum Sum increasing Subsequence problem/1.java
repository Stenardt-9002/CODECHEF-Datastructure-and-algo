import java.util.*;

class OkDokey {


  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int i,j;
    int n = in.nextInt();
    int []ar1 = new int[n];
    int []dp1 = new int[n];
    // System.out.println(n);
    for (i=0;i<n ;i++ )
    {
    dp1[i] = ar1[i] = in.nextInt();

    }
    // System.out.println();
    // for (i=0;i<n ;i++ )
    // {
    //   System.out.println(ar1[i]);
    //
    // }
    int max1 =0;

    for (j=1; j<n; j++)
    {
      for (i=0;i<j ;i++ )
      {
        if ((ar1[j]>ar1[i])&&(dp1[j]<dp1[i]+ar1[j]))
        {
          dp1[j] = dp1[i]+ar1[j];
        }

      }

    }
    max1 = dp1[0];
    for (i=1;i<n ;i++ )
    {
      if (max1<dp1[i])
      {
        max1 = dp1[i];
      }

    }


    System.out.println(max1);


  }

}
