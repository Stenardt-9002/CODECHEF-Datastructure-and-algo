// https://practice.geeksforgeeks.org/problems/number-formation3506/1





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


ll exact_value_func( ll X , ll Y , ll Z , vector<ll> dp1)
{
    // X digits 4 // Y digits 5 // Z digits 6
    if(X==0 &&Y==0&&Z==0)
        return 0ll ;
    ll totoal_count = dp1[X+Y+Z]/(dp1[X]*dp1[Y]*dp1[Z]);
    ll ans1 = 0;
    ll number4 = 0,number5=0,number6=0 ;

    for (ll i1 = 0; i1 < X+Y+Z; i1++)
    {
        number4+=(4*(pow(10,i1)));
        number5+=(5*(pow(10,i1)));
        number6+=(6*(pow(10,i1)));
    }
    
    ll countX = (X*(totoal_count))/(X+Y+Z);
    ll countY = (Y*(totoal_count))/(X+Y+Z);
    ll countZ = (Z*(totoal_count))/(X+Y+Z);


    // ans1 = ((number4*countX))+((number5*countY))+((number6*countZ));
    // ans1 = ans1%MOD1 ;
    // if(ans1<0)
    //     ans1 = ans1+MOD1;
    ans1 = ((number4*countX)%MOD1)+((number5*countY)%MOD1)+((number6*countZ)%MOD1);
    ans1 = ans1%MOD1 ;
    return ans1 ;
}



// int getSum(int X, int Y, int Z) 
// {
//     // Your code goes here
//     ll length_string=X+Y+Z ;
//     vector<ll> dp1(length_string+1,1);
//     for (ll i1 = 2; i1 <= length_string; i1++)
//         dp1[i1] = (dp1[i1-1]*i1)%MOD1 ;
            

    
//     ll ans1 = 0;
//     for (int x = 0; x < X+1; x++)
//         for (int y = 0; y < Y+1; y++)
//             for (int z = 0; z < Z+1; z++)
//             {
//                 ans1+=(exact_value_func(x,y,z,dp1));
//                 ans1%=MOD1;
//             }
    

//     return ans1%MOD1 ;
    
// }




int getSum(int X, int Y, int Z) 
{
    // Your code goes here
    vector<vector<vector<ll>>>exactdp1(66 , vector<vector<ll>>(66,vector<ll>(66,0)));
    vector<vector<vector<ll>>>sumdp2(66 , vector<vector<ll>>(66,vector<ll>(66,0)));

    if(X==0&&Y==0&&Z==0)
        return 0 ;

    exactdp1[0][0][0] = 1;

    ll ans1 = 0;
    for (int x = 0; x < X+1; x++)
        for (int y = 0; y < Y+1; y++)
            for (int z = 0; z < Z+1; z++)
            {
                if(x>0)
                {
                    sumdp2[x][y][z]+=(sumdp2[x-1][y][z]*10 + 4*exactdp1[x-1][y][z])%MOD1;
                    exactdp1[x][y][z]+=exactdp1[x-1][y][z]%MOD1;
                }
                if(y>0)
                {
                    sumdp2[x][y][z]+=(sumdp2[x][y-1][z]*10 + 5*exactdp1[x][y-1][z])%MOD1;
                    exactdp1[x][y][z]+=exactdp1[x][y-1][z]%MOD1;
                }
                if(z>0)
                {
                    sumdp2[x][y][z]+=(sumdp2[x][y][z-1]*10 + 6*exactdp1[x][y][z-1])%MOD1;
                    exactdp1[x][y][z]+=exactdp1[x][y][z-1]%MOD1;
                }

                ans1+=sumdp2[x][y][z]%MOD1;
                ans1%=MOD1;

            }   
    

    return ans1%MOD1 ;
    
}








int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    // int testcases=1 ;
    // int x , y,z;
    // cin>>testcases;
    // while (testcases--)
    // {
    //     cin>>x>>y>>z ;
    //     cout<<getSum(x,y,z)<<endl;
    // }
    
    cout<<getSum(1,1,1)<<endl;
    // vector<ll> dp1(13,1);
    // for (ll i1 = 2; i1 <= 12; i1++)
    //     dp1[i1] = dp1[i1-1]*i1 ;


    // cout<<exact_value_func(0,0,0 , dp1)<<endl;


    return 0;
}



