






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



vector<int> leafNodes(int arr[],int N) 
{
    // code here
    if(N==0)
        return {};

    stack<int> s1;
    vector<int> ans1 ;
    bool ound = true ;
    for (int i1 = 0,j1 = 1; j1 < N;j1++, i1++)
    {
        ound = false ;

        if(arr[i1]>arr[j1])
            s1.push(arr[i1]);

        else 
            while (!s1.empty() )
                if(arr[j1]>s1.top())
                {
                    s1.pop();
                    ound = true ;//found leaf 
                }
                else 
                    break ;
        
        if(ound)
            ans1.push_back(arr[i1]);
    }
    
    ans1.push_back(arr[N-1]);

    return ans1 ;
}








