// https://leetcode.com/problems/reorganize-string/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

// string reorganizeString(string s) 
// {
//     map<char,int>cunt1 ;
//     int n = s.size();
//     int max1 = INT_MIN ;
//     char charama ;
//     for (int i1 = 0; i1 < s.size(); i1++)
//     {
//         if(cunt1.find(s[i1])==cunt1.end())    
//             cunt1[s[i1]] = 1 ;
//         else 
//             cunt1[s[i1]]++ ;
//         if(max1<cunt1[s[i1]])    
//         {
//             max1 = cunt1[s[i1]] ;
//             charama = s[i1];
//         }
//     }
//     int litmit = ceil(float(n)/2) ;
//     if(cunt1[charama] >litmit)
//         return "";
//     int i1 =0;
//     while(cunt1[charama]!=0)    
//     {
//         s[i1] = charama;
//         cunt1[charama]--;
//         i1+=2;
//     }
//     for (auto x : cunt1)
//         while(cunt1[x.first]!=0)    
//         {
//             if(i1>=s.size())
//                 i1 = 1;
//             s[i1] = x.first;
//             cunt1[x.first]--;
//             i1+=2;

//         }
//     return s ;
// }


string reorganizeString(string s) 
{
    vector<int>cunt1(26,0);
    int n = s.size();
    int max1 = INT_MIN ;
    char charama ;
    for (int i1 = 0; i1 < s.size(); i1++)
    {
        cunt1[s[i1]-'a']++;
        if(max1<cunt1[s[i1]-'a'])    
        {
            max1 = cunt1[s[i1]-'a'] ;
            charama = s[i1];
        }
    }
    int litmit = ceil(float(n)/2) ;
    if(cunt1[charama-'a'] >litmit)
        return "";
    int i1 =0;
    while(cunt1[charama-'a']!=0)    
    {
        s[i1] = charama;
        cunt1[charama-'a']--;
        i1+=2;
    }
    for (int car=0;car<26;car++)
        while(cunt1[car]!=0)    
        {
            if(i1>=s.size())
                i1 = 1;
            s[i1] = car+'a';
            cunt1[car]--;
            i1+=2;
        }
    return s ;
}


int main(int argc, char const *argv[])
{
    cout<<reorganizeString("aab");
    return 0;
}
