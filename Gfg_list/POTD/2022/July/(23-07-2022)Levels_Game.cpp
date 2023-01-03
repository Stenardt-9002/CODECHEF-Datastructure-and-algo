// https://practice.geeksforgeeks.org/problems/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int rec_util(int h , int m , int last_step ,vector<vector<int>>&moisaion)
{
    if(moisaion[h][m]!=-1)
        return moisaion[h][m];
    int val1 = INT_MIN ,val2 = INT_MIN ,val3 = INT_MIN ;  

    if(last_step!=0)
        val1 = 1+rec_util(h+3,m+2,0,moisaion);

    if(last_step!=1&& h>5 && m>10)
        val2 = 1+rec_util(h-5,m-10,1,moisaion);

    if(last_step!=2&& h>20 )
        val3 = 1+rec_util(h-20,m+5,2,moisaion);

    // if(val1==INT_MIN&&val2==INT_MIN&&val3==INT_MIN)
    //     return moisaion[h][m]=0 ;

    moisaion[h][m]=max({0,val1,val2,val3 }) ;
    return moisaion[h][m];

}

int maxLevel(int h,int m)
{
    // code here
    vector<vector<int>> moisaion(4002,vector<int>(4002,-1));
    int ans1= rec_util(h,m,-1,moisaion);
    return ans1 ;

}



int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int h,m ; 
    cin>>h>>m ;
    // int max
    cout<<maxLevel(h,m);



    return 0;
}




