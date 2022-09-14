// https://practice.geeksforgeeks.org/problems/power-of-2-and-subsequences0759/1










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





long long numberOfSubsequences(int N, long long A[])
{
    // code here
    // long long int power2a = 1<<63 ; 
    long long int power2a = pow(2,62) ; 

    int MOD1 = 1000000007;
    int number_of_2_counts = 0 ;
    for (int i1 = 0; i1 < N; i1++)
        if(power2a%A[i1]==0)
            number_of_2_counts++ ;

    long long int ans1 = 1 ;
    for (int i1 = 0; i1 < number_of_2_counts; i1++)
        ans1*=2 ,ans1 = ans1%MOD1;    

    return ans1-1;

    
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        long long *A1 = new long long[n];
        for (int i1 = 0; i1 < n; i1++)
            cin>>A1[i1];
        
        cout<<numberOfSubsequences(n,A1)<<endl;
        delete []A1;
    }
    return 0 ;
}

