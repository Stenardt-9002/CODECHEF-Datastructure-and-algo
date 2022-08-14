// https://practice.geeksforgeeks.org/batch-problems/array-pair-sum-divisibility-problem3257/0/?track=microsoft-29days-day2&batchId=636



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



// bool canPair(vector<int> nums, int k) 
// {
//     // Code here.
//     int n = nums.size();
//     if(n%2==1)
//         return false ;
//     unordered_map<int,int> map1 ;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         int rema = nums[i1]%k ;
//         if((rema!=0 && (map1.find(k-rema)!=map1.end())) || (rema==0 && (map1.find(k-rema)!=map1.end()) ))
//             map1.erase(k-rema);
//         else if(rema==0 && (map1.find(0)!=map1.end()) )
//             map1.erase(0);
//         else 
//             map1[rema] = 1;

//         // cout<<endl<<"DEBUG ";
//         // for(auto x : map1)
//         //     cout<<x.first<<" ";
//         // cout<<endl<<"DEBUGEND1";
//     }
//     return (map1.size()==0);
// }
//better map approach 
bool canPair(vector<int> nums, int k) 
{
    // Code here.
    int n = nums.size();
    if(n%2==1)
        return false ;
    vector<int>map1(k,0) ;
    for (int i1 = 0; i1 < n; i1++)
        map1[nums[i1]%k]++ ;


    if(map1[0]%2!=0)
        return false ;
    for (int i1 = 1; i1 <= k/2; i1++)
        if(map1[i1]!=map1[k-i1])
            return false ;

    return true;
}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n , k;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int>array_in(n,0);
        cin>>k ;
        for(int i1 = 0 ; i1<n;i1++)
            cin>>array_in[i1] ;
        cout<< canPair(array_in,k);
        cout<<endl ;
    }
    return 0 ;
}

