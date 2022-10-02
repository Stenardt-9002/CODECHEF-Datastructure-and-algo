// https://leetcode.com/problems/longest-common-prefix/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

string longestCommonPrefix(vector<string>& strs) 
{
    // string long_prefix = ""    ;
    // int n = strs.size() ;
    // int cur_indx = -1;
    // bool break_var = true ;
    // while(break_var)
    // {
    //     cur_indx++;
    //     for (auto i1 = 1; i1 < n; i1++)
    //     {
    //         if(cur_indx>=strs[0].size()|| cur_indx>=strs[i1].size()|| strs[0][cur_indx]!=strs[i1][cur_indx])
    //             break_var = false;
    //     }
        
    // }
    // long_prefix = strs[0].substr(0,cur_indx);
    // return long_prefix;


    //better method
    int n = strs.size() ;
    if(n==0)
        return "";
    if(n==1)
        return strs[0];

    sort(strs.begin(),strs.end());

    int max_size = min(strs[0].size(),strs[n-1].size());
    int i1 = 0;
    while(i1<max_size && strs[0][i1]==strs[n-1][i1])
        i1++;

    return strs[0].substr(0,i1);
}


int main(int argc, char const *argv[])
{

    vector<string> str = {"ower","flow","flight"};
    cout<<"     "<<longestCommonPrefix(str);


    return 0;
}



