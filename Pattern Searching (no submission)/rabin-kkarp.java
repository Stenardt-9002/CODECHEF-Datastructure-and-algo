class Rabinkarpimn
{

  static void srch(String textmain,String pasttern)
  {
    int CHARACMUKL = 256;
    int patlen = pasttern.length();int phash  = 0;
    int lentext = textmain.length()    ;int texthas = 0;
    //initial length matching
    int i,j;
    for (i=0;i<patlen ;i++ )
    {
        phash = phash*CHARACMUKL+pasttern.charAt(i);
        texthas = texthas*CHARACMUKL+textmain.charAt(i);


    }
    // System.out.println(phash);
    // System.out.println(texthas);


    for (i=patlen; i<=lentext ;i++ )
    {
      if (phash == texthas)
      {
          for (j=0;j<patlen ; j++)
          {
            if (pasttern.charAt(j)!=textmain.charAt(i+j-patlen))
            {
            //
            //   System.out.println(i);
            //   System.out.println(j);
            //   System.out.println(pasttern.charAt(i));
            //   System.out.println(textmain.charAt(i+j));
            //
            //   System.out.println("reahcede");

              break;
            }
          }

          if(j==patlen)
          {
            System.out.println("Found "+(i-patlen));
            j=0;
          }

      }
      if (i==lentext)
      {
          return;
      }

      //not found
        texthas = (texthas-((textmain.charAt(i-patlen))*(int)(Math.pow(CHARACMUKL,patlen-1))))*CHARACMUKL+textmain.charAt(i);
        // texthas = (texthas-(textmain.charAt(i-patlen)))*CHARACMUKL+(textmain.charAt(i))*CHARACMUKL;
        // pattern hash same

    }






  }


	public static void main(String[] args)
	{
		// String txt = "This is an pattern testing string in case of fired which again may i say that you are hired but everyday we are tired";
		// String pat = "ired";

    String txt = "SSASABCASDF";
    String pat = "AS";


		srch(txt,pat);
	}


}
