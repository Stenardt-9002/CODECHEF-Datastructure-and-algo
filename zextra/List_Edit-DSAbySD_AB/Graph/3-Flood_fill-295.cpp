// https://leetcode.com/problems/flood-fill/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

void floodfill_util(vector<vector<int>>& image, int sr, int sc, int newColor,int oldColor) 
{
    int m = image.size();
    int n = image[0].size();
    int movex[] = {1,0,-1,0} ;
    int movey[] = {0,1,0,-1} ;
    queue<pair<int,int>> q1 ;
    q1.push({sr,sc});
    image[sr][sc] = newColor ;

    while (!q1.empty())
    {
        pair<int,int> top1 = q1.front();
        q1.pop();
        int x = top1.first ;int y = top1.second ;
        int newx , newy ;
        for (int ind = 0; ind < 4; ind++)
        {
            newx = x+movex[ind] ;
            newy = y+movey[ind] ;
            if(newx>=0 && newy>=0 && newx<m && newy<n&& image[newx][newy]==oldColor )
            {
                image[newx][newy] = newColor ;
                q1.push({newx,newy}) ;
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int oldcolor = image[sr][sc];
    if(oldcolor==newColor)
        return image;
    floodfill_util(image, sr,sc, newColor,oldcolor) ;
    return image ;
}






/*

    
void flodfil_util_bfs(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor,int m ,int n) 
{
    queue<pair<int,int>> q; //queue for BFS

    image[sr][sc] = newColor ;
    q.push({sr,sc}) ; //q has visited nodes 
    int movex[] = {1,0,-1,0} ;
    int movey[] = {0,1,0,-1} ;
    while (!q.empty())
    {
        int x = q.front().first ; int y = q.front().second ;
        q.pop() ;
        int newX,newY ;
        for (int ind = 0; ind < 4; ind++)
        {
            newX = x+movex[ind] ; newY = y+movey[ind] ;
            if (newX>=0 && newY>=0 && newX<m && newY<n && image[newX][newY]==oldcolor )
            {
                image[newX][newY] = newColor ; 
                q.push({newX,newY});
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int oldcolor = image[sr][sc] ;
    int m = image.size() ; int n = image[0].size();
    if (newColor==oldcolor) //no need to spread out 
    {        return image ;    }
    
    flodfil_util_bfs(image,sr,sc,newColor,oldcolor,m,n);
    return image ;
}

    



*/





