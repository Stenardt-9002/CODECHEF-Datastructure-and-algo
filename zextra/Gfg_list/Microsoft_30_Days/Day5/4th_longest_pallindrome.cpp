// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/longest-palindrome-in-a-string3411









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




string longestPalin (string S) 
{
        // code here
    int n = S.length();
    vector<vector<bool>>dp1(n , vector<bool>(n,false));
    for (int i1 = 0; i1 < n; i1++)
        dp1[i1][i1] = true ; 
    int lowpt = 0 ; 
    int max_le = 1 ;
    for (int i1 = 0; i1 < n-1; i1++)
        if(S[i1]==S[i1+1] )   
        {
            dp1[i1][i1+1] = true ;
            if(max_le<2)
                max_le = 2 , lowpt = i1 ;
        }
    
    for (int leng = 3; leng <=n; leng++)
        for (int star = 0; star <=n-leng; star++)
            if(S[star]==S[star+leng-1] && dp1[star+1][star+leng-2])
            {
                dp1[star][star+leng-1] = true ;
                if(max_le<leng)
                {
                    max_le = leng ; 
                    lowpt = star ;
                }
            }
    
    return S.substr(lowpt , max_le);

}




int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    ll n ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        string a , b;
        cin>>a ;
        cout<<longestPalin(a);
        cout<<endl ;
    }
    return 0 ;
}














