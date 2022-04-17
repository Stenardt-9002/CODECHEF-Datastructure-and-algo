    
    

// https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




string removeConsecutiveCharacter(string S)
{
    // code here.
    if(S.size()==0)
        return "" ;
    string str1 = S.substr(0,1) ;
    int j1 = 0 ;
    for (int i1 = 1; i1 < S.size(); i1++)
    {
        if(S[i1]==str1[j1])
            continue;
        else 
        {
            str1+=S[i1];
            j1++ ;
        }
    }
    return str1 ;
}








