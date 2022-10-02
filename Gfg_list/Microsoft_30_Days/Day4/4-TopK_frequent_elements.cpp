// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day4/problem/top-k-frequent-elements-in-array







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool compardre_fuc(pair<int,int> a1 , pair<int,int> b1)
{
    if(a1.second==b1.second)
        return a1.first>b1.first ;
    return a1.second>b1.second ;
}

vector<int> topK(vector<int>& nums, int k) 
{
    // Code here
    map<int,int> map1 ;

    for(auto x:nums)
        map1[x]++ ;

    vector<pair<int,int>> map2(map1.begin(),map1.end()) ; 
    // for(auto x : map1)
    //     map2.push_back({x.first , x.second});
    sort(map2.begin(),map2.end(),compardre_fuc);
    vector<int> ans1 ; 
    vector<pair<int, int>> ::iterator i = map2.begin();
    for (int i1 = 0 ; i1 < k&& i!=map2.end(); i1++,i++)
        ans1.push_back(i->first);
    
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
    // ll n ;
    int n , k; 
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int>array_in(n,0);
        for(int i1 = 0 ; i1<n;i1++)
            cin>>array_in[i1] ;
        cin>> k ;
        vector<int> oputut = topK(array_in,k);
        for(auto ot:oputut)
            cout<<ot<<" ";
        cout<<endl ;
    }
    return 0 ;
}

