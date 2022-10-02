import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {

  private static int magic_function(int [][]ar1)
  {
    int m = ar1[0].length;
    int n = ar1.length;

    int temSum[][] = new int[n+1][m];
    int i,j,k;
    for (i=0;i<n ;i++ )
    {
        for (j=0;j<m ;j++ )
        {
          temSum[i+1][j] = temSum[i][j] + ar1[i][j];//sum dis shiz

        }

    }


    int maxVal,minVal,sum1 = 0 ;
    maxVal = -34;minVal = Integer.MIN_VALUE;
    for (i=0; i<n; i++)
    {
      for (j=i;j<n ;j++ )
      {
          sum1 = 0;
          for (k=0; k<m;k++ )
          {
            sum1+=temSum[j+1][k]-temSum[i][k];
            if (sum1<0)
            {
                sum1 = 0;
            }
            else if(maxVal<sum1)
            {
              maxVal = sum1;

            }

          }
      }


    }

    return maxVal;


  }





	public static void main (String[] args)
  {

    Scanner obj1 = new Scanner(System.in);
    int testcases,rows,cols,i,j;
    testcases = obj1.nextInt();
    rows = obj1.nextInt();
    cols = obj1.nextInt();
     int [][]arr1 ;
    arr1 = new int[rows][cols];

    for (i=0;i<rows  ;i++ )
    {
      for (j=0; j<cols;j++ )
      {
        arr1[i][j] = obj1.nextInt();

      }


    }

    // System.out.println();
    // for (i=0;i<rows  ;i++ )
    // {
    //   for (j=0; j<cols;j++ )
    //   {
    //     System.out.print(arr1[i][j]);
    //     System.out.print(" ");
    //
    //   }
    //   System.out.println();
    //
    // }

System.out.println(magic_function(arr1));

	 }









}
