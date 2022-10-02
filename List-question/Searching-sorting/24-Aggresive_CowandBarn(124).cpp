// https://www.spoj.com/problems/AGGRCOW/


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

        sort(arr1,arr1+n);
        int low = 0 , high = arr1[n-1],mid, ans1 = 0 ;

        while (low<=high)
        {
            mid = (low+high+1)>>1;
            int cnt=1 , left =0 ;
            for (int i1 = 1; i1 < n && cnt<m ; i1++)
            {
                if(arr1[i1]-arr1[left]>=mid)
                {
                    cnt++ ;
                    left = i1 ;
                }
            }
            if(cnt==m)//more than m counts
            {
                ans1 = mid ;
                low = mid+1 ;//go right 
            }
            else 
                high = mid-1 ;
        }
        cout<<ans1<<endl ;
    }
    

    return 0;
}

