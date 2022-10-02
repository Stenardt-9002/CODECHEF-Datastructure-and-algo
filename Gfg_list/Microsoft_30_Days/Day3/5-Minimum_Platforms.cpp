// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day3/problem/minimum-platforms-1587115620





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    vector<pair<int ,int>>data1 ;
    for (int i1 = 0; i1 < n; i1++)
    data1.push_back({arr[i1] , dep[i1]})     ;

    sort(data1.begin(),data1.end());

    priority_queue<int,vector<int>,greater<int>> heap1 ;     
    int ans1_val = 1 ;
    heap1.push(data1[0].second);
    for(int i1 = 1 ; i1<n ; i1++)
    {
        if(heap1.top()>=data1[i1].first)
            ans1_val++ ;
        else 
            heap1.pop();
        heap1.push(data1[i1].second);
    }
    return ans1_val ;

}



