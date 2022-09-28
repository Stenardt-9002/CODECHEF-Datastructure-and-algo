// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    //code here


    map<string,vector<string>> amp1 ;
    for (auto str1 : string_list)
    {
        string comp = str1 ;
        sort(comp.begin(),comp.end());
        if(amp1.find(comp)!=amp1.end())
            amp1[comp].push_back(str1);
        else 
            amp1[comp] = {str1};
    }
    
    vector<vector<string>> ans1 ;
    for (auto key : amp1)
        ans1.push_back(key.second);
    
    return ans1 ;


}





