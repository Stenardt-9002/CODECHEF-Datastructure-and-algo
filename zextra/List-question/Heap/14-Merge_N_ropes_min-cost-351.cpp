// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1       
    
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);





long long minCost(long long arr[], long long n) 
{
    // Your code here
    vector<long long> heap1 ;
    for (long long i1 = 0; i1 < n; i1++)
        heap1.push_back(arr[i1])    ;


    make_heap(heap1.begin(),heap1.end(),greater<long long>());
    // cout<<endl ;
    // for (auto x : heap1)
    //     cout<<" "    <<x ;
    // cout<<endl ;
    long long sum1 = 0,first_al=0,second_val = 0;
    while (heap1.size()!=1)
    {
        first_al = heap1.front();
        second_val = 0;
        pop_heap(heap1.begin(),heap1.end(),greater<long long>());
        heap1.pop_back();
        if(!heap1.empty())
        {
            second_val = heap1.front();
            pop_heap(heap1.begin(),heap1.end(),greater<long long>());
            heap1.pop_back();
        }
        // cout<<"BUG DE"<<first_al<<" "<<second_val<<endl;
        first_al = first_al+second_val ;
        sum1+=first_al ;
        heap1.push_back(first_al) ;
        push_heap(heap1.begin(),heap1.end(),greater<long long>());
    }
    return sum1 ;
}

int main(int argc, char const *argv[])
{
    ll1d n;cin>>n;
    ll1d *arr1 =     new ll1d[n];
    for (ll1d i = 0; i < n; i++)
        cin>>arr1[i]    ;
    cout<<endl;
    cout<<" "<<minCost(arr1,n);
    delete[]arr1;
    return 0;
}



