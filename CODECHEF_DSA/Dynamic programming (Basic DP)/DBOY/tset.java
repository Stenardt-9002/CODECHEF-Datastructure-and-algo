import java.util.*;
import java.io.*;
class OkDokey
{
  public static void main(String[] args) throws java.lang.Exception
  {


    Scanner in = new Scanner(System.in);
    int m,i,j,k,sizefuel,n,res,z;
    int []dynaar,rdunfuel,ditance,fuel;
    dynaar = new int[1001];
    ditance = new int[501];
    rdunfuel = new int[501];//maximum petrol
    fuel = new int[501]; //not maxiumum n mightinpt be utilised
    k = Integer.parseInt(in.nextLine());
    System.out.println(k+10);

    for (z = 0; z<5;z++ )
    {
        dynaar[z] = in.nextInt();
    }
    System.out.println(dynaar[0]);
    System.out.println(dynaar[2]);
    System.out.println(dynaar[3]);
    System.out.println(dynaar[4]);
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    String name = reader.readLine();
    System.out.println(name+10);

   }

}
