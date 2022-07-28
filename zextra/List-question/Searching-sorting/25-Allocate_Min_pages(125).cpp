// https://www.spoj.com/problems/AGGRCOW/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int findPages(int A[], int N, int M) 
{
    //code here
    // N = NUmber of pages 
    // M = Number of stuudents 
    // sort(A,A+N);
    // only if N>=M
        if(N<M)
            return -1 ;
        int low = A[M-1];
        int high = A[M-1];
        
        for (int i1 = M; i1 < N; i1++)
            high+=A[i1]    ;
        int ans1 = high ;
        while(low<=high)
        {
            int mid = (low+high+1)>>1 ;
            //try mid 
            int set_cunt = N ;// pages
            int set_cunt_stud = M ;//students
            while(set_cunt>0&&set_cunt_stud>0)
            {
                int cum_sum = 0;
                while (set_cunt>0&&cum_sum+A[set_cunt-1]<=mid)
                {
                    cum_sum+=A[set_cunt-1];
                    set_cunt-- ;
                }
                set_cunt_stud-- ;
            }
            if(set_cunt==0)
            {
                ans1 = mid ; 
                high = mid-1;
            }
            else
                low = mid+1 ;
        }
    
        return ans1 ;
}



int main(int argc, char const *argv[])
{
    
    fastIO
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n , m ;
        cin>>n>>m ;//m cows n holes
        int *arr1 = new int[n];
        for (int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1]    ;

        cout<<findPages(arr1,n,m)<<endl;
        // sort(arr1,arr1+n);
        // int low = 0 , high = arr1[n-1],mid, ans1 = 0 ;

        // while (low<=high)
        // {
        //     mid = (low+high+1)>>1;
        //     int cnt=1 , left =0 ;
        //     for (int i1 = 1; i1 < n && cnt<m ; i1++)
        //     {
        //         if(arr1[i1]-arr1[left]>=mid)
        //         {
        //             cnt++ ;
        //             left = i1 ;
        //         }
        //     }
        //     if(cnt==m)//more than m counts
        //     {
        //         ans1 = mid ;
        //         low = mid+1 ;//go right 
        //     }
        //     else 
        //         high = mid-1 ;
        // }
        // cout<<ans1<<endl ;
    }
    

    return 0;
}

