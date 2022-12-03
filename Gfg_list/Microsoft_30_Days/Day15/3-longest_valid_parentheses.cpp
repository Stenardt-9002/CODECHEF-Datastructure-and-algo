
// https://www.geeksforgeeks.org/check-if-it-is-possible-to-convert-one-string-into-another/
// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day15/problem/longest-valid-parentheses5657




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









int maxLength(string S)
{

    // code here

    int n = S.length();
    stack<int> indeces ;
    int ans1 = 0 ;

    for (int i1 = 0; S[i1]; i1++)
    {
        if(S[i1]=='(')
            indeces.push(i1);
        else 
        {
            if(indeces.size())
                indeces.pop();

            if(indeces.size())
                ans1 = max(ans1 , i1-indeces.top());
            else 
                indeces.push(i1);
        }
    }
    

    return ans1 ;
}