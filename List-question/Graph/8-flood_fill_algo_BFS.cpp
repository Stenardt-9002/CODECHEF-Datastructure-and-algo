// https://leetcode.com/problems/flood-fill/

//DFS approach

#include<bits/stdc++.h>
using namespace std;

void flodfil_util_bfs(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor,int m ,int n) 
{
    queue<pair<int,int>> q; //queue for BFS

    image[sr][sc] = newColor ;
    q.push({sr,sc}) ; //q has visited nodes 
    
    while (!q.empty())
    {
        int x = q.front().first ; int y = q.front().second ;
        q.pop() ;
        int movex[] = {1,0,-1,0} ;
        int movey[] = {0,1,0,-1} ;

        int newX,newY ;

        for (int ind = 0; ind < 4; ind++)
        {
            newX = x+movex[ind] ; newY = y+movey[ind] ;
            if (newX>=0 && newY>=0 && newX<m && newY<n && image[newX][newY]==oldcolor )
            {
                image[newX][newY] = newColor ; q.push({newX,newY});
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




int main(int argc, char const *argv[])
{
    
    return 0;
}






