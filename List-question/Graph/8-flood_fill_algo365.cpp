// https://leetcode.com/problems/flood-fill/

//DFS approach

#include<bits/stdc++.h>
using namespace std;



void flodfil_util(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor,int m ,int n) 
{
    if (sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc]!=oldcolor )
    {
        return ;
    }
    image[sr][sc] = newColor ;
    flodfil_util(image,sr+1,sc,newColor,oldcolor,m,n);
    flodfil_util(image,sr,sc+1,newColor,oldcolor,m,n);

    flodfil_util(image,sr,sc-1,newColor,oldcolor,m,n);
    flodfil_util(image,sr-1,sc,newColor,oldcolor,m,n);

    
}



vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int oldcolor = image[sr][sc] ;
    int m = image.size() ; int n = image[0].size();
    if (newColor==oldcolor)
    {
        return image ;
    }
    
    flodfil_util(image,sr,sc,newColor,oldcolor,m,n);
    return image ;
}


