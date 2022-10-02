// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/implement-atoi









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int atoi(string str) 
{
    //Your code here
    int power = 1 ;
    int ans1 = 0 ;
    for (int i1 = str.size()-1; i1 >=0; i1--)
        if(str[i1]>='0' && str[i1]<='9')
        {
            ans1 += ((str[i1]-'0')*power);
            power*=10 ;
        }
        else if(str[i1]!='-' || (str[i1]=='-'&& i1!=0 ))
            return -1 ;
        else 
            ans1*=-1 ;
        

    return ans1 ;
}



