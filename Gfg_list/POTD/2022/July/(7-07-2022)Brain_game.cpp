// https://practice.geeksforgeeks.org/problems/brain-game1742/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




bool brainGame(vector<int>nums) 
{
    // Code here.

    vector<int> arr1(1005,0);
    for(int i1 = 2 ; i1<=1000 ; i1++)
        for(int j1 = 2*i1 ; j1<=1000 ; j1+=i1)
            arr1[j1] = max(arr1[j1],1+arr1[i1]);

    int nas1 = 0 ;
    for(auto x: nums)
        nas1 ^= x ;
    
    if(!nas1)
        return false ;
    return true ;
}


int main(int argc, char const *argv[])
{
    // int n ; cin>>n; 
    vector<int> arr1(1005,0);
    for(int i1 = 2 ; i1<=1000 ; i1++)
        for(int j1 = 2*i1 ; j1<=1000 ; j1+=i1)
            arr1[j1] = max(arr1[j1],1+arr1[i1]);

    cout<<endl ;
    for(auto x : arr1)
        cout<< ","<<x ;

    return 0;
}

