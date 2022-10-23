// https://practice.geeksforgeeks.org/problems/reverse-spiral-form-of-matrix4033/1







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




vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  
{
    // code here
    vector<int> ans1 ;
    int r1 = 0 , r2 = R-1,c1 = 0 ,c2 = C-1;
    
    while(r1<=r2 && c1<=c2)
    {

        for (int i1 = c1; i1 <=c2; i1++)
            ans1.push_back(a[r1][i1]);

        //r2
        for (int i = r1+1; i<=r2 ; i++)
            ans1.push_back(a[i][c2]);
        
        if(r1!=r2)
        for (int i1 = c2-1; i1 >=c1; i1--)
            ans1.push_back(a[r2][i1]);
            
        if(c1!=c2)
        for (int i = r2-1; i>=r1+1 ; i--)
            ans1.push_back(a[i][c1]);

        r1++ ;r2-- ;
        c1++ ;c2-- ;    
    }
        reverse(ans1.begin(),ans1.end());

    return ans1 ;
}


int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n , m;
        cin>>n>>m ;
        vector<vector<int>>matrix(n,vector<int>(m,0));
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                cin>>matrix[i1][j1];

        vector<int>ans1 = reverseSpiral(n,m,matrix);
        for(auto c: ans1)
            cout<<c<<" ";
        cout<<endl ;
    }
    

    return 0;
}


