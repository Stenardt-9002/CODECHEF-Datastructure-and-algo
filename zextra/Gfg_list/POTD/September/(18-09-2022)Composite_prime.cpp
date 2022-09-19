// https://practice.geeksforgeeks.org/problems/composite-and-prime0359/1










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;

// int Count(int L, int R)
// {
//     // Code here
//     set<int> createprime = {2,3};
//     for (int i1 = 5; i1 <=R; i1++)
//     {
//         bool ifprime = true ;
//         for(auto ele : createprime)
//             if(i1%ele==0)
//             {
//                 ifprime = false ;
//                 break ;
//             }
//         if(ifprime)
//             createprime.insert(i1);

//     }
//     int prime_count = 0 ;
//     if(L<2)
//         L = 2 ;
//     for (int i1 = L; i1 <=R; i1++)
//         if(createprime.find(i1)!=createprime.end())
//             prime_count++ ;

//     return (R-L+1-prime_count)-prime_count ;    


// }

int Count(int L, int R)
{
    // Code here
    vector<bool> prime(R+1,true);
    for (int num = 2; num*num <=R; num++)
        if(prime[num])
            for (int i1 = num*num; i1 <=R; i1+=num)
                prime[i1] = false ;
            
    int prime_count = 0 ;

    if(L<2)
        L = 2 ;
    for (int i1 = L; i1 <=R; i1++)
        if(prime[i1])
            prime_count++ ;

    return (R-L+1-prime_count)-prime_count ; 
    
    
}




