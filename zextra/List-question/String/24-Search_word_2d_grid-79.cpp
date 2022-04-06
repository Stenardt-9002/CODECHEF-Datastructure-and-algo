// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


bool valid_pos(int x, int y, int n , int m )
{
    return (x>=0&&y>=0 && x<n && y<m) ;
}


// bool check_coordingate(int i,int j,vector<vector<char>>grid, string word,int n ,int m,int curenlength)
// {
//     int arrx[] = {-1,-1,-1,0,0,1,1,1};
//     int arry[] = {1,0,-1,1,-1,1,0,-1,};
//     if(grid[i][j]==word[curenlength])
//     {
//         if(curenlength==word.size()-1)
//             return true ;

//         for (int i1 = 0; i1 < 8; i1++)
//         {
//             if(valid_pos(i+arrx[i1],j+arry[i1],n,m)&& check_coordingate(i+arrx[i1],j+arry[i1],grid,word,n,m,curenlength+1))
//                 return true ;
//         }        
//     }
//     return false ;
// }



// vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
// {
//     // Code here
//     set<vector<int>> s1 ;
//     int n = grid.size();
//     int m =grid[0].size();;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         // m = grid[i1].size();
//         for (int j1 = 0; j1 < m; j1++)
//         {
//             if(check_coordingate(i1,j1,grid,word,n,m,0))
//                 s1.insert({i1,j1});
//         }
//     }
//     vector<vector<int>>ans1 ;
//     for (auto x : s1)
//         ans1.push_back(x) ;
//     return ans1 ;
// }










bool check_coordingate(int i,int j,vector<vector<char>>grid, string word,int n ,int m,int curenlength)
{
    int arrx[] = {-1,-1,-1,0,0,1,1,1};
    int arry[] = {1,0,-1,1,-1,1,0,-1,};
    if(grid[i][j]==word[curenlength])
    {
        if(curenlength==word.size()-1)
            return true ;

        for (int i1 = 0; i1 < 8; i1++)
        {
            if(valid_pos(i+arrx[i1],j+arry[i1],n,m)&& check_coordingate(i+arrx[i1],j+arry[i1],grid,word,n,m,curenlength+1))
                return true ;
        }        
    }
    return false ;
}













vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
{
    // Code here
    set<vector<int>> s1 ;
    int n = grid.size();
    int m =grid[0].size();
    int word_size = word.size();
        int arrx[] = {-1,-1,-1,0,0,1,1,1};
    int arry[] = {1,0,-1,1,-1,1,0,-1,};
    int directionx ,directiony ;
    int posx , posy ;
    for (int i1 = 0; i1 < n; i1++)
    {
        // m = grid[i1].size();
        for (int j1 = 0; j1 < m; j1++)
        {
            if(grid[i1][j1]==word[0]&&s1.find({i1,j1})==s1.end())
            {             
                if(word_size==1)
                    s1.insert({i1,j1});
                else 
                {    for (int x = 0; x < 8; x++)
                        if(valid_pos(i1+arrx[x],j1+arry[x],n,m)&&grid[i1+arrx[x]][j1+arry[x]]==word[1] )
                        {
                            directionx = arrx[x] ;
                            directiony = arry[x] ;

                            posx = i1+directionx;posy = j1+directiony;
                            int cur_indx = 1 ;
                            while (cur_indx<word_size)
                            {
                                // cout<<"\nDEbug "<<posx<<" "<<posy<<" "<<grid[posx][posy]<<" "<<word[cur_indx]<<" "<<cur_indx<< endl;
                                if(!valid_pos(posx,posy,n,m) || grid[posx][posy]!=word[cur_indx])
                                    {
                                        break ;
                                    }

                                cur_indx++ ;
                                posx += directionx;
                                posy += directiony;
                            }
                            // cout<<"\n "<<cur_indx<<endl;
                            // cout<<"\nn "<<n<<endl;
                            if(cur_indx==word_size)
                                s1.insert({i1,j1});
                        }
                }
            }


        }
    }
    vector<vector<int>>ans1 ;
    for (auto x : s1)
        ans1.push_back(x) ;
    return ans1 ;
}



int main(int argc, char const *argv[])
{
    // vector<vector<char>>grid = {{'a','b','c'},{'d','r','f'},{'g','h','i'}};
    // vector<vector<char>>grid = {{'a','b','a','b'},{'a','b','e','b'},{'e','b','e','b'}};
    vector<vector<char>>grid = {{'c','b','a','c','e','a'}};

    string word = "ead";
    vector<vector<int>>ans1 = searchWord(grid,word);
    for (auto x : ans1)
        cout<<" "<<x[0]<<" "<<x[1]<<endl;
    return 0;
}






