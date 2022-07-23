// https://practice.geeksforgeeks.org/problems/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int countMin(string str)
{
    //complete the function here
    int n = str.length();
    vector<vector<int>>dp1(n,vector<int>(n,0));
    int left_side , right_sdie , distance ;

    for(distance=1 ; distance<n ; distance++)
        for ( left_side = 0,right_sdie = distance;  right_sdie<n; left_side++,right_sdie++)
            dp1[left_side][right_sdie] = (str[left_side]==str[right_sdie])?dp1[left_side+1][right_sdie-1]:(min(dp1[left_side][right_sdie-1],dp1[left_side+1][right_sdie])+1 );
        
    return dp1[0][n-1];

}



int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdin);

    int n ; 
    cin>>n ;


    return 0;
}

