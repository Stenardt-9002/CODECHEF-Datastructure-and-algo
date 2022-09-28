// https://practice.geeksforgeeks.org/problems/license-key-formatting/1





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

// string ReFormatString(string S, int K)
// {
//     int n = S.length()-1;
//     string ans1 = "";
//     int current = K ;
//     while(n>=0)
//     {
//         if(S[n]!='-')
//         {
//             ans1 = (char)toupper(S[n])+ans1 ;
//             current-- ;
//             if(current==0) 
//             {
//                 current = K ;
//                 ans1 = "-"+ans1 ;
//             }
//         }
//         n--;
//     }
//     if(ans1[0]=='-')
//         ans1 = ans1.substr(1);
//     return ans1 ;    
// }


// string ReFormatString(string S, int K)
// {
//     int n = S.length()-1;
//     string S1 = "";
//     for (int i1 = 0; i1 <=n; i1++)
//         if(S[i1]!='-')    
//             S1 = S1+S[i1];

//     // return S1 ;
//     string ans1 = "";
//     n = S1.length()-1;
//     int current = K ;
//     while(n>=0)
//     {
        
//         ans1 = (char)toupper(S1[n])+ans1 ;
//         current-- ;
//         if(current==0) 
//         {
//             current = K ;
//             ans1 = "-"+ans1 ;
//         }
    
//         n--;
//     }
//     if(ans1[0]=='-')
//         ans1 = ans1.substr(1);
//     return ans1 ;    
// }

string ReFormatString(string S, int K)
{
    int len = S.length(),cnt = 0, x = 0;
 
    for (int i = len - 1; i >= 0; i--) 
        if (S[i] == '-') 
            x++;
        else 
            S[i + x] = toupper(S[i]);
 
    int slen = len - x, step = slen / K, val = x;
    reverse(S.begin(), S.end());
    while (val--) 
        S.pop_back();
    
    int temp = step;
    while (temp--)
        S.push_back(' ');
    reverse(S.begin(), S.end());
 
    len = S.length();
    int i = slen, j = step, f = 0;
    
    while (j < len) 
    {
        step = i / K;
        if (f == 1)
            step--;
        int rem = i % K;
 
        if (rem == 0 and f == 0) 
        {
            S[j - step] = '-';
            f = 1;
            continue;
        }
        S[j - step] = S[j];
        i--;
        j++;
        f = 0;
    }
 
    len = S.length();
    reverse(S.begin(), S.end());
    for (int i = len - 1; i >= 0; i--) 
    {
        if (S[i] != '-') 
            break;

        if (S[i] == '-')
            S.pop_back();
    }
    reverse(S.begin(), S.end());
 
    return S;   
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
        string inpuit1 ;
        cin>>inpuit1>>n ;
        cout<<ReFormatString(inpuit1 , n)<<endl;
    }
    return 0 ;
}



