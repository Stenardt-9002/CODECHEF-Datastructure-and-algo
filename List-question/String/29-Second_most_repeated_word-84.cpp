// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


string secFrequent (string arr[], int n)
{
    map<string,int> dic_T;
    for (int i1 = 0; i1 < n; i1++)
    {
        if(dic_T.find(arr[i1])==dic_T.end())
            dic_T[arr[i1]]=1;
        else
            dic_T[arr[i1]]+=1;
    }
    string second_max ;
    int first_max = INT_MIN ,sec_max = INT_MIN ;
    for (auto x : dic_T)
    {
        if(x.second>first_max)
        {
            sec_max = first_max;
            first_max = x.second ;
        }
        else if(x.second>sec_max && x.second!=first_max)
            sec_max = x.second ;
    }
    
    for(auto x : dic_T)
        if(x.second==sec_max)
            second_max = x.first ;

    return second_max ;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}





