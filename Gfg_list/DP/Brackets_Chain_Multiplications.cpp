// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1?page=1&difficulty[]=2&status[]=unsolved&category[]=Arrays&category[]=Dynamic%20Programming&sortBy=submissions














#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;


   string matrixChainOrder(int arr[], int n){
        // code here
        n--;
        vector<vector<int>> dp(n,vector<int>(n,1000000000));
       
        vector<vector<string>> ans(n,vector<string>(n,""));
        for(int len=1;len<n+1;len++)
        {
            for(int i=0;i+len<=n;i++)
            {
                if(len==1)
                {dp[i][i]=0;
                ans[i][i]=char('A'+i);
                }
                for(int j=i;j<i+len-1;j++)
                {
                    if(dp[i][i+len-1]>dp[i][j]+arr[i]*arr[j+1]*arr[len+i]+dp[j+1][len+i-1])
                    {
                    dp[i][i+len-1]=dp[i][j]+arr[i]*arr[j+1]*arr[len+i]+dp[j+1][len+i-1];
                    ans[i][i+len-1]="("+ans[i][j]+ans[j+1][len+i-1]+")";
                    }
                }
            }
        }
        return ans[0][n-1];
        
    }
class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        n-- ; 
        vector<vector<int>> dp1(n ,vector<int>(n,INT_MAX) );
        vector<vector<string>> ans(n,vector<string>(n , ""));

        for (int start = 0; start <n; start++)
        {
            dp1[start][start] = 0 ;
            ans[start][start] = char(65+start);
        }

        for (int l = 1; l <= n; l++)
            for (int start = 0; start <=n-l; start++)
                for (int lim = start; lim < start+l-1; lim++)
                    if(dp1[start][start+l-1]>dp1[start][lim]+dp1[lim+1][l+start-1]+p[start]*p[lim+1]*p[start+l])
                    {
                        dp1[start][start+l-1] = dp1[start][lim]+dp1[lim+1][l+start-1]+p[start]*p[lim+1]*p[start+l];
                        ans[start][start+l-1] = "("+ans[start][lim]+ans[lim+1][start+l-1]+")";
                    }

        return ans[0][n-1];
    }
};


// class Solution{
// public:
//     string matrixChainOrder(int p[], int n){
//         // code here
//         vector<vector<int>>dp1(n+1 , vector<int>(n+1,0));
//         vector<vector<int>>save_partition(n+1 , vector<int>(n+1,0));
        

//         for (int l = 1; l <n; l++)
//             for (int start = 1; start <=n-l; start++)
//             {
//                 int end = start+l ; 
//                 int min_val = INT_MAX ;
//                 int get_index = 0 ;
//                 for (int partition = start; partition <end; partition++)
//                     if(min_val>dp1[start][partition]+dp1[partition+1][end]+p[start-1]*p[partition+1]*p[end])
//                     {
//                         min_val = dp1[start][partition]+dp1[partition+1][end]+p[start-1]*p[partition]*p[end];
//                         get_index = partition ;
//                     }

//                 save_partition[start][end] = get_index ;
//                 dp1[start][end] = min_val ;
//             }
            
//         string ans = "(";
//         for (int i = 0; i < n-1; i++)
//             ans+=65+i ;
//         ans+=")";
//         // int i = 3;
//         // while(i<n)
//         // {
//         //     for (int l = 1; l < n-1; l++)
//         //     {
//         //         int min_val = INT_MAX ;
//         //         int index = 1;
//         //         for (int start = 1; start <=n-l; start++)
//         //         {
//         //             if(min_val>dp1[start][start+l])
//         //             {
//         //                 min_val = dp1[start][start+l];
//         //                 index = start+ l ;
//         //             }
//         //         }
//         //         update_string(ans , 65+index-l-1 ,65+index );
//         //     }
            

//         //     i++ ;
//         // }

//         cout<<"DISPLAY\n\n";
//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= n; j++)
//                 cout<<dp1[i][j]<<" ";
//             cout<<endl ;        
//         }

//         cout<<"2 DISPLAY\n\n";
//         cout<<"DISPLAY partition\n\n";
//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= n; j++)
//                 cout<<save_partition[i][j]<<" ";
//             cout<<endl ;        
//         }

//         cout<<"2 DISPLAY\n\n";

//         return ans;
//     }
// };




int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n ; 
        cin>> n;
        int *input = new int[n] ; 
        for (int i = 0; i < n; i++)
            cin>>input[i];
        
        Solution obj1 ;
        cout<<obj1.matrixChainOrder(input , n)<<endl;
        delete []input ;
    }
    

    return 0;
}





