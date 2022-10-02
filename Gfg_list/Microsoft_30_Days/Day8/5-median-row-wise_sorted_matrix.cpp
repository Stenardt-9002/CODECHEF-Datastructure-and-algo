// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day8/problem/median-in-a-row-wise-sorted-matrix1527


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

const long long int mod2 =  1e18 ;


int median(vector<vector<int>> &matrix, int r, int c)
{
    // code here      
    int low1 = INT_MAX ; int high1 = INT_MIN ;
    for (int i1 = 0; i1 < r; i1++)
    {
        low1 = min(low1,matrix[i1][0] );
        high1 = max(high1 , matrix[i1][c-1]);
    }


    while (low1<high1)
    {
        int mid = (low1+high1)>>1;
        int count_til = 0 ;
        for (int i1 = 0; i1 < r; i1++)
            count_til+=(upper_bound(matrix[i1].begin() ,matrix[i1].end() , mid)-matrix[i1].begin() );


        if(count_til<((r*c+1)/2))
            low1 = mid+1 ;
        else 
            high1 = mid ;

    }
    
    return low1 ;
        

}


