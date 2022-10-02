// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/?page=1&curated[]=2&sortBy=submissions






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef  long long ll1d;


vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here

    long long int cur_suj = arr[0] ;int start = 0 , i1 ;
    for(i1=1 ; i1<=n;i1++)
    {
        while(cur_suj>s && start<i1-1 )
        {
            cur_suj = cur_suj - arr[start];
            start++ ;
        }
        if(cur_suj==s)
            return {start+1,i1};

        if(i1<n)
            cur_suj=cur_suj+arr[i1];
    }
    return {-1};
}



// vector<int> subarraySum(int arr[], int n, long long s)
// {
//     // Your code here
//     int i1 = 0, j1 = 1;
//     vector<long long int >dp1(n,0);
//     dp1[0] = arr[0];
//     for(i1=1;i1<n;i1++)
//     {
//         dp1[i1] = arr[i1]+dp1[i1-1];
//         if(dp1[i1]==s)
//             return {1,i1+1};
//     }
//     i1=0;
//     while(i1<j1 || (dp1[j1]-dp1[i1]==s))
//     {
//         if(dp1[j1]-dp1[i1]==s)
//             return {i1+2,j1+1};
//         else if(dp1[j1]-dp1[i1]>s)
//             i1++; 
//         else 
//             j1++;
//         // cout<<"\nDEBUG"<<i1<<" "<<j1 ;
//     }
//     if(dp1[j1]-dp1[i1]!=s)
//         return {-1} ;
//     return {i1+2,j1+1};

// }




int main(int argc, char const *argv[])
{
    // int s1[] = {1,2,3,7,5};
    // int s1[] = {1,2,3,4,5,6,7,8,9,10};
    int n  ;
    long long int sum ;
    cin>>n>>sum ;
    int *s1 = new int[n];
    for(int i1 = 0 ; i1<n;i1++)
        cin>>s1[i1] ;
    // vector<int> x = subarraySum(s1 , 5, 12);
    vector<int> x = subarraySum(s1 , n ,sum);
    
    // vector<int> x = subarraySum(s1 , 10, 15);

    cout<<endl;
    for(auto y:x)
    cout<<" "<<y;

    return 0;
}


