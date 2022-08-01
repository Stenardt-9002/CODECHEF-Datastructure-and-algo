// https://www.spoj.com/problems/PRATA/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
bool genrate_parthe(long long int *arr1 , long long int n , long long int giventime,long long int limit_parat)
{   
    long long int sum_aprath =0 ;
    for (long long int i1 = 0; i1 < n; i1++)
    {
        long long int rank = arr1[i1];
        long long int low = floor(sqrt(2*giventime/(rank+1)))-1;
        long long int hgih = ceil(sqrt(2*giventime/(rank)))+1;
        long long int number_parathe_gener = low;
        while(low<=hgih)
        {
            long long int mid = (low+hgih+1)>>1 ;
            if((rank*(mid*(mid+1))/2)<=giventime )
            {
                number_parathe_gener = mid ;
                low = mid+1 ;
            }
            else 
                hgih = mid-1;
        }
        sum_aprath+=number_parathe_gener ;
        if(sum_aprath>=limit_parat)
            return true ;


        // long long int rank = arr1[i1];
        // long long int low = floor(sqrt(2*giventime/(rank+1)))-1;
        // long long int number_parathe_gener = low;
        // while((rank*(low*(low+1))/2)<=giventime)
        // {
        //     number_parathe_gener = low ;
        //     low++ ;
        // }



        // sum_aprath+=number_parathe_gener ;
        // if(sum_aprath>=limit_parat)
        // {
        //     // cout<<endl<<sum_aprath<<endl;
        //     return true ;

        // }
    }
    return false ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int testcase ;
    cin>>testcase ;
    while (testcase--)
    {
        long long int n , m ;
        cin>>m>>n ;
        long long int *arr1 = new long long int[n];
        for ( long long int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1]    ;

        long long int low = 1;
        long long int high = *max_element(arr1,arr1+n);
        high  = high*m*(m+1)/2 ;
        long long int ans1 = high ;
        while (low<=high)
        {
            long long int given_time = (low+high+1)>>1;
            if(genrate_parthe(arr1,n,given_time,m))
            {
                ans1 = given_time ;
                high = given_time-1 ;
            }
            else 
                low = given_time+1 ;
        }
        cout<<ans1<<endl;
        // cout<<"\nDEBUG1 "<<m<<"\n"<<genrate_parthe(arr1,n,12,m)<<endl;

    }
    // for (int i1 = 0; i1 < n; i1++)
    //     cout<<" "<<arr1[i1];
    
    // cout<<endl<<func_allow(arr1,n,m,35);

    return 0;
}


