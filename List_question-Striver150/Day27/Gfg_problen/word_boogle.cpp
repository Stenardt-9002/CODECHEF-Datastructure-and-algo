// https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1





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

// bool dfs_util(int i1 , int j1 , int n , int m ,int stringindex , vector<vector<char> > &board,vector<vector<bool>> &visited  ,string str1 )
// {   
//     if(i1<0||j1<0||i1>=n||j1>=m ||visited[i1][j1]||board[i1][j1]!=str1[stringindex])
//         return false ;

//     bool abns1 = true ;
//     if(stringindex == str1.length()-1)
//         return true ;
//     visited[i1][j1]=true;

//     abns1 =abns1|| dfs_util(i1+1 , j1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1+1 , j1-1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1+1 , j1+1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1-1 , j1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1-1 , j1-1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1-1 , j1+1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1 , j1-1,n,m,stringindex+1,board,visited,str1);
//     abns1 =abns1|| dfs_util(i1 , j1+1,n,m,stringindex+1,board,visited,str1);

//     return abns1 ;
// }
bool bfs_util(int i1 , int j1 , int n , int m , vector<vector<char> > &board,string str1 )
{   
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int stringindex = 0;
    if(board[i1][j1]!=str1[stringindex])
        return false ;
    queue<vector<int>>q1 ;//srcx/srcy/stringindex
    q1.push({i1,j1 , 0});
    int arrx[]= {1,-1,0,1,-1,0,-1,1};
    int arry[] ={1,1,1,-1,-1,-1,0,0};
    int i2 ,j2 ;
    while (!q1.empty())
    {
        vector<int> top1 = q1.front();
        q1.pop();
        i2 = top1[0] ;
        j2 = top1[1] ;
        stringindex = top1[2];
        cout<<"DEBUG1 "<<str1[stringindex]<<" "<<visited[1][2]<<endl;
        visited[i1][j1] = true ;
        if(stringindex==str1.size()-1)
            return true ;
        for (int pos = 0; pos < 8; pos++)
        {
            i1 = i2+arrx[pos];
            j1 = j2+arry[pos];
            if(i1<0||j1<0||i1>=n||j1>=m ||visited[i1][j1]||board[i1][j1]!=str1[stringindex+1])
                continue ;
            else 
                q1.push({i1,j1,stringindex+1}) , visited[i1][j1] = true ;
        }
        

    }
    return false ;

}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
{
    // Code here
    //instead of graph bfs and graph dfs 
    int n = board.size();
    int m = board[0].size();
    vector<string> ans12 ;
    
    for(auto str:dictionary)
    {
        bool dobne =true ;
        for (int i1 = 0; i1 < n && dobne; i1++)
            for (int j1 = 0; j1 < m&& dobne; j1++)
                if(bfs_util(i1,j1,n,m,board, str))
                    dobne = false ,ans12.emplace_back(str);

                // if(dfs_util(i1,j1,n,m,0,board, visited,str))

        
    }
    return ans12 ;

}





int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 

        
    int testcase ;
    // long long int n ;//, target;
    // testcase=1 ;
    cin>>testcase;
    while (testcase--)
    {
        int n ,m;
        cin>>n;

        vector<string> input1(n) ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>input1[i1] ;
        cin>>n>>m ;
        vector<vector<char>> board(n,vector<char>(m));// vector<string>& dictionary
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                cin>>board[i1][j1];

        
        vector<string> output =  wordBoggle( board,  input1) ;
        cout<<endl ;
        for (auto out : output)
            cout<<out<<" ";
        

    }
    return 0 ;
}



