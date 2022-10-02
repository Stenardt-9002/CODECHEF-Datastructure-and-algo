// https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



int main() 
{
    int testcases ;
    string str1 ;
    cin>>testcases ;
    while (testcases--)
    {
        map<char,int> has_map ;
        string input_1 ; 
        cin>> input_1 ;
        int n = input_1.length();
        for (int i1 = 0; i1 < n; i1++)
            if(has_map.find(input_1[i1])==has_map.end())   
                has_map[input_1[i1]] = 1;
            else 
                has_map[input_1[i1]]++;

        int min_cunt = 0;
        for (auto x: has_map)
            if(x.second>min_cunt)
                min_cunt = x.second;
                
        if(min_cunt<=ceil(n/2))
            cout<<"1\n";
        else 
            cout<<"0\n";
    }
	return 0;
}



