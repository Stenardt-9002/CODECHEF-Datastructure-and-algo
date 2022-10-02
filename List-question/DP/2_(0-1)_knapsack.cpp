#include "bits/stdc++.h"

using namespace std;



    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     vector<int> dp1(W+1 ,-1) ; // all -1 means not exist 
    //     // dp1 consist value min 
    //     for (int i1 = 0; i1 < n; i1++)
    //     {
    //         if(wt[i1]<=W){dp1[wt[i1]] = val[i1] ;}
    //     }


    //          cout<<endl;
    //         for (int i1 = 0; i1 < W+1; i1++)
    //         {
    //             cout<<" "<<dp1[i1];
    //         }
            
    //     cout<<endl;




    //     int max_val = INT_MIN ;
    //     //traverse all weights 

    //     int current_max = INT_MIN ;


    //     for (int i1 = 1; i1 < W+1; i1++)
    //     {

    //         // if (dp1[i1]!=-1&&current_max<dp1[i1])
    //         // {
    //         //     current_max = dp1[i1];
    //         // }
            



    //         max_val = INT_MIN ;
    //         for (int j1 = 0; j1 < n; j1++)
    //         {
    //             if ((i1-wt[j1])>0 && dp1[i1-wt[j1]]!=-1 && max_val<(dp1[i1-wt[j1]]+val[j1] )  )//weight available
    //             {
    //                 max_val = dp1[i1-wt[j1]]+val[j1];
    //             }
                
    //         }
    //         if (max_val!=INT_MIN)
    //         {
    //             dp1[i1] = max_val ;
    //         }
            

    //         // if (current_max > dp1[i1])
    //         // {
    //         //     dp1[i1] = current_max;
    //         // }
            



    //     }
    //            cout<<endl;
    //         for (int i1 = 0; i1 < W+1; i1++)
    //         {
    //             cout<<" "<<dp1[i1];
    //         }
            
    //     cout<<endl;

        
    //         for (int i1 = 1; i1 < W+1; i1++)
    //         {
    //             if (dp1[i1]>current_max)
    //             {
    //                 current_max = dp1[i1];
    //             }
    //             else
    //             {
    //                 dp1[i1] = current_max ;
    //             }
                
                
    //             // dp1[i1];
    //         }
            
        

    //     cout<<endl;
    //         for (int i1 = 0; i1 < W+1; i1++)
    //         {
    //             cout<<" "<<dp1[i1];
    //         }
            
    //     cout<<endl;


    //     return dp1[W];
        
       
    // }





    int knapSack(int W, int wt[], int val[], int n) 
    { 


    // vector<vector<int>> dp1(n+1,vector<int>(W+1));
        int dp1[n+1][W+1];
        for(int i1 = 0 ;i1<=n;i1++)
        {
            for(int j1=0;j1<W+1;j1++)
            {
                dp1[i1][j1] = 0;
            }
        }

        //for each items 
        for (int  i1 = 0; i1 <=n; i1++)
        {
            //for each weights
            for (int j1 = 0; j1 <=W; j1++)
            {
                    if (i1==0||j1==0)
                    {
                        dp1[i1][j1] = 0;
                    }
                
                    else if (j1-wt[i1-1]>=0) // (i1-1)th item cannot be included 
                    {
                        dp1[i1][j1] = max(val[i1-1]+dp1[i1-1][j1-wt[i1-1]] ,dp1[i1-1][j1] );
                    }
                    else
                    {
                        // cant add weight because crossing limiting restriction
                        dp1[i1][j1] = dp1[i1-1][j1] ;
                    }

            }
            
        }
        
        return dp1[n][W];

    }






int main(int argc, char const *argv[])
{
    int n;
    cin>>n ;
    int wieghtresti ;
    cin>>wieghtresti ;

    int *wt = new int[n] ;
    int *val1 = new int[n] ;

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>val1[i1] ;
    }

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>wt[i1] ;
    }
    

    cout<<knapSack(wieghtresti,wt,val1,n);




    delete []wt ;delete[] val1 ;
    return 0;
}





