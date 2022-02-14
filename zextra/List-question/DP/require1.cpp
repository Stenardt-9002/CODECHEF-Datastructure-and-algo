

#include "bits/stdc++.h"



using namespace std;


#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount




    int eggDrop(int n, int k) 
    {
        // your code here
        // N eggs  k floors 
        if(n==1)
        {return k;}
        if(k==1)
        {return 1;}
        if (k==0)
        {
            return 0 ;
        }
        int dp1[n+1][k+1];
        for (int i1 = 0; i1 < 1000; i1++)
        {
            for (int j1 = 0; j1 < 1000; j1++)
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

                int miin = INT_MAX ;
                int niim1 = INT_MAX ;
                  for (int allflor = 1; allflor <crflor; allflor++)
                    {
                        miin = max(dp1[eggs-1][allflor-1] ,dp1[eggs][crflor-allflor]) ;
                          if (niim1>miin)
                            {
                                niim1 = miin ;
                            }
                
                    }
                    dp1[eggs][crflor] = niim1+1;
            }
            
        }
        


      
        return dp1[n][k];
        // return niim1+1 ;
    }









