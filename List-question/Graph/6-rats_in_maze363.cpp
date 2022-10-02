
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;




bool isSafe(int row, int col, vector<vector<int>> m,int n , vector<vector<bool>> visited)
{
    if (row==-1 || row==n || col==-1 || col==n || visited[row][col] || m[row][col]==0)
    {
        return false ;
    }
    return true ;
}





void recursivepath(int row , int col , vector<vector<int>> &m ,int n ,string &cureentpath, vector<string> &ans , vector<vector<bool>> &visited)
{
    if (row==-1 || row==n || col == -1 || col==n || visited[row][col] || m[row][col]==0) //blocked
    {
        return ;
    }

    if (row==n-1 && col==n-1 )
    {
        ans.push_back(cureentpath);
        return ;
    }


    visited[row][col] = true ;

    //one direction
    if (isSafe(row+1,col,m,n,visited))
    {
        cureentpath.push_back('D') ;
        recursivepath(row+1 , col, m,n ,cureentpath ,ans,visited) ;
        cureentpath.pop_back() ;
    }
    

    if (isSafe(row,col-1,m,n,visited))
    {
        cureentpath.push_back('L') ;
        recursivepath(row , col-1, m,n ,cureentpath ,ans,visited) ;
        cureentpath.pop_back() ;
    }
    
    
    if (isSafe(row,col+1,m,n,visited))
    {
        cureentpath.push_back('R') ;
        recursivepath(row , 1+col, m,n ,cureentpath ,ans,visited) ;
        cureentpath.pop_back() ;
    }

    if (isSafe(row-1,col,m,n,visited))
    {
        cureentpath.push_back('U') ;
        recursivepath(row-1 , col, m,n ,cureentpath ,ans,visited) ;
        cureentpath.pop_back() ;
    }
    
    
    visited[row][col] = false ;

}





vector<string> findPath(vector<vector<int>> &m, int n) 
{
    vector<string> ans ;
    string path ;
    vector<vector<bool>> visited(n);
    for (int i1 = 0; i1 < n; i1++)
    {        visited[i1] = vector<bool>(n,false );    }

    recursivepath(0,0,m,n,path,ans,visited);
    return ans ;
}




int main(int argc, char const *argv[])
{
    
    return 0;
}





