

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1



int eggDrop(int n, int k) 
{
    // your code here
   vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0));
   int m = 0; // Number of moves
   while (dp[m][n] < k) {
       m++;
       for (int x = 1; x <= n; x++) {
           dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
       }
   }
   return m;

}



int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
        int n,k;
        cin>>n>>k ;
        cout<<eggDrop(n,k)<<endl;
    }
    return 0;
}
