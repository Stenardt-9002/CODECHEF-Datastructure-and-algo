

#include "bits/stdc++.h"

using namespace std;








    // int eggDrop(int n, int k) 
    // {
    //     // your code here
    //     // N eggs  k floors 
    //     if(n==1)
    //     {return k;}
    //     if(k==1)
    //     {return 1;}
    //     if (k==0)
    //     {
    //         return 0 ;
    //     }
        
    //     int miin = INT_MAX ;
    //     int niim1 = INT_MAX ;
    //     int success1 ;
    //     int not_break ;
    //     for (int allflor = 1; allflor < k; allflor++)
    //     {
    //            success1 = eggDrop(n-1,allflor-1) ;
    //            not_break = eggDrop(n,k-allflor);
    //            miin = max(success1 , not_break) ;
    //             if (niim1>miin)
    //             {
    //                 niim1 = miin ;
    //             }
                

    //     }
        
    //     return niim1+1 ;
    // }

    int eggDrop(int n, int k) 
    {

//O(n*k^2)


        // your code here
        // N eggs  k floors 

        // if(n==1)
        // {return k;}
        // if(k==1)
        // {return 1;}
        // if (k==0)
        // {
        //     return 0 ;
        // }
        int dp1[n+1][k+1];
        for (int i1 = 0; i1 < n+1; i1++)
        {
            for (int j1 = 0; j1 < k+1; j1++)
            {
                dp1[i1][j1] = 0;
            }
            
        }

        for (int i1 = 1; i1 < k+1; i1++)
        {
            dp1[1][i1] = i1;
        }
        for (int i1 = 1; i1 < n+1; i1++)
        {
            dp1[i1][1] = 1;
        }




        for (int eggs = 2; eggs < n+1; eggs++)
        {
            for (int crflor = 2; crflor < k+1; crflor++)
            {

                int maxone ;
                int minofall = INT_MAX ;
                  for (int allflor = 1; allflor <=crflor; allflor++)
                    {
                        maxone = max(dp1[eggs-1][allflor-1] ,dp1[eggs][crflor-allflor]) ;
                          if (minofall>maxone)
                            {
                                minofall = maxone ;
                            }
                
                    }
                    dp1[eggs][crflor] = minofall+1;
// one id for tha tral            
                    }
            
        }
        


      
        return dp1[n][k];
        // return niim1+1 ;
    }

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k ;

    cout<<eggDrop(n,k);
    return 0;
}


