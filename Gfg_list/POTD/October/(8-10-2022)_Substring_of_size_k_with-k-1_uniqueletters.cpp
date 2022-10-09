

// https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1



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




int countOfSubstrings(string S, int K) 
{
    int n = S.length();
    vector<int> array(26,0)    ;
    int unique_characters = 0;
    int ans1 = 0 ;
    for (int i1 = 0; i1 < K; i1++)
        if(array[S[i1]-'a']++==0)
            unique_characters++ ;


    for (int i1 = K; i1 < n; i1++)
    {
        if(unique_characters==K-1)
            ans1++ ;
        if(--array[S[i1-K]-'a']==0)
            unique_characters--;
        if(array[S[i1]-'a']++==0)
            unique_characters++ ;

    }
    
    if(unique_characters==K-1)
            ans1++ ;

    // code here
    return ans1 ;
}



