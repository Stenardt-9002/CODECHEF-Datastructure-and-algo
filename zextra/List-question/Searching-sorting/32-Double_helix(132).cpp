// https://www.spoj.com/problems/ANARC05B/



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
    testcase=10000 ;
    while (testcase--)
    {
        long long int n , m ;
        cin>>m;
        if(m==0)    
            break ;
        long long int *arr1 = new long long int[m];
        for ( long long int i1 = 0; i1 < m; i1++)
            cin>>arr1[i1]    ;

        cin>>n ;
        long long int *arr2 = new long long int[n];
        for ( long long int i1 = 0; i1 < n; i1++)
            cin>>arr2[i1]    ;

        long long int low_second = 0 ;
        long long int high_second = 0 ;
        long long int pos = -1 ;
        vector<long long int> arr_sum1 ;
        vector<long long int> arr_sum2 ;
        // vector<long long int>intersection_pt ;
        long long int sum1 = 0 ;
        long long int sum2 = 0 ;

        for (int i1 = 0; i1 < m; i1++)
        {
            
            if((pos = found(arr1[i1] ,arr2,low_second,n))!=-1)
            {
                arr_sum1.push_back(sum1+arr2[pos]);//arr2[pos]==arr1[i1]
                high_second = pos ;
                //sum from low second to high+second
                sum2 =0 ;
                for (long long int j1 = low_second; j1 <= high_second && j1<n; j1++)
                    sum2+=arr2[j1];

                arr_sum2.push_back(sum2);



                sum1 =0 ;
                low_second = pos+1;
            }
            else 
                sum1+=arr1[i1];
            
        }
        arr_sum1.push_back(sum1);
        sum2 = 0 ;
        for (long long int i1 = low_second; i1 < n; i1++)
            sum2+=arr2[i1];

        arr_sum2.push_back(sum2);
        long long int ans1 = 0 ;        
        for (long long int i1 = 0; i1 < arr_sum2.size(); i1++)
            ans1+=max(arr_sum1[i1],arr_sum2[i1]);

        cout<<ans1<<endl ;

        delete []arr1 ;
        delete []arr2 ;
    }
    // for (int i1 = 0; i1 < n; i1++)
    //     cout<<" "<<arr1[i1];
    
    // cout<<endl<<func_allow(arr1,n,m,35);

    return 0;
}




















//better method


// func()
// {
//     int b[m];
//     for (int i1 = 0; i1 < m; i1++)
//         cin>>b[i1];

//     int s1 =0 ,s2=0 ;
//     int i=0 , j=0 ;
//     int ma = 0  ;
//     while (i<n&&j<m)
//     {
//         if(a[i]<b[j])    
//             s1+=a[i++];
//         else if(b[j]<a[i])
//             s2+=b[j++];
//         else 
//         {
//             ma += (max(s1,s2)+a[i]);
//             s1 = s2 = 0 ;
//             i++ ; j++ ;
//         }
//     }
//     while(i<n)
//     {
//         s1+=a[i++];
//     }
//     while (j<m)
//     {
//         s2+=b[j++]    ;
//     }
//     ma+=max(s1,s2);
//     cout<<ma<<endl

    
// }


