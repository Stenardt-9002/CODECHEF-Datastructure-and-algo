import java.util.*;
class OkDokey
{
  public static void main(String[] args)
  {


    Scanner in = new Scanner(System.in);
    int m,i,j,k,sizefuel,n,res;
    int []dynaar,rdunfuel,ditance,fuel;
    dynaar = new int[1001];
    ditance = new int[501];
    rdunfuel = new int[501];//maximum petrol
    fuel = new int[501]; //not maxiumum n mightinpt be utilised
    while(in.hasNext())
        {
          int test = Integer.parseInt(in.nextLine());//test cases
        while (test-->0)
        {
          m =-1;
          // if(in.hasNext())
          {n = Integer.parseInt(in.nextLine());}

          for (i=0; i<n; i++)
          {
            ditance[i] = Integer.parseInt(in.nextLine());
            // System.out.println(ditance[i]);
            if (m<ditance[i])
            {
              m = ditance[i];
            }
          }

          Arrays.fill(dynaar, 9999);
          Arrays.fill(rdunfuel, 0);
          //clear dynaar and rdunfuel
          sizefuel = 0;

          for (i=0; i<n;i++ )
          {
            k = Integer.parseInt(in.nextLine());
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

}
