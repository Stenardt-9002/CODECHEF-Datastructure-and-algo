// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1





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























	void shortest_distance(vector<vector<int>>&matrix)
	{
	    // Code here
	    int n = matrix.size();
	    int i , j , k ;
	    for(k=0 ; k<n ; k++)
	    {
	        for(i=0;i<n;i++)
	        {
	            for(j=0;j<n;++j)
	            {
	                if(matrix[k][j]!=-1 && matrix[i][k]!=-1 )
	                {
	                    if(matrix[i][j]==-1)
	                    matrix[i][j] = matrix[k][j]+matrix[i][k] ;
	                    else 
	                    matrix[i][j] = min(matrix[i][j] ,matrix[k][j]+matrix[i][k] );
	                }
	            }
	        }
	    }
	}