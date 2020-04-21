
import java.io.*;
// import junit.framework.TestCase;

import java.util.*;


class Gra1ph
{
  int Veritcno ;
  LinkedList<Integer> adjvertice[];

  Gra1ph(int nofvert)
  {
    this.Veritcno = nofvert;
    this.adjvertice = new LinkedList[nofvert];

    for (int i=0; i<nofvert; i++)
    {
      this.adjvertice[i] = new LinkedList();

    }

  }

  void aDDedge(int v1,int w1)
  {
    this.adjvertice[v1].add(w1);
  }
  void dgsrecur(int tovert,boolean discovered[])
  {
    discovered[tovert] = true;
    System.out.print(tovert+" ");
    Iterator<Integer> i = this.adjvertice[tovert].listIterator();
    while (i.hasNext())
    {
        int neet = i.next();
        if (discovered[neet]==false)
        {
          dgsrecur(neet,discovered);
        }
    }


  }

  void startdfs()
  {
    boolean discovered[] = new boolean[this.Veritcno];
    for (int i=0;i<this.Veritcno ;i++ )
    {
        discovered[i] = false;
    }

    for (int i=0;i<this.Veritcno ;i++ )
    {
        if (discovered[i] ==false)
        {
          dgsrecur(i,discovered);
        }
    }



  }


  public static void main(String[] args)
  {
      Gra1ph g1 = new Gra1ph(7);
      // System.out.println("reached1");
      g1.aDDedge(1,2);
      // System.out.println("reached2");

      g1.aDDedge(1,3);
      // System.out.println("reached3");

      g1.aDDedge(2,1);
      // System.out.println("reached4");

      g1.aDDedge(2,4);
      // System.out.println("reached5");

      g1.aDDedge(2,5);
      // System.out.println("reached6");

      g1.aDDedge(3,1);
      // System.out.println("reached7");

      g1.aDDedge(3,5);
      // System.out.println("reached8");

      g1.aDDedge(4,2);
      // System.out.println("reached9");

      g1.aDDedge(4,5);
      // System.out.println("reached12");

      g1.aDDedge(4,6);
      // System.out.println("reached22");

      g1.aDDedge(5,3);
      // System.out.println("reached32");

      g1.aDDedge(5,4);
      // System.out.println("reached42");

      g1.aDDedge(5,2);
      // System.out.println("reached52");

      g1.aDDedge(5,6);
      // System.out.println("reached62");

      g1.aDDedge(6,4);
      // System.out.println("reached72");

      g1.aDDedge(6,5);
      // System.out.println("reached82");

      // System.out.println("reached3");

      g1.startdfs();
  }




}
