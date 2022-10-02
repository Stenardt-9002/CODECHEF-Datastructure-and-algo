

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







//used in KMP _algo

// int lps(string s) 
// {
//     // Your code goes here

//     int n = s.length() ;
//     if(n<2)   
//         return 0;
//     int len = 0,i1 = 1;
//     while (i1<n)
//     {
//         if (s[i1]==s[len])
//         {
//             len++ ; 
//             i1++ ;
//         }
//         else
//         {
//             i1 = i1-len+1 ;
//             len = 0 ;
//         }
//     }
//     return (len>n/2)? len/2:len;
// }   



vector<int> get_lps(string s)
{
    int n = s.size() ;
    int len = 0;
    vector<int>dp1(n,0) ;
    dp1[0] = 0;
    int i1 = 1 ;
    while (i1<n)
    {
        if (s[i1]==s[len])
            dp1[i1++] = ++len ;

        else
        {
            if(len!=0)
                len = dp1[len-1] ;//where last search ptr is
            else 
                dp1[i1++] = 0;// no match
        }   
    }
    return dp1 ;
}




void KMP_Search(string pat , string txt )
{
    int n = txt.size() ;
    int m = pat.size() ;


    vector<int> lps = get_lps(pat) ; //longest prefix suffix array
    int i1 = 0,j1=0;//i1 for txt and j1 for pattern
    while (i1<n)
    {
        if(pat[j1]==txt[i1])
        {
            j1++; i1++;
        }


        if(j1==m)
        {
            cout<<endl<<"Found Pattern at "<<i1-j1<<endl ;
            j1 = lps[j1-1] ;
        }
        else if (i1<n && pat[j1]!=txt[i1])
        {
            if(j1!=0)
                j1 = lps[j1-1] ;
            else 
                i1++ ;
        }   
    }
}














