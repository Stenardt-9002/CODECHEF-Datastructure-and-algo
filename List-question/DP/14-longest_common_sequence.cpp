#include "bits/stdc++.h"



using namespace std;


    int lcs(int x, int y, string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp1(m+1);
        for (int i1 = 0; i1 < m+1; i1++)
        {
            dp1.push_back(vector<int>(n+1,0));
        }
        
        for (int i1 = 0; i1 < m+1; i1++)
        {
            dp1[i1][0] = 0;
        }
        

        for (int i1 = 0; i1 < n+1; i1++)
        {
            dp1[0][i1] = 0;
        }
        
        for (int i1 = 1; i1 < m+1; i1++)
        {
            for (int j1 = 1; j1 < n+1; j1++)
            {
                if (s1[i1-1]==s2[j1-1])
                {
                    dp1[i1][j1] = 1+dp1[i1-1][j1-1];
                }
                else
                {
                    dp1[i1][j1] = max(dp1[i1][j1-1],dp1[i1-1][j1]);
                }
                
                
            }
            
        }
        return dp1[m][n];


    }


int main(int argc, char const *argv[])
{
    
    return 0;
}







