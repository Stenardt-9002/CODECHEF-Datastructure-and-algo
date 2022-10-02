// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


long long int  countPS(string str)
{
    long long n = str.size() ;
    vector<vector<long long>> dp1(n,vector<long long>(n,0));


    for (long long i = 0; i < n; i++)
        dp1[i][i] = 1;
    


    for (long long len = 1; len < n; len++)
    {
        for (long long starti = 0; starti < n-len; starti++)
        {
            long long startj = len+starti ;
            if (str[starti]==str[startj])
                    dp1[starti][startj] = 1+dp1[starti+1][startj]+dp1[starti][startj-1];
                //one from one subsequence added

            else 
                    dp1[starti][startj] = dp1[starti+1][startj]+dp1[starti][startj-1]-dp1[starti+1][startj-1];//remove the counted twice as well
        }
    }
    return dp1[0][n-1] ;
}


    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       const int mod1 = (1e9+7);

        long long n = str.size() ;
        vector<vector<long long>> dp1(n,vector<long long>(n,0));
    
    
        for (long long i = 0; i < n; i++)
            dp1[i][i] = 1;
  
        for (long long len = 1; len < n; len++)
        {
            for (long long starti = 0; starti < n-len; starti++)
            {
                long long startj = len+starti ;
                if (str[starti]==str[startj])
                    {    
                        dp1[starti][startj] = 1+dp1[starti+1][startj]+dp1[starti][startj-1];
                        dp1[starti][startj] = dp1[starti][startj]%mod1;
                        if(dp1[starti][startj]<0)
                            dp1[starti][startj]+=mod1;
                    }
                    //one from one subsequence added
    
                else 
                    {
                        dp1[starti][startj] = dp1[starti+1][startj]+dp1[starti][startj-1]-dp1[starti+1][startj-1];//remove the counted twice as well
                        dp1[starti][startj] = dp1[starti][startj]%mod1;
                        if(dp1[starti][startj]<0)
                            dp1[starti][startj]+=mod1;
                    }
            }
        }
        return dp1[0][n-1] ;
    }

int main(int argc, char const *argv[])
{
    cout<<countPS("abcd");
    return 0;
}

