    
    

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1


#include "bits/stdc++.h"

using namespace std;



    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        vector<vector<int>>dp1(n);
        for(int i1=0;i1<n;i1++)
        {
            vector<int> a1(m,0) ;
            dp1[i1] = a1;
        }
        //base case 
        for(int i1=0;i1<n;++i1){dp1[i1][0]=mat[i1][0] ;}
        for(int i1=0;i1<m;++i1){dp1[0][i1]=mat[0][i1] ;}
        
        
        //recursive
        for(int i1 = 1;i1<n;i1++)
        {
            for(int j1=1;j1<m;++j1)
            {
                if(mat[i1][j1])//if 1 then possibility of being square
                dp1[i1][j1] = 1+min({dp1[i1-1][j1-1],dp1[i1-1][j1],dp1[i1][j1-1]});
                else
                dp1[i1][j1] = 0;
            }
        }
        
        int max_val = INT_MIN ;
        for(int i1 = 0;i1<n;i1++)
        for(int k1 = 0;k1<m;k1++)
            max_val = max(max_val,dp1[i1][k1]);
        return max_val ;
    }



int main(int argc, char const *argv[])
{
    int n,m;

    cin>>n>>m ;
    int temp1 ;
        vector<vector<int>>arr1(n);
        for(int i1=0;i1<n;i1++)
        {
            vector<int> a1(m,0) ;
            arr1[i1] = a1;

            for (int j1 = 0; j1 < m; j1++)
            {
                cin>>temp1 ;
                arr1[i1][j1] = temp1;
            }
        }
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     for (int j1 = 0; j1 < m; j1++)
    //     {
    //         cin>>arr1[i1][j1];
    //     }
        
    // }
    //     for (int i1 = 0; i1 < n; i1++)
    // {   
    //     cout<<endl;
    //     for (int j1 = 0; j1 < m; j1++)
    //     {
    //         cout<<" "<<arr1[i1][j1];
    //     }
        
    // }
    

    return 0;
}




