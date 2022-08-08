// https://leetcode.com/problems/combination-sum-iv/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int combinationSum4(vector<int>& nums, int target) 
{
    
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcase ;
    // cin>>testcase ;
    testcase = 1;
    while(testcase--)
    {
        int n ; cin>>n ;
        int target ; 
        cin>>target ;
        vector<int>val(n);
        for (int i1 = 0; i1 < n; i1++)
            cin>>val[i1]     ;

        

        cout<<endl<<combinationSum4(val , target);

    }    


    return 0 ;
}


