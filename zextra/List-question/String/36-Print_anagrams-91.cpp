// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);






vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    //code here
    vector<string> copy1 ;
    for (auto x:string_list)
        copy1.push_back(x)    ;

    unordered_map<string,vector<int>> hashp_dup1 ;
    string str1 ;
    for (int i1 = 0; i1 < copy1.size(); i1++)
    {
        sort(copy1[i1].begin(),copy1[i1].end());
        if(hashp_dup1.find(copy1[i1])==hashp_dup1.end())
            hashp_dup1[copy1[i1]] = {i1};
        else 
            hashp_dup1[copy1[i1]].push_back(i1);
    }
    // copy1.clear();
    vector<string> copy2 ;
    for (auto x:string_list)
        copy2.push_back(x)    ;
    
    // sort(copy2.begin(),copy2.end());
    vector<vector<string>> ans1 ; 
    // vector<set<string>> temp1 ;

    string rach_word ;
    for (auto x:copy2)
    {
        rach_word = x ;
        // x.copy(rach_word ,x.size());
        sort(rach_word.begin(),rach_word.end());
        vector<string> temp3 ;
        if(hashp_dup1[rach_word].size()!=0)
        {
            for (auto ind: hashp_dup1[rach_word])
                temp3.push_back(string_list[ind])   ;     
            hashp_dup1[rach_word] = {};
            ans1.push_back(temp3);
        }
    }
    

    // for (auto x : temp1)
    // {
    //     vector<string> temp4 ;
    //     for (auto y : x)
    //         temp4.push_back(y);
    //     ans1.push_back(temp4)        ;
    // }
    return ans1 ;
}



int main(int argc, char const *argv[])
{
    vector<string> input1 = {"act","god","cat","dog","tac"} ;
    vector<vector<string>> ans1 = Anagrams(input1);
    for (auto x : ans1)
        {
            // cout<<endl;
            for(auto y:x)    
            cout<<" "<<y;
        }
    return 0;
}







