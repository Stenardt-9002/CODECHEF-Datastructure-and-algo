    
#include "bits/stdc++.h"

using namespace std;

    
    



    int maxGold(int n, int m, vector<vector<int>> M)
    {
        
      if(m==1)  
      {
        //   return max(M[0]);
        int max1 = INT_MIN ;
        for(int i1 = 0;i1<n;i1++)
        max1 = max(max1,M[i1][0]);
        
        return max1;
          
      }
      if(n==1)
      {
          int sum1 = 0;
         for(int i1 =0 ;i1<m;i1++) 
         sum1+=M[0][i1];
         
         return sum1 ;
      }


        for(int j1 = 1;j1<m;j1++)    
        {
            int max1 ;
            for(int i1 =0 ;i1<n;i1++)
            {
               if (i1>0&&i1<n-1)
               {
                   max1 = max({M[i1-1][j1-1] ,M[i1][j1-1],M[i1+1][j1-1] });
               }
               else if(i1>0)
               {max1 = max(M[i1-1][j1-1] ,M[i1][j1-1] );}
               else
               {   max1 = max(M[i1][j1-1],M[i1+1][j1-1]);}

                M[i1][j1]+=max1 ;   
            }
            
        }


        // cout<<endl;
        // for (int i1 = 0; i1 < n; i1++)
        // {
        //     cout<<endl;
        //     for (int j1 = 0; j1 < m; j1++)
        //     {
        //         cout<<" "<<M[i1][j1];
        //     }
            
        // }
        
        int asnwer1 = M[0][m-1];
        for(int i1 = 1;i1<n;i1++)
        {asnwer1 = max(asnwer1,M[i1][m-1]);}
        return asnwer1;
        
    }




int main(int argc, char const *argv[])
{
        int n;
    cin>>n ;
    int m ;cin>>m;

    vector<vector<int>> mstrix(n);
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     mstrix.push_back(a1);
    // }
    
    // int temp1;
    for (int i1 = 0; i1 < n; i1++)
    {
        mstrix[i1] = vector<int>(m);
    }
    
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            cin>>mstrix[i1][j1];
        }
    }
    

    cout<<maxGold(n,m,mstrix);

    
    return 0;
}



