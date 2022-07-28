// https://practice.geeksforgeeks.org/problems/adding-array-element4756/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
int knots(int M, int N, int K)
{
    // code here
        vector<vector<long long int>> possib(max(M,N)+1,vector<long long int>(max(M,N)+1 , 0));
        int MOD1 = 1000000007;
        int ans1 = 1 ;
        for (int i1 = 0; i1 <= max(N,M); i1++)
        {
            possib[i1][0] = 1;
            possib[i1][i1] = 1;
            for(int j1=1;j1<i1 ; j1++)
                possib[i1][j1] = ((possib[i1-1][j1]%MOD1)+(possib[i1-1][j1-1]%MOD1))%MOD1;
        }
            
        ans1 = (possib[N][K]*possib[M][K])%MOD1;
        return ans1 ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
        int n,m,k ;
        cin>>m>>n>>k ;
        cout<<endl<<knots(m,n,k);
    }
    return 0;
}

