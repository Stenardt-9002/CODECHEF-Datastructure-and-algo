// https://practice.geeksforgeeks.org/problems/8d157f11af5416087251513cfc38ffc4d23be308/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




class Solution
{
public:

    static bool cmp(string a , string b)
    {
        if(a.length()!=b.length())
            return a.length()<b.length();
        return a>b;
    }



    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string,int> map1 ;
        int n = words.size();
        for (int i = 0; i < n; i++)
            map1[words[i]]++;


        sort(words.begin() , words.end() , cmp);
        for (int i = n-1 ; i >= 0; i--)
        {
            int curl = words[i].length();
            bool var = true ;
            string temp = "";
            for (int it = 0; it < curl && var; it++)
            {
                temp+=words[i][it];
                if(map1[temp]==0)
                    var = false;
            }
            if(var)
                return words[i];
        }
        return "";
    }
};
