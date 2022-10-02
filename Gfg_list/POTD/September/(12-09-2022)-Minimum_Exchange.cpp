// https://practice.geeksforgeeks.org/problems/distributing-question-papers2513/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int MinimumExchange(vector<vector<char>>matrix)
{
    // Code here
    int n = matrix.size(),m = matrix[0].size();
    int count1 = 0 ,count2 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(matrix[i1][j1]=='A')
            {
                if((i1+j1)%2)
                    count1++ ;
                else 
                    count2++ ;
            }
            else 
            {
                if((i1+j1)%2)
                    count2++ ;
                else 
                    count1++ ;
            }
    // if((m+n)%2)
    //     return count1/2;
    if(count1%2==0)
        count1/=2 ;
    if(count2%2==0)
        count2/=2 ;
            
    return min(count1,count2);
}



