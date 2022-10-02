class GFG {

    static void printEgypt(int nr ,int dr)
    {

        //case 0 
        // eihter is 0 
        // case 1
        //either is dr//nr


        // n = dr/nr+1 greatest intger function 

        if(dr==0 || nr==0)
        {
            return ;
        }

        if(dr%nr==0)
        {
            System.out.print("1/" + (dr/nr) ) ;
            return ;
        }

        int t = dr/nr+1 ; //gretest intger function 

        //recursion call again 
        System.out.print("1/" + t+" + ") ;
        printEgypt(nr*t-dr ,dr*t);


    }






public static void main(String[] args) {
    
    int nr = 7 , dr = 22; 

    printEgypt(7,22);

}

} 







