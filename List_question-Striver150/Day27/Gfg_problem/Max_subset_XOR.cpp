// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1?page=1&difficulty[]=2&status[]=unsolved&curated[]=1&sortBy=submissions



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





#define INT_SIZE 32




class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
        int ans = 0 ;
        int cur_ind = 0;

        for (int i = 31; i >= 0; i--)
        {
            int maxInd = cur_ind ;
            int maxEle = INT_MIN ;
            for (int j = cur_ind; j < N; j++)
                if((arr[j]&(1<<i))!=0 && arr[j]>maxEle)
                    maxEle = arr[j], maxInd = j;


            if(maxEle == INT_MIN)
                continue ;

            swap(arr[cur_ind],arr[maxInd]);
            maxInd = cur_ind ;
            for (int j = 0; j < N; j++)
                if(j!=maxInd && (arr[j]&(1<<i))!=0)
                    arr[j] = arr[j]^arr[maxInd];

            cur_ind++;            

        }
        
        for (int i = 0; i < N; i++)
            ans^=arr[i]            ;


        return ans ;
    }
};