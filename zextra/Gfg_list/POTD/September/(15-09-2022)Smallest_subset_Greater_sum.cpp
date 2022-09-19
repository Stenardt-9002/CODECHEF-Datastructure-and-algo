// https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1











#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int minSubset(vector<int> &Arr,int N)
{
    long long int sum1 = 0 ;
    int i1 = 0 ;
    for( i1 = 0 ;i1<N ;i1+=1)
        sum1+=Arr[i1];
    sum1/=2;
    sort(Arr.begin(),Arr.end() ,greater<int>());
    long long int newsum = 0 ;
    i1 = 0 ;
    while (i1<N && newsum<=sum1)
        newsum+=Arr[i1++];

    return i1 ;

}





