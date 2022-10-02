// https://practice.geeksforgeeks.org/problems/find-the-odd-occurence4820/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll1d;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);




// long long int nineDivisors(long long int N)
// {
//     vector<ll1d>dp1(N+1,0);

//     for (ll1d i1 = 1; i1 <= N; i1++)
//         for (int j1 = i1; j1 <= N; j1+=i1)
//             dp1[j1]++;
    
//     ll1d ans1 = 0 ;
//     // cout<<endl ;
//     for(auto x : dp1)
//         if(x==9)
//             ans1++ ;
//         // cout<<" "<<x ;
//     // cout<<endl;
//     return ans1 ;


//         //Code Here
// }




long long int nineDivisors(long long int N)
{
    // int sqrt1 = sqrt(N);

    // vector<bool>seive_array(sqrt1+1,true);

    // for (int i1 = 2; i1*i1<=sqrt1; i1++)
    //     if(seive_array[i1])
    //         for (int j1 = i1*i1; j1 <=sqrt1; j1++)
    //             seive_array[j1] = false ;
            
    // for (int i1 = 2; i1 <=sqrt1; i1++)
    // {
    //     int p = seive_array[i1] ;
    //     int q = seive_array[i1/p];

    // }
    
    long long int ans1 = 0;
    long long int sqrt1 = sqrt(N);

    vector<ll1d>seive_array(sqrt1+1,0);

    for (ll1d i1 = 1; i1 <sqrt1 ; i1++)
        seive_array[i1] = i1 ;

    for (int i1 = 2; i1*i1<=sqrt1; i1++)
        if(seive_array[i1]==i1)
            for (int j1 = i1*i1; j1 <=sqrt1; j1+=i1)
                if(seive_array[j1]==j1)
                    seive_array[j1] = i1 ;
        
            
    for (int i1 = 2; i1 <=sqrt1; i1++)
    {
        int p = seive_array[i1] ;
        int q = seive_array[i1]/p;


        if((q!=p && p*q==i1 && q!=1)||(seive_array[i1]==i1 && pow(i1,8)<=N))
            ans1++ ;

    }
    

    return ans1 ;


        //Code Here
}






int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n;
    testcase=2 ;
    while (testcase--)
    {
        cin>>n;
        cout<<nineDivisors(n);
    }
    return 0 ;
}


