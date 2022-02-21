// https://leetcode.com/problems/n-queens/submissions/
// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1


#include <bits/stdc++.h>
using namespace std;
//leetecode 

// bool isSafe1(int rowc,int colc,vector<string>board , int n )
// {
//     //check column 
//     //check diagonal
//     //check right diagonal
//     int curr = rowc ; 
//     int curc = colc ;
//     while (curr>=0 && curc>=0)
//     {
//         if (board[curr][curc]=='Q')
//         {
//             return false ; //problem 
//         }
//         curr-- ;
//         curc-- ;
//     }

//     //check column 
//      curr = rowc ; 
//      curc = colc ;
//     while (curc>=0)
//     {
//         if (board[curr][curc]=='Q')
//         {
//             return false ; //problem 
//         }
//         curc-- ;
//     }
    
//         //check upper diagonal 
//      curr = rowc ; 
//      curc = colc ;
//     while (curr<n &&curc>=0)
//     {
//         if (board[curr][curc]=='Q')
//         {
//             return false ; //problem 
//         }
//         curc-- ;
//         curr++;
//     }

//     return true ;
    
// }



// void util_sove(int col,vector<string> &board,vector<vector<string>> &ans,int n)
// {
//     if (col==n)
//     {
//         ans.push_back(board);
//         //done
//         return ;
//     }
//     //recursive for all rows 
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         //i1 is row 
//         if (isSafe1(i1,col,board,n))
//         {
//             board[i1][col] = 'Q';
//             util_sove(col+1,board ,ans, n) ;// see if it works
//             board[i1][col] = '.';//done with recursion 
//         }
        
//     }
    

    
// }




// vector<vector<string>> solveNQueens(int n) 
// {
//     vector<vector<string>> an1s ;
//     vector<string> board(n) ;
//     string s1(n,'.') ;
//     for (int i1 = 0; i1< n; i1++)
//     {
//         board[i1] = s1;
//     }
//     util_sove(0,board,an1s,n);
//     return an1s ;



// }

//gfg

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



void util_sove(int col,vector<string> &board,vector<vector<int>> &ans,int n,vector<int> &collist)
{
    if (col==n)
    {
        ans.push_back(collist);
        //     cout<<"\nDEBUG\n" ;
        // for (int i1 = 0; i1 < n; i1++)
        // {
        //     cout<<endl<<board[i1] ; 
        // }
    
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
            collist.push_back(i1+1) ;
            util_sove(col+1,board ,ans, n,collist) ;// see if it works
            collist.pop_back();
            board[i1][col] = '.';//done with recursion 
        }
        
    }
    

    
}




vector<vector<int>> solveNQueens(int n) 
{
    // vector<vector<string>> an1s ;
    vector<vector<int>>an1s ;
    vector<string> board(n) ;
    string s1(n,'.') ;
    vector<int> collist;
    for (int i1 = 0; i1< n; i1++)
    {
        board[i1] = s1;
    }
    util_sove(0,board,an1s,n,collist);


    return an1s ;



}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n ;
    vector<vector<int>> ans1 ;
    ans1 = solveNQueens(n);
    for (int i1 = 0; i1 < ans1.size(); i1++)
    {
        cout<<endl;
        for (int j1 = 0; j1 < ans1[i1].size(); j1++)
        {
            
            cout<<" "<<ans1[i1][j1];
        }
        
    }
    
    return 0;
}





