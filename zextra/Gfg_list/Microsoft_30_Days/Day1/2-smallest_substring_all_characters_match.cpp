// https://practice.geeksforgeeks.org/batch-problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





string smallestWindow (string s, string p)
{
    // Your code here

    vector<int> array_hash(256,0);
    int individual_counter = 0 ;
    //preprocess p 
    for (auto ch : p)
        if(array_hash[ch]++==0)
            individual_counter++ ;
    

    int n = s.size();
    int first_ptr = 0 , second_ptr = 0;
    int ans_length = INT_MAX ;
    int firstindex = 0 ;
    while (second_ptr<n)
    {
        if(--array_hash[s[second_ptr]]==0)
            individual_counter-- ;
        
        while(individual_counter==0)
        {
            if(second_ptr-first_ptr<ans_length)
            {
                ans_length = second_ptr-first_ptr ;
                firstindex = first_ptr ;
            }
            if(array_hash[s[first_ptr]]++==0)
                individual_counter++ ;
            first_ptr++ ;
        }
        second_ptr++ ;
    }
    
    if(ans_length==INT_MAX)
        return "-1" ;
    
    return s.substr(firstindex , ans_length+1);

}




