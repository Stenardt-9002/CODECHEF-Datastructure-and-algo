// https://practice.geeksforgeeks.org/batch-problems/three-sum-closest/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
struct val{
	int first;
	int second;
};

bool comapre_fuc(val a1 , val b1)
{
    return a1.second<b1.second ;
}



int maxChainLength1( val arr[], int n) 
{ 
    int i, j, max = 0; 
    int *mcl = new int[sizeof( int ) * n ]; 
      
    /* Initialize MCL (max chain length)
    values for all indexes */
    for ( i = 0; i < n; i++ ) 
        mcl[i] = 1; 
      
    /* Compute optimized chain 
    length values in bottom up manner */
    for ( i = 1; i < n; i++ ) 
        for ( j = 0; j < i; j++ ) 
            if ( arr[i].first > arr[j].second && 
                    mcl[i] < mcl[j] + 1) 
                mcl[i] = mcl[j] + 1; 
      
    // mcl[i] now stores the maximum 
    // chain length ending with Pair i 
      
    /* Pick maximum of all MCL values */
    for ( i = 0; i < n; i++ ) 
        if ( max < mcl[i] ) 
            max = mcl[i]; 
      
    /* Free memory to avoid memory leak */
      
    return max; 
} 
      
// int maxChainLen(struct val p[],int n)
// {
//     //Your code here
//     sort(p, p+n , comapre_fuc);
//     vector<int>dp1(n,1);
//     for (int i1 = 1; i1 < n; i1++)
//         for (int j1 = 0; j1 < i1; j1++)
//             if(p[j1].second<p[i1].first && dp1[i1]<dp1[j1]+1)
//                 dp1[i1] = dp1[j1]+1 ;

//     return *max_element(dp1.begin(),dp1.end());
// }   

int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p, p+n , comapre_fuc);
    vector<int>dp1(n,1);
    int j1 = 0;
    int counter = 1;
    for (int i1 = 1; i1 < n; i1++)
        if(p[j1].second<p[i1].first)
            counter++   ,j1 = i1 ;

    return counter ;
}   





int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        val *array_in = new val[n];
        for(int i1 = 0 ;i1<n ; i1++)
            cin>>array_in[i1].first>>array_in[i1].second ;
        cout<<maxChainLen(array_in,n)<<" "<<maxChainLength1(array_in,n)<<endl;
    }
    return 0 ;
}







    