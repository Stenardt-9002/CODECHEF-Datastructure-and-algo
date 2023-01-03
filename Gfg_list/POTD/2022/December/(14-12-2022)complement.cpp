// https://practice.geeksforgeeks.org/problems/complement3911/1


    










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;












vector<int> findRange(string str, int n) 
{
    // code here
    bool found_0 = true ; 
    for(int i =0 ;str[i] ; ++i)
        if(str[i]=='0')
            found_0 = false ;

    if(found_0)
        return {-1};
    int max_length = 0, max_count_0 = 0 , ans_start_index = -1 ;
    int cur_count_0 = 0 ;

    int first_ptr = 0 , second_ptr = 0;
    while (second_ptr<n)
    {
        cur_count_0+=(str[second_ptr]=='1')?-1:1;
        if(cur_count_0<0)
        {
            cur_count_0 = 0 ;
            first_ptr = second_ptr+1 ;
        }
        if(cur_count_0>max_count_0)
        {
            ans_start_index = first_ptr ;
            max_length = second_ptr-first_ptr ;
            max_count_0 = cur_count_0 ;
        }
        second_ptr++ ;
    }
    
    return {ans_start_index+1 , ans_start_index+1+max_length};

}





