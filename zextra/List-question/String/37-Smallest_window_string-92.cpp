// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



string smallestWindow (string s, string p)
{
    // Your code here

    int len1 = s.size();
    int len2 = p.size() ;
    if(len1<len2)
        return "-1";

    vector<int> hash_pattern(256,0);
    vector<int> hash_strn(256,0);

    for (int i1 = 0; i1 < len2; i1++)
        hash_pattern[p[i1]]++;

    int start1 = 0,start_indx = -1 , min_len = INT_MAX ;
    int cunt1 =0;
    //travese second string 
    for (int j1 = 0; j1 < len1; j1++)
    {
        hash_strn[s[j1]]++ ;
        if(hash_strn[s[j1]]<=hash_pattern[s[j1]]  ) 
            cunt1++ ;

        if(cunt1==len2)
        {
            while ((hash_strn[s[start1]]>hash_pattern[s[start1]] )|| hash_pattern[s[start1]]==0   )//second case if the character is not in string
            {
                if(hash_strn[s[start1]]>hash_pattern[s[start1]])
                    hash_strn[s[start1]]-- ;
                start1++ ;
            }

            int len_wind = j1-start1+1;
            if(min_len>len_wind)
            {
                min_len = len_wind ;
                start_indx = start1 ;
            }
        }
    }
    if(start_indx==-1)
        return "-1";

    return s.substr(start_indx,min_len);
}











