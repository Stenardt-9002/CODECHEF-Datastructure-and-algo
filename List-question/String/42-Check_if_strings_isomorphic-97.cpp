
// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


// bool areIsomorphic(string str1, string str2)
// {
    
//     // Your code here
//     if(str1.size()!=str2.size())
//         return false ;

//     long long i1,n = str1.size();
//     // map<char,char> hashp_map ;

//     // for (ll1d i1 = 0; i1 < n; i1++)
//     // {
//     //     if(hashp_map.find(str1[i1])== hashp_map.end())
//     //         hashp_map[str1[i1]] = str2[i1] ;
//     //     else if(hashp_map[str1[i1]] != str2[i1])
//     //         return false ;
//     // }
//     // return true ;

//     int count1[52];
//     int count2[52];
//     for ( i1 = 0; i1 < 52; i1++)
//     {
//         count1[i1] = 0;count2[i1] = 0;
//     }
    

//     for ( i1 = 0; i1 < n; i1++)
//     {
//         count1[str1[i1]-'a']++ ;
//         count2[str2[i1]-'a']++ ;
//     }
    
//     for ( i1 = 0; i1 < n; i1++)
//     if(count1[str1[i1]-'a']!=count2[str2[i1]-'a'])
//         return false ;

//     return true ;
// }

    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size())
            return false ;
        int i1,n = s.size();
        map<char,char> hashp_map ;
        map<char,char> hashp_map2 ;
        for (i1 = 0; i1 < n; i1++)
        {
            if(hashp_map.find(s[i1])== hashp_map.end()&&hashp_map2.find(t[i1])== hashp_map2.end())
            { 
                hashp_map[s[i1]] = t[i1] ;
                hashp_map2[t[i1]] = s[i1] ;
            }        
            else if((hashp_map.find(s[i1])!= hashp_map.end() && hashp_map[s[i1]] != t[i1])||(hashp_map2.find(t[i1])!= hashp_map2.end() && hashp_map2[t[i1]] != s[i1])||(hashp_map2.find(t[i1])== hashp_map2.end())||(hashp_map.find(s[i1])== hashp_map.end()) )
                return false ;
        }
        return true ;
    }



int main(int argc, char const *argv[])
{
    // string a1 = "bbbaaaba";
    // string b1 = "aaabbbba";
    string a1 = "badc";
    string b1 = "baba";
    cout<<endl<<isIsomorphic(a1,b1);

    return 0;
}










