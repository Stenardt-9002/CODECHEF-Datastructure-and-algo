// https://practice.geeksforgeeks.org/problems/2d3fc3651507fc0c6bd1fa43861e0d1c43d4b8a1/1






















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






























class Solution
{
    public:
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
            vector<vector<int>>dp1(N, vector<int>(N,0));
            for (int i = 0; i < N; i++)
            {
                int first = 1 ,second = 1;
                if(i>0)
                    first = a[i-1];
                if(i<N-1)
                    second = a[i+1];
                dp1[i][i] = first*a[i]*second;
            }



            for (int length = 1; length < N; length++)
                for (int start = 0; start < N-length; start++)
                {
                    int max_sum = INT_MIN ;
                    int end = start+length ;
                    int first = 1 , second = 1;
                    if(start>0)
                        first = a[start-1];
                    if(end<N-1)
                        second = a[end+1];
                    for (int index = start+1; index <end ; index++)
                        max_sum = max(max_sum , dp1[start][index-1] + dp1[index+1][end]+ first*a[index]*second);


                    max_sum = max({max_sum , first*a[start]*second + dp1[start+1][end],first*a[end]*second + dp1[start][end-1]});
                    dp1[start][end] = max_sum ;
                }
                
            

            return dp1[0][N-1];



        }
};



















