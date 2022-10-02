// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int maxSubstring(string S)
{
    // Your code goes here
    int current_sum = 0  , max_sum = 0;
    int n = S.size();
    for (int i1 = 0; i1 < n; i1++)
    {
        current_sum+=((S[i1]=='0')?1:-1) ;
        current_sum = max(0, current_sum);
        max_sum = max(max_sum , current_sum);
    }
    
    return max_sum==0 ?-1:max_sum ;
}
int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcase ;
    cin>>testcase ;
    while(testcase--)
    {
        int n ; cin>>n ;
        int w ; cin>>w ;
        int *val = new int[n];
        int *wt = new int[n];

        for (int i1 = 0; i1 < n; i1++)
            cin>>val[i1]     ;

        for (int i1 = 0; i1 < n; i1++)
            cin>>wt[i1]     ;



        // cout<<knapSack(n,w,val,wt)<<endl ;

        delete []val ;delete []wt ;
    }    


    return 0 ;
}


