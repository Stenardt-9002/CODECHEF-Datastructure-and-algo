// https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int bullshit(int arr[] , int ele_to_search , int m)
{
    int low = 0 ; int high = m-1 ;
    while(low<=high)
    {
        int mid = (low+high)>>1 ;
        if(arr[mid]<=ele_to_search)
            low = mid+1 ;
        else 
            high = mid-1 ;
    }
    return high  ;
}
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
    //Your code goes here
    sort(arr2,arr2+n);
    vector<int> ans1 ; 
    for(int i1 = 0 ; i1<m ; i1++)
        ans1.push_back(bullshit(arr2 , arr1[i1] , n)+1);

    return ans1 ;
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
        cin>>n ;
        int *ar1 = new int[n]   ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>ar1[i1];
        cin>>m ;
        int *ar2 = new int[m]   ;
        for (int i1 = 0; i1 < m; i1++)
            cin>>ar2[i1];
        for(auto x : countEleLessThanOrEqual(ar1 ,ar2 , n ,m))
            cout<<x<<" " ; 
        cout<<endl;
    }
    return 0 ;
}




