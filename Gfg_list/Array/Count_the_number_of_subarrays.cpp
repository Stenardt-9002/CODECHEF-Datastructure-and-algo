// https://practice.geeksforgeeks.org/problems/count-the-number-of-subarrays/1?page=1&difficulty[]=2&status[]=unsolved&category[]=Arrays&category[]=Dynamic%20Programming&sortBy=submissions














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


























class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) 
    {
        // code here
        long long int subarray_less_L = 0 ;
        long long int i = 0 ;//,j =0 ; 
        //get subarray less than L
        long long int sum1 = 0 ;
        for (int j = 0; j < N; j++)
        {
            sum1+=A[j];
            while (sum1>=L)
                sum1-=A[i++];

            long long int length = j-i+1 ; 
            // length = length*(length+1)/2 ;
            subarray_less_L+=length ; 
        }





        long long int subarray_less_R = 0 ;
        i = 0 ,sum1 = 0 ;
        //get subarray less than R
        for (int j = 0; j < N; j++)
        {
            sum1+=A[j];
            while (sum1>R)
                sum1-=A[i++];

            long long int length = j-i+1 ; 
            // length = length*(length+1)/2 ;
            subarray_less_R+=length ; 
        }



        return subarray_less_R-subarray_less_L ;

    }
};




int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n ; 
        cin>> n;
        vector<int> input(n,0) ; 
        for (int i = 0; i < n; i++)
            cin>>input[i];
        
        long long int L,R ;
        cin>>L>>R ;
        Solution obj1 ;
        cout<<obj1.countSubarray(n , input , L ,R)<<endl;

    }
    

    return 0;
}









