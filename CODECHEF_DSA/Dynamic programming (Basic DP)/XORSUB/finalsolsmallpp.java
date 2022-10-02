import java.util.*;
class Codechef{

static int maxSubarrayXOR(int array1[], int n,int feltoxor)
{

  int maxEle = array1[0];
  for (int j=1;j<n ;j++ )
  {
    if (array1[j]>maxEle)
    {
      maxEle = array1[j];
    }

  }


  // int litmit = (1 << (int)(log2(max_ele) + 1) ) - 1;
  int per = (int)((Math.log(maxEle))/(Math.log(2)));
  int litmi = (int)(Math.pow(2,(per+1)))-1;

  int dp[][] = new int[n+1][litmi+1];
  for (int i=0; i<=n; i++)
        for (int j=0; j<=litmi; j++)
            dp[i][j] = 0;

   dp[0][0] = 1;
   for (int i=1; i<=n; i++)
        {
          for (int j=0; j<=litmi; j++)
            {
              dp[i][j] = dp[i-1][j] + dp[i-1][j^array1[i-1]];
            }
        }
    maxEle = 0;
    int onto;
    for (int i=0;i<litmi+1 ;i++ )
    {
      if(dp[n][i]>0)
      {
        onto = i ^ feltoxor;
        if (onto>maxEle)
        {
          maxEle = onto;
        }
      }
    }

  return maxEle;

}

public static void main (String[] args) throws java.lang.Exception
{
  // int array1[] = {14,15, 8,3,12,1,6 ,5,9,19,13};
  Scanner input= new Scanner(System.in);
  int array1[] = new int[1000];
  int testcaes;

  int n;
  testcaes = input.nextInt();
  int etelemxor;
  while (testcaes-->0)
  {
    n = input.nextInt();
    etelemxor = input.nextInt();

    for (int i=0;i<n ;i++ )
    {
      array1[i] = input.nextInt();

    }
    System.out.print(maxSubarrayXOR(array1, n,etelemxor));


  }



}
}
