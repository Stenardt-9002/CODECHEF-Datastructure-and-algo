// https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dfs_util(vector<vector<char> > mat , string taget , int length , int i1 , int j1, int n ,int m)
{
    if(i1<0 || j1<0 || i1>=n || j1>=m || mat[i1][j1]!=taget[length]) 
        return 0;
    // current_sting += mat[i1][j1] ; 
    int ans1 = 0 ;
    char mathc = mat[i1][j1] ; 
    length++ ;
    mat[i1][j1] = 0; 
    if(taget[length]==0)
    {
        ans1 = 1;
    //     ans1++ ;
    //     return ;
    }
    else 
    {
        
        ans1+=dfs_util(mat , taget ,  length , i1+1 , j1,n,m);
        ans1+=dfs_util(mat , taget ,  length , i1 , j1+1,n,m);
        ans1+=dfs_util(mat , taget ,  length , i1-1 , j1,n,m);
        ans1+=dfs_util(mat , taget ,  length , i1 , j1-1,n,m);

    }
    mat[i1][j1] = mathc; 
    return ans1 ;
}

int findOccurrence(vector<vector<char> > &mat, string target)
{
    int ans1 = 0;
    int n = mat.size(),m = mat[0].size();

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            ans1+=dfs_util(mat ,target ,0 , i1 ,j1,n,m);
    

    return ans1 ;
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n>>m;
        vector<vector<char> >mat(n,vector<char>(m));
        for (auto &vec : mat)
            for(auto &ch : vec)
                cin>>ch ;

        string target ;
        cin>>target ;
        cout<<findOccurrence(mat,target)<<endl;

    }
    return 0 ;
}

