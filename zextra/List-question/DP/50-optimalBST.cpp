
// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/





#include "bits/stdc++.h"

using namespace std;

int iotimalBST(vector<int> freq,vector<int> keys, int n)
{
    vector<int> cumlative(n) ;
    cumlative[0] = freq[0] ;
    int dp1[n][n] ;
    //O(n)
    dp1[0][0] = freq[0] ;
    for (int i1 = 1; i1 < n; i1++)
    {
        dp1[i1][i1] = freq[i1] ;
        cumlative[i1] = cumlative[i1-1]+freq[i1] ;
    }
    
    //O(n^3)

    for (int len = 2; len <=n; len++)
    {
        for (int i1 = 0; i1 <=n-len+1; i1++)
        {
            int j1 = i1+len-1;
            dp1[i1][j1] = INT_MAX ;
        }
        
        
    }
    




}



int main(int argc, char const *argv[])
{
    int n ;cin>>n ;
    vector<int> freq(n);vector<int> keys(n);
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>freq[i1] ;
    }
    
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>keys[i1] ;
    }
    


    return 0;
}







