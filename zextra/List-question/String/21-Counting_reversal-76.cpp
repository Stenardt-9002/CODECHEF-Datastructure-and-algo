// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




int countRev (string s)
{
    // your code here


    int n = s.size();
    int left_br_cnt = 0,right_br_cnt = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        if (s[i1]=='{')
            left_br_cnt++;
        else
        {
            if(left_br_cnt==0)
                right_br_cnt++;
            else
                left_br_cnt-- ;
        }
    }
    return ceil(left_br_cnt/2)+ceil(right_br_cnt/2) ;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}






