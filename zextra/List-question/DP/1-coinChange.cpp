#include<iostream>
using namespace std;



    int CoinChange(int *arr1 , int m , int n)
    {
        //n value to be made
        // length of array of m

        if(n==0){return 1 ;}
        if(n<0 || m<=0){return 0 ;}


        return CoinChange(arr1,m,n-arr1[m-1])+CoinChange(arr1,m-1,n);
    }




    // long long int count(int S[], int m, int n) 
    // {

    //     long long int i,j,x,y ;
        
    //     long long int dp1[n+1][m];
        
    //     for(i=0;i<m;i++)
    //     {
    //         dp1[0][i] = 1;
    //     }
        
    //     for(i=1;i<n+1;i++)
    //     {
    //         for(j=0;j<m;j++)
    //         {
    //             x = 0;
    //             if(i-S[j]>=0)
    //             {
    //                 x = dp1[i-S[j]][j] ;
    //             }
    //             y=0;
    //             if(j>=1)
    //             {
    //                 y = dp1[i][j-1] ;
    //             }
                
    //             dp1[i][j] = x+y;
    //         }
    //     }
    //     return dp1[n][m-1];
        

    // }


    long long int count(int S[], int m, int n) 
    {

        if(n==0 && m==0)
        {
            return 1 ;
        }


// O(n) space O(m*n) time 
        long long int i,j,x,y ;
        long long int dp1[n+1];
        memset(dp1,0,sizeof(dp1));

        dp1[0] = 1;//base case if 0 value no way
        
        for(i=0;i<m;i++)
        {
            for ( j = S[i]; j <= n; j++)
            {
                dp1[j] += dp1[j-S[i]];
            }
            
        }
        
        return dp1[n];
    
    }



int main(int argc, char const *argv[])
{
    
    
    return 0;
}




