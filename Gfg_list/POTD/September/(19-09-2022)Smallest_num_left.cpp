

// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1






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

const long long int mod2 =  1e18 ;


vector<int> leftSmaller(int n, int a[])
{
    // code here
    if(n==0)
        return {};
    if(n==1)
        return {-1};
    
    vector<int> ans1(n,-1);
    stack<int> indexes ;


    for(int i1 = 0 ; i1<n ; i1++)
    {
        while (!indexes.empty() && indexes.top()>=a[i1])
            indexes.pop();

        if(!indexes.empty())
            ans1[i1] = indexes.top() ;            
            
        indexes.push(a[i1]);
        
    }
    return ans1 ;



    // int i1 = n-2 ;
    // int lastindx = n-1 ;
    // indexes.push(n-1);
    // while(i1>=0)
    // {
    //     if(indexes.empty() || a[i1]>=a[indexes.top()])
    //         indexes.push(i1);

    //     else 
    //     {
    //         ans1[lastindx] = a[i1];
    //         indexes.pop();
    //         while(!indexes.empty() && a[i1]<a[indexes.top()])
    //         {
    //             lastindx = indexes.top();
    //             indexes.pop();
    //             ans1[lastindx] = a[i1];
    //         } 
    //     }
    //     i1--;
    // }
    // return ans1 ;


}



