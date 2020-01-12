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



    for (i=patlen; i<lentext ;i++ )
    {
      if (phash == texthas)
      {
          for (j=0;j<patlen ; j++)
          {
            if (pasttern.charAt(j)!=textmain.charAt(i+j)) {
              break;
            }
          }

          if(j==patlen-1)
          {
            System.out.println("Found "+i);
          }

      }

      //not found
        texthas = (texthas-((textmain.charAt(i-patlen))*CHARACMUKL))*CHARACMUKL+textmain.charAt(i);
        // pattern hash same

    }






  }


	public static void main(String[] args)
	{
		String txt = "GEEKS FOR GEEKS";
		String pat = "GEEK";
		srch(txt,pat);
	}


}
