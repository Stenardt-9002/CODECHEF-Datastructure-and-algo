// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day4/problem/c565fe576fadbe605488f2b6b20d11a72005b381




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


bool comapre_d(vector<int> a1 , vector<int> b1)
{
    return a1[0]<b1[0];
}

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
{
    //Your code here
    
    sort(intervals.begin(),intervals.end(),comapre_d);
    vector<vector<int>>ans1 ;
    int size1= intervals.size(); 
    ans1.emplace_back(intervals[0]);
    int last = 0 ;
    for(int i1 = 1 ; i1<size1 ; i1++)
    {
        vector<int> current = ans1[last];
        if(intervals[i1][0]<=current[1])
        {
            current[0] = min(current[0], intervals[i1][0]);
            current[1] = max(current[1], intervals[i1][1]);
            ans1[last] = current ;
        }
        else 
        {
            ans1.emplace_back(intervals[i1]);
            last++ ;
        }
    }


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
    ll n ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        ll *array_in = new ll[n];
        for(ll i1 = 0 ; i1<n;i1++)
            cin>>array_in[i1] ;
        cout<<endl ;
    }
    return 0 ;
}

