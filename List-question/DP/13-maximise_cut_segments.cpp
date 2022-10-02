// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1





#include "bits/stdc++.h"

using namespace std;


    int maximizeTheCuts(int n, int x, int y, int z)
    {
       
        int dp1[n+1];
        for(int i1=0;i1<n+1;++i1)dp1[i1]=-1;
        if(x<n+1)
        dp1[x]=1;
        if(y<n+1)
        dp1[y]=1;
        if(z<n+1)
        dp1[z]=1;
        for(int i1=1;i1<n+1;++i1)
            {
                if(dp1[i1]!=-1)//not available
                {
                    if(i1+x<=n)
                    dp1[i1+x] = max(dp1[i1+x],dp1[i1]+1);
                
                    if(i1+y<=n)
                    dp1[i1+y] = max(dp1[i1+y],dp1[i1]+1);
                
                    if(i1+z<=n)
                    dp1[i1+z] = max(dp1[i1+z],dp1[i1]+1);
                
                
                }
                
            }
            if(dp1[n]==-1)return 0;
            return dp1[n];
    }

