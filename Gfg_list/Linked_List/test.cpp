   #include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

 
     vector<string> combine(vector<string> first , string word)
    {
        for(int i1 =0 ;i1<first.size();i1++)
            first[i1]+=" "+word;
            
        return first ;
    }

     vector<string> func_m_util(string s ,unordered_map<string,vector<string>> &map1,unordered_set<string> &dict1 )
    {
        if(map1.find(s)!=map1.end())
            return map1[s];
        
        vector<string> ans1 ;
        
        if(dict1.find(s)!=dict1.end())
            ans1.push_back(s) ;
            
        for(int i1=1 ; i1<s.length();i1++)
        {
            string word = s.substr(i1);
            if(dict1.find(word)!=dict1.end())
            {
                string left = s.substr(0,i1);
                vector<string> prev = combine(func_m_util(left,map1,dict1),word);
                left.insert(left.end(),prev.begin(),prev.end());
            }
        }
        map1[s] = ans1 ;
        return ans1 ;
        
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string,vector<string>> map1;
        unordered_set<string> dict1 ;
        
        dict1.insert(dict.begin(),dict.end());
        return func_m_util(s,map1,dict1);
    }