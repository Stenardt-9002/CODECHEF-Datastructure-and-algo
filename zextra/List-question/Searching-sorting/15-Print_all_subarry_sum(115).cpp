
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll;

// ll findSubarray(vector<ll> arr, int n ) 
// {
//     //code here
//     unordered_map<ll,ll> dict_1 ; 
//     long long int sum_val = 0;
//     ll ans1 = 0 ;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         sum_val+=arr[i1];

//         // if(sum_val==0)
//         //     ans1++ ;

//         if(dict_1.find(sum_val)!=dict_1.end())
//             dict_1[sum_val]++;
//         else 
//             dict_1[sum_val]=1;
        
//     }
//     for(auto x : dict_1)
//         if(x.second>1 && x.first!=0)
//             ans1+=((x.second*(x.second-1))/2);
    

//     return ans1;
// }


ll findSubarray(vector<ll> arr, int n ) 
{
    //code here
    unordered_map<ll,vector<ll>> dict_1 ; 
    vector<pair<int,int>> out ;
    long long int sum_val = 0;
    ll ans1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        sum_val+=arr[i1];

        if(sum_val==0)
            out.push_back({0,i1});

        if(dict_1.find(sum_val)!=dict_1.end())
        {
            vector<ll> temp1 = dict_1[sum_val];
            for(auto it : temp1)
                out.push_back({it+1,i1});
        }
        dict_1[sum_val].push_back(i1);
    }
    for(auto x : out)
        ans1++;
    

    return ans1;
}



int main(int argc, char const *argv[])
{
    vector<ll>arr1 = {6,-1,-3,4,-2,2,4,6,-12,-7}    ;
    // vector<ll>arr1 = {0,0,5,5,0,0}    ;

    int n = arr1.size();
    cout<<" "<<findSubarray(arr1,n);
    return 0;
}
