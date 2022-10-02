    
    
// https://practice.geeksforgeeks.org/problems/word-wrap1646/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;





int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here

    int n = nums.size();
    
    vector<vector<int>>dp1cost;
    vector<vector<int>>dp2cost;

    for (int i1 = 0; i1 < n+1; i1++)
    {
        vector<int>temp1(n+1,0);
        dp1cost.push_back(temp1)        ;
        dp2cost.push_back(temp1)        ;

    }
    vector<int> cst1(n+1) ;


   for (int i1 = 1; i1 < n+1; i1++)
    {
        dp1cost[i1][i1] = k-nums[i1-1];//cost from i to j words in line
        for (int j = i1+1; j < n+1; j++)
            dp1cost[i1][j] = dp1cost[i1][j-1]-nums[j-1]-1 ; //one word included therefore 1 for space cost
    }


    for (int i1 = 1; i1 < n+1; i1++)
    {
        for (int j1 = i1; j1 < n+1; j1++)
        {
            if(j1==n && dp1cost[i1][j1]>=0)
                dp2cost[i1][j1] = 0 ;

            else if(dp1cost[i1][j1]<0)
                dp2cost[i1][j1] = INT_MAX ;

            else 
                dp2cost[i1][j1] = dp1cost[i1][j1]*dp1cost[i1][j1] ; //cost is squared
        }

    }
    
    cst1[0] = 0 ;
    for (int j1 = 1; j1 < n+1; j1++)
    {
        cst1[j1] = INT_MAX ;
        for (int i1 = 1; i1 < j1+1; i1++)
        {
            if(cst1[i1-1]!=INT_MAX && dp2cost[i1][j1]!=INT_MAX)
                cst1[j1] = min(cst1[j1],cst1[i1-1]+dp2cost[i1][j1]);
        }
        
    }
    int min_ans = cst1[n] ;

    // for (int i1 = 1; i1 < n+1; i1++)
    //     min_ans = min(min_ans,cst1[i1])    ;

    return min_ans;
} 


int main(int argc, char const *argv[])
{
    int n ;cin>>n;
    int temp1,k ;
    vector<int> a1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>temp1 ;
        a1.push_back(temp1);
    }
    cin>> k ;
    cout<<endl<<solveWordWrap(a1,k);
    
    return 0;
}





