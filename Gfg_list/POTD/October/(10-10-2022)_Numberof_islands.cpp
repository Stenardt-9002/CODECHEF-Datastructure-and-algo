// https://practice.geeksforgeeks.org/problems/number-of-islands/1




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



void dfs_util(int i1 , int j1 , int n , int m , vector<vector<bool>> &visisted)
{
    if(i1<0||j1<0||i1>=n||j1>=m||!visisted[i1][j1])
        return ;

    visisted[i1][j1] = false ;

    dfs_util(i1+1 , j1 , n , m , visisted);
    dfs_util(i1-1 , j1 , n , m , visisted);
    dfs_util(i1 , j1+1 , n , m , visisted);
    dfs_util(i1 , j1-1 , n , m , visisted);

    return ;
}




vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
{
    // code here
    vector<int> ans1 ;
    vector<vector<int>> indexes ;
    for(auto vec : operators)
    {
        indexes.push_back({vec[0],vec[1]});
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(auto in : indexes)
            visited[in[0]][in[1]] = true ;
        int num_of_componenets = 0 ;
        for(auto in : indexes)
            if(visited[in[0]][in[1]])
                dfs_util(in[0],in[1] ,n,m,visited) , num_of_componenets++ ;

        ans1.push_back(num_of_componenets);
    }

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
        
    }
    

    return 0;
}




