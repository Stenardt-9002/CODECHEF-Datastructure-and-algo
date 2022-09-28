// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int smallestSumSubarray(vector<int>& a)
{
    //Code here
    int n = a.size();
    int min_sum = -a[0] ;
    int curr_sum = -a[0];
    for(int i1 = 1 ; i1< n ; i1++)
    {
        // curr_sum+=(-a[i1]);
        curr_sum = max(-a[i1] , curr_sum-a[i1]);
        min_sum = max(min_sum,curr_sum);
    }
    return -min_sum ;
}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        int size1 ;
        cin>>size1 ;
        int value ;
        vector<int> intup ;
        while(size1--)
        {
            cin>>value ;
            intup.push_back(value);
        }
        cout<<smallestSumSubarray(intup);     
    }
    return 0 ;
}





