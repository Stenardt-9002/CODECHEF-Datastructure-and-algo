class Answer
{

void getlps(String pat1,int lps[]) // my expectation were pretty low but ehat in hell
{

  int patlen = pat1.length();
// 0 th index alway 0
  lps[0] = 0;
  int i = 1,j = 0;
  while (i<patlen)
  {

    if (pat1.charAt(i)== pat1.charAt(j))
    {
      lps[i] = j++;i++;
    }
    else
    {
      if (j==0)
      {
          lps[i] = 0;i++;
      }
      else
      {
        j = lps[j-1];
      }
    }


  }



}




void cluateasnwer(String operstring,String pat)
{

  int operlen = operstring.length();
  int patlen = pat.length();
  int[] lps1 = new int[patlen];
  int j =0;
  getlps(pat,lps1);
  int i=0;
  while(i<operlen)
  {
    if (pat.charAt(j) == operstring.charAt(i))
    {
        i++;j++;
    }


    if (j==patlen)
    {
      System.out.println("Found one at "+(i-j));//i-j strting index of shit
      j = lps1[j-1];

    }

    else if (i<operlen && pat.charAt(j)!=operstring.charAt(i))
    {
        if (j!=0)
        {
            j =  lps1[j-1];//note j begins from 1

        }
        else
        {
          i++;
        }


    }


  }





}



public static void main(String[] args)
{
  String test =  "ABABDABACDABABCABAB";
        String pat = "ABABCABAB";

          Answer A1 = new Answer();
          A1.cluateasnwer(test,pat);

}



}
