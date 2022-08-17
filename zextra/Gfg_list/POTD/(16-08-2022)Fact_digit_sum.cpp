// https://practice.geeksforgeeks.org/problems/fact-digit-sum4125/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



bool rec_util(int N,vector<int> dp1 ,vector<int>&temp1,vector<int>&ans1)
{
    if(N==0)
    {
        ans1 = temp1 ;
        return true ;
    }
    // bool continueloop = false ;
    // for (int i1 = 9; i1 >=0 && !continueloop; i1--)
    for (int i1 = 9; i1 >=0 ; i1--)

        if(N>=dp1[i1])
        {
            temp1.push_back(i1);
            if(rec_util(N-dp1[i1],dp1,temp1 , ans1))
                return true ;
            temp1.pop_back();
        }
    return false ;    
}



vector<int> FactDigit(int N)
{
    // Code here

    if(N==0)
        return {-1};
    if(N==1)
        return {1};
    if(N==2)
        return {2} ;

    vector<int> dp1(11,1);
    
    for (int i1 = 2; i1 < 10; i1++)
        dp1[i1] = dp1[i1-1]*i1;

    vector<int> ans1 ;
    vector<int> temp1 ;
    rec_util(N,dp1 ,temp1,ans1);
    sort(ans1.begin(),ans1.end());
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
    int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int> output  = FactDigit(n);
        for(auto x:output)
            cout<<x<<" ";
        cout<<endl ;
    }
    return 0 ;
}











