

// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;















// int lps(string s) 
// {
//     // Your code goes here

//     int n = s.length() ;
//     int dp1[n] ;
//     dp1[0] = 0;
//     int len = 0,i1 = 1;
//     while (i1<n)
//     {
//         if (s[i1]==s[len])
//         {
//             len++ ; dp1[i1] = len ;
//             i1++ ;
//         }
//         else
//         {
//             if (len!=0)
//                 len = dp1[len-1]             ;
            
//             else
//             {
//                 dp1[i1] = 0;i1++ ;
//             }
//         }
//     }
//     int res = dp1[n-1] ;
//     return (res>n/2)? res/2:res;
// }   









int lps(string s) 
{
    // Your code goes here

    int n = s.length() ;
    if(n<2)   
        return 0;
    int len = 0,i1 = 1;
    while (i1<n)
    {
        if (s[i1]==s[len])
        {
            len++ ; 
            i1++ ;
        }
        else
        {
            i1 = i1-len+1 ;
            len = 0 ;
        }
    }
    return (len>n/2)? len/2:len;
}   




