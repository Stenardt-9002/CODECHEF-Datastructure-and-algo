// https://practice.geeksforgeeks.org/problems/find-the-odd-occurence4820/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);

int getOddOccurrence(int arr[], int n) 
{
    // code here
    int j1 =0 ;
    // for(int i1 = 0 ;i1<n ;i1++)
    // {
        
    // }
            int j1 =0 ;
        int res = 0 ;
           for(int i1 = 0 ;i1<n ; i1++)
            res ^= arr[i1];
            
        return res ; 
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;

    }
    return 0 ;
}


