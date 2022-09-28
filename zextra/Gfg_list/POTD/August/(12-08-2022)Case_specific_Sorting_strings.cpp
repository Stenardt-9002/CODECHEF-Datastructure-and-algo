// https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




    string caseSort(string str, int n)
    {
        // your code here
        string strsmall = "",strlarger = "";
        for(int i1 = 0 ; i1<n ; i1++)
            if(str[i1]>='A' && str[i1]<='Z')
                strlarger+=str[i1];
            else
                strsmall+=str[i1] ;
        
        sort(strsmall.begin(),strsmall.end());
        sort(strlarger.begin(),strlarger.end());
        int indexsmall = 0,indexlarger = 0 ;
        for(int i1 = 0 ; i1<n ; i1++)
            if(str[i1]>='A' && str[i1]<='Z')
                str[i1] = strlarger[indexlarger++];
            else
                str[i1] = strsmall[indexsmall++] ;
        return str ; 
        
    }












