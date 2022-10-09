// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day11/problem/stock-buy-and-sell-1587115621







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


// vector<vector<int> > stockBuySell(vector<int> A, int n)
// {
//     // code here
//     vector<vector<int>> asn1 ;
//     int min_now_ind = 0 ;
//     int max_now_ind = 0 ;
//     int stock_val = INT_MIN ;
//     for (int i1 = 1; i1 < n; i1++)
//     {
//         if(A[i1]-A[min_now_ind]>stock_val)
//         {
//             max_now_ind = i1 ;
//             stock_val = A[i1]-A[min_now_ind];
//         }
//         else if(A[i1]<A[min_now_ind])
//         {
//             asn1.push_back({min_now_ind , max_now_ind});
//             stock_val = INT_MIN ;
//             min_now_ind = i1 ;
//         }
//     }
//     return asn1 ;

// }


vector<vector<int> > stockBuySell(vector<int> A, int n)
{
    // code here
        vector<vector<int>> asn1 ;
        int min_now_ind = 0 ;
        int max_now_ind = 0 ;
        int stock_val = INT_MIN ;
        for (int i1 = 1; i1 < n; i1++)
            if(A[i1]-A[i1-1]>0)
                max_now_ind = i1 ;
            else 
            {
                if(max_now_ind>min_now_ind)
                    asn1.push_back({min_now_ind , max_now_ind});
                min_now_ind = i1 ;
            }


        if(max_now_ind>min_now_ind)
            asn1.push_back({min_now_ind , max_now_ind});
        return asn1 ;
}


