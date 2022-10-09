
	

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


// bool dfs_util(int i1 , int j1 , int n , int m , string current , int length_str , vector<vector<char>>&board,vector<vector<bool>> &visited)
// {
//     if(i1<0 || j1<0 || i1>=n||j1>=m || visited[i1][j1]||board[i1][j1]!=current[length_str])
//         return false ;
//     if(length_str==current.size()-1)
//         return true ;
//     visited[i1][j1] = true ;//some random character
    
//     bool ans1 = dfs_util(i1+1 , j1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1-1 , j1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1+1 , j1-1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1 , j1-1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1-1 , j1-1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1+1 , j1+1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1 , j1+1 , n,m,current , length_str+1 , board,visited)||
//     dfs_util(i1-1 , j1+1 , n,m,current , length_str+1 , board,visited);

//     visited[i1][j1] = false ;
//     return ans1 ;
    
// }


// bool check_str(string current , vector<vector<char> > board,int n , int m)
// {
//     vector<vector<bool>> visited(n,vector<bool>(m,false));
//     for (int i1 = 0; i1 < n; i1++)
//         for (int j1 = 0; j1 < m; j1++)
//             if(current[0]==board[i1][j1] && dfs_util(i1,j1,n,m,current,0,board,visited))
//                 return true ;
//     return false ;
// }
    

bool dfs_util(int i1 , int j1 , int n , int m , string current , int length_str , vector<vector<char>>&board)
{
    if(i1<0 || j1<0 || i1>=n||j1>=m || board[i1][j1]!=current[length_str])
        return false ;
    if(length_str==current.size()-1)
        return true ;
    char orig = board[i1][j1] ;//some random character
    board[i1][j1] = 240 ;
    bool ans1 = dfs_util(i1+1 , j1 , n,m,current , length_str+1 , board)||
    dfs_util(i1-1 , j1 , n,m,current , length_str+1 , board)||
    dfs_util(i1+1 , j1-1 , n,m,current , length_str+1 , board)||
    dfs_util(i1 , j1-1 , n,m,current , length_str+1 , board)||
    dfs_util(i1-1 , j1-1 , n,m,current , length_str+1 , board)||
    dfs_util(i1+1 , j1+1 , n,m,current , length_str+1 , board)||
    dfs_util(i1 , j1+1 , n,m,current , length_str+1 , board)||
    dfs_util(i1-1 , j1+1 , n,m,current , length_str+1 , board);

    board[i1][j1] = orig ;
    return ans1 ;
    
}


bool check_str(string current , vector<vector<char> > board,int n , int m)
{
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(current[0]==board[i1][j1] && dfs_util(i1,j1,n,m,current,0,board))
                return true ;
    return false ;
}



vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
{
    // Code here
    int n = board.size();
    int m = board[0].size();
    set<string> ans1 ;
    for(auto str1 : dictionary)
        if(check_str(str1 , board,n,m))
            ans1.insert(str1);
    vector<string> ans2(ans1.begin(),ans1.end()) ;
    return ans2 ;
}


