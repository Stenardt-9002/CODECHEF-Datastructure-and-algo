// https://practice.geeksforgeeks.org/problems/904237fa926d79126d42c437802b04287ea9d1c8/1





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;




int minLength(string s, int n) 
{
        // code here
    set<string> s1 = {"12","21","34","43","56","65","78","87","09","90"};
    string ans1 = "";
    int i1 = 0 ;
    stack<string> stack1 ;

    for (int i1 = 0; i1 < n; i1++)
    {
        stack1.push(s.substr(i1,1));
        bool flag_not_foud = true ;
        while(stack1.size()>=2 && flag_not_foud)
        {
            string temp = stack1.top();
            stack1.pop();
            string temp2 = stack1.top();
            stack1.pop();

            string top = temp2+temp ;
            if(s1.find(top)==s1.end() )
            {
                flag_not_foud = false ;
                stack1.push(top.substr(0,1));
                stack1.push(top.substr(1,1));
            }

        }
    }
    
    return stack1.size() ;

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
        string inpuit1 ;
        cin>>inpuit1;
        cout<<minLength(inpuit1 , n)<<endl;
    }
    return 0 ;
}





