
// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;






int editDistance(string s, string t) 
{
    int length1 = s.length() ;
    int length2 = t.length() ;

    int dp1[2][length1+1];
    memset(dp1,0,sizeof(dp1));

    for (int i1 = 0; i1 <=length1; i1++)
        dp1[0][i1] = i1 ;

    
    for (int i1 = 1; i1 <length2+1; i1++)
    {
        for (int j1 = 0; j1 < length1+1; j1++)
        {
            if (j1==0)
                dp1[i1%2][j1] = i1 ;
            
            else if (t[i1-1]==s[j1-1])
                dp1[i1%2][j1] = dp1[(i1-1)%2][j1-1];

            else
                dp1[i1%2][j1] = 1+min( {dp1[i1%2][j1-1],dp1[(i1-1)%2][j1],dp1[(i1-1)%2][j1-1]});//insert , remove, replace
        }
        
    }
    return dp1[length2%2][length1];
}




























