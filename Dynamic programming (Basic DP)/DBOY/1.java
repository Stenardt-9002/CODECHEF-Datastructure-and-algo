import java.util.*;
import java.io.*;

class OkDokey
{
  public static void main(String[] args) throws java.lang.Exception
  {


    Scanner in = new Scanner(System.in);
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int m,i,j,k,sizefuel,n,res;
    int []dynaar,rdunfuel,ditance,fuel;
    dynaar = new int[1001];
    ditance = new int[501];
    rdunfuel = new int[501];//maximum petrol
    fuel = new int[501]; //not maxiumum n mightinpt be utilised
    int test;
    try {
            // test = Integer.parseInt(in.nextLine());//test cases
            test = Integer.parseInt(br.readLine());


    } catch(Exception e)
    {
      test = 0;
    }

        while (test-->0)
        {
          m =-1;
          // if(in.hasNext())
          // n = Integer.parseInt(in.nextLine());
          n = Integer.parseInt(br.readLine());

          for (i=0; i<n; i++)
          {
            try {
                // ditance[i] = Integer.parseInt(in.nextLine());
                ditance[i] = in.nextInt();

            }
            catch (Exception e)
            {
              break;
            }

            // System.out.println(ditance[i]);
            if (m<ditance[i])
            {
              m = ditance[i];
            }
          }

          Arrays.fill(dynaar, 19999);
          Arrays.fill(rdunfuel, 0);
          //clear dynaar and rdunfuel
          sizefuel = 0;

          for (i=0; i<n;i++ )
          {
            try
            {
                // k = Integer.parseInt(in.nextLine());
                k = in.nextInt();
            } catch(Exception e)
            {
                break;
            }


            if (rdunfuel[k]==0)
            {
                fuel[sizefuel++] = k;
                rdunfuel[k] = 1;
                //removal of redundant
            }



          }



          dynaar[0] = 0;
          for (i = 0;i<sizefuel;i++ )
          {
            for (j=0;j<=2*m-fuel[i] ;j++ )
            {
                if (dynaar[j]+1<dynaar[j+fuel[i]])
                {
                  dynaar[j+fuel[i]] = dynaar[j]+1;
                }

            }

          }
            res = 0;
            for (i =0;i<n ;i++ )
            {
                res+=dynaar[2*ditance[i]];
            }
            System.out.println(res);





        }



   }

}
