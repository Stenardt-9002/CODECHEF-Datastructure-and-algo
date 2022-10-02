// https://www.spoj.com/problems/EKO/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int main(int argc, char const *argv[])
{
    
    fastIO
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    // int testcases=1 ;
    // cin>>testcases;
    // while (testcases--)
    // {
        long long int n , m ;
        cin>>n>>m ;//m cows n holes
        long long int *arr1 = new long long int[n];
        long long int ans1 ; 
        for (long long int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1]    ;
            // if(max_val<arr1[i1])
            //     max_val = arr1[i1] ;
        long long int low1 = 0 ;
        long long int high1 = *max_element(arr1,arr1+n); ;
        long long int definezero = 0;
        while(low1<=high1)
        {
            long long int mid11 = (low1+high1)>>1;
            long long int sum11 =0 ;
            //check if suffice 
            for (long long int i1 = 0; i1 < n; i1++)
                sum11+=(max(definezero,arr1[i1]-mid11))            ;

            if(sum11>=m)
            {
                //clear threshold
                // try for more height 
                ans1 = mid11 ;
                low1 = mid11+1 ;
            }
            else 
                high1 = mid11-1 ;

        }

        cout<<ans1<<endl ;
    // }
    

    return 0;
}




