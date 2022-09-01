// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/bike-racing0543



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


// long long int function_acc(long long int time , long veloc[] ,long accer[] , long limit1 , long N)
// {
//     long long int sum1 = 0 ;
//     for (long i1 = 0; i1 < N; i1++)
//         if((veloc[i1] + time*accer[i1])>=limit1 )
//             sum1+=(veloc[i1] + time*accer[i1]);
    
//     return sum1 ;
// }


//more optimised
long buzzTime(long N, long M, long L, long H[], long A[])
{
    // code here
    long minlow = 0 ,maxhigh = 0 ,comp1 = max(L,M);
    for(long a = 0 ;a<N ;a++)
        if((comp1-H[a])%A[a]==0 )
            maxhigh = max(maxhigh  , (comp1-H[a])/A[a] );
        else 
            maxhigh = max(maxhigh  , ((comp1-H[a])/A[a])+1 );



    while(minlow<=maxhigh)
    {
        long  mid1 = (maxhigh+minlow)>>1;
        long sum1 = 0 ;
        for (long i1 = 0; i1 < N; i1++)
            if((H[i1] + mid1*A[i1])>=L )
                sum1+=(H[i1] + mid1*A[i1]);
    
        if(sum1>=M)
            maxhigh = mid1-1 ;
        // {
            // ans1 = mid1 ;
            // cout<<"\nDEUG1 "<<mid1<<" "<<maxhigh<<" "<<compardre;
        // }
        else 
            minlow = mid1+1 ;//,cout<<"\nDEUG2 "<<mid1<<" "<<maxhigh<<" "<<compardre;;
    }
    return minlow ;
}   



    // long buzzTime(long N, long M, long L, long H[], long A[])
    // {
    //     // code here
    //     long minlow = 0 ,maxhigh = max(L,M);
    //     while(minlow<=maxhigh)
    //     {
    //         long  mid1 = (maxhigh+minlow)>>1;
    //         long sum1 = 0 ;
    //         for (long i1 = 0; i1 < N; i1++)
    //             if((H[i1] + mid1*A[i1])>=L )
    //                 sum1+=(H[i1] + mid1*A[i1]);
        
    //         if(sum1>=M)
    //             maxhigh = mid1-1 ;
    //         else 
    //             minlow = mid1+1 ;
    //     }
    //     return minlow ;
    // }




int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long n ,m,l;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n>>m>>l ;
        long *H = new long[n];
        long *A = new long[n];

        for (auto i1 = 0; i1 < n; i1++)
            cin>>H[i1];
        for (auto i1 = 0; i1 < n; i1++)
            cin>>A[i1];
        long nas1 = buzzTime(n, m, l, H,A);
        cout<<"FUCKEM "<<nas1<<endl ;
        // for(int time = 0;time<5;time++ )
        // cout<<function_acc( time , H ,A , l, n)<<" ";

    }
    return 0 ;
}










