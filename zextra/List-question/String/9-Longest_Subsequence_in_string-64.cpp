	
    



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;





    int LongestRepeatingSubsequence(string str)
		{
		    int n = str.length();
		    int dp1[n+1][n+1];
		    for(int i1=0;i1<n+1;i1++)
		        dp1[0][i1] = dp1[i1][0] = 0;//0 common
		    
		    for(int i1 =1;i1<=n;i1++)
            {
                for(int j1 =1;j1<=n;j1++)
                {
                    if(str[i1-1]==str[j1-1] &&i1!=j1)
                    {
                        dp1[i1][j1] = dp1[i1-1][j1-1]+1 ;//length of word 
                    }
                    else
                    {
                        dp1[i1][j1] = max(dp1[i1-1][j1],dp1[i1][j1-1]);
                    }
                }
                
            }
		    return dp1[n][n];
		}