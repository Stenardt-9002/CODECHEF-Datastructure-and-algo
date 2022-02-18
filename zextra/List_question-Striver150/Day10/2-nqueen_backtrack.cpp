

#include <bits/stdc++.h>
using namespace std;


bool isSafe1(int rowc,int colc,vector<string>board , int n )
{
    //check column 
    //check diagonal
    //check right diagonal
    int curr = rowc ; 
    int curc = colc ;
    while (curr>=0 && curc>=0)
    {
        if (board[curr][curc]=='Q')
        {
            return false ; //problem 
        }
        curr-- ;
        curc-- ;
    }

    //check column 
     curr = rowc ; 
     curc = colc ;
    while (curc>=0)
    {
        if (board[curr][curc]=='Q')
        {
            return false ; //problem 
        }
        curc-- ;
    }
    
        //check upper diagonal 
     curr = rowc ; 
     curc = colc ;
    while (curr<n &&curc>=0)
    {
        if (board[curr][curc]=='Q')
        {
            return false ; //problem 
        }
        curc-- ;
        curr++;
    }

    return true ;
    
}



void util_sove(int col,vector<string> &board,vector<vector<string>> &ans,int n)
{
    if (col==n)
    {
        ans.push_back(board);
        //done
        return ;
    }
    //recursive for all rows 
    for (int i1 = 0; i1 < n; i1++)
    {
        //i1 is row 
        if (isSafe1(i1,col,board,n))
        {
            board[i1][col] = 'Q';
            util_sove(col+1,board ,ans, n) ;// see if it works
            board[i1][col] = '.';//done with recursion 
        }
        
    }
    

    
}




vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> an1s ;
    vector<string> board(n) ;
    string s1(n,'.') ;
    for (int i1 = 0; i1< n; i1++)
    {
        board[i1] = s1;
    }
    util_sove(0,board,an1s,n);
    return an1s ;



}








