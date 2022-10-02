// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1











#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


string findSum(string X, string Y) 
{
    // Your code goes here
    int length1 = X.size()-1;
    int length2 = Y.size()-1;
    string ans1 = "";
    int i1 = length1 ,j1 = length2 ;
    int carry = 0 ;
    while(i1>=0 && j1>=0)
    {
        int value = (X[i1--]-'0')+(Y[j1--]-'0')+carry;
        carry = value/10 ;
        value = value%10 ;
        char a1 = value+'0';
        ans1 = a1+ans1;
    }

    while(i1>=0)
    {
        int value = (X[i1--]-'0')+carry;
        carry = value/10 ;
        value = value%10 ;
        char a1 = value+'0';
        ans1 = a1+ans1;
    }
    while(j1>=0)
    {
        int value = (Y[j1--]-'0')+carry;
        carry = value/10 ;
        value = value%10 ;
        char a1 = value+'0';
        ans1 = a1+ans1;
    }

    if(carry!=0)
    {
        char a1 = carry+'0';
        ans1 = a1+ans1;
    }
    string ans2 = "";
    //removing 0 from start
    i1 = 0 ;
    bool  breakflag = true ;
    for(i1 = 0 ;i1<ans1.size() && breakflag;i1++)
        if(ans1[i1]!='0')
            breakflag = false ;
    if(breakflag && i1== ans1.size())
        return "0" ;
    
    ans2 = ans1.substr(i1-1,ans1.size()-i1+1);
    return ans2 ;   

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
        string s1 , s2 ;        
        cin>>s1>>s2 ;
        cout<<findSum(s1,s2)<<endl ;
    }
    return 0 ;
}








