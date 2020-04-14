import java.util.*;
class Mofat
{
public int n;//,arr1[][];
public int arr1[][] =  {
  { 1, 0, 0, 0 },
  { 1, 1, 0, 1 },
  { 0, 1, 0, 0 },
  { 1, 1, 1, 1 }
};
// public int arr1[][] =  {
//   { 1, 1, 1, 1 },
//   { 1, 1, 1, 1 },
//   { 1, 1, 1, 1 },
//   { 1, 1, 1, 1 }
// };
public int sol[][] ;
  int mazesol(int starx,int stary)
  {
    // System.out.println(starx);

      if (starx == this.n-1 && stary == this.n-1 && this.arr1[starx][stary] == 1)
      {
        this.sol[starx][stary] = 1;
        return 1;

      }

      if(starx>=0 && stary>=0 && starx<this.n && stary<this.n )
      {
        if(this.arr1[starx][stary]==1)
        {
           this.sol[starx][stary] = 1;
          if (this.mazesol(starx,stary+1)==1)
          {
            return 1;
          }

          if (this.mazesol(starx+1,stary)==1)
          {
            // System.out.print("RESCRFEWF ONECES");
            return 1;
          }
        }
        this.sol[starx][stary] = 0;
        return 0;

      }
      return 0;

  }

  void fucj(int starx,int stary)
  {
    // System.out.print(starx);
      if (this.mazesol(starx,stary)==0)
      {
          System.out.println("No solution");

      }
      for (int i=0;i<this.n ;i++ )
      {
        for (int j = 0 ;j<this.n ;j++ )
        {
            // this.sol[i][j] ;
            System.out.print(this.sol[i][j]);
            System.out.print(" ");
        }
        System.out.println();
      }
      // return 1;
  }


public static void main(String[] args)
{
  Scanner myobj1 = new Scanner(System.in);

  // System.out.println("Enter the number\n");
  Mofat m1ob = new Mofat();
// m1ob.n = myobj1.nextInt();

// m1ob.arr1 = {
//   { 1, 0, 0, 0 },
//   { 1, 1, 0, 1 },
//   { 0, 1, 0, 0 },
//   { 1, 1, 1, 1 }
// };
  m1ob.n = m1ob.arr1.length;
  // m1ob.arr1 = new int[m1ob.n][m1ob.n];
  m1ob.sol = new int[m1ob.n][m1ob.n];
  for (int i=0;i<m1ob.n ;i++ )
  {
    for (int j = 0 ;j<m1ob.n ;j++ )
    {
        m1ob.sol[i][j] = 0;
    }

  }
  m1ob.fucj(0,0);//start x y
// return 1
}

}
