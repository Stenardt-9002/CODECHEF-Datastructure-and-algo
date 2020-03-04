// #better hashing
class Rabinkarpimproved
{

  static void srch(String textmain,String pasttern)
  {
    int CHARACMUKL = 256;
    int hashMaxsize = 15;
    int patlen = pasttern.length();int phash  = 0;
    int lentext = textmain.length()    ;int texthas = 0;
    int i,j;

    // CHARACMUKL^patlen-1 is used so effecient way of calulating it and mod it by hashMaxsize
    int multilplywhen_shifting = 1;
    for (i=0; i<patlen;i++ )
    {
      multilplywhen_shifting = (multilplywhen_shifting*CHARACMUKL)%hashMaxsize;


    }


    //initial length matching


    for (i=0;i<patlen ;i++ )
    {
        phash = (phash*CHARACMUKL+pasttern.charAt(i))%hashMaxsize;
        texthas = (texthas*CHARACMUKL+textmain.charAt(i))%hashMaxsize;
        // make memory effiecient

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
        // texthas = (texthas-((textmain.charAt(i-patlen))*(int)(Math.pow(CHARACMUKL,patlen-1))))*CHARACMUKL+textmain.charAt(i);
        //improved pattern
        texthas = ((texthas-((textmain.charAt(i-patlen))*multilplywhen_shifting))*CHARACMUKL+textmain.charAt(i))%hashMaxsize;

        // pattern hash same
         // NOTE1 REALLY IMPORTANT STUFF
         if (texthas<0) //modding can give value less than 0
         {
           texthas+=hashMaxsize;
         }

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
