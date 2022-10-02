

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long int found(long long int val , long long int *arr1 ,long long int low , long long int n)
{
    int high = n-1 ;
    int mid  ;
    while (low<=high)
    {
            mid = (low+high)>>1;
            if(arr1[mid]==val)
                return mid ;
            else if(arr1[mid]>val)
                high = mid-1 ;
            else 
                low = mid+1 ;
    }
    return -1 ;
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;
        vector<long long int>arr1(n,0);
        for (long long int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1];

        //all subsets  
        long long int subset_count = 1 ;
        for (long long int i1 = 0; i1 < n; i1++)
        {
            long long int sum12  = 0;
            for (long long int j1 = i1; j1 < n; j1++)
            {
                sum12+=arr1[j1];
                if(sum12>=min(a,b) &&sum12<=max(a,b))
                    subset_count++ ;
            }
        }   
        cout<<subset_count<<endl ;


    }
    return 0 ;
}