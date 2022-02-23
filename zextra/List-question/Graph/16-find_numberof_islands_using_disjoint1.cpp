    
    
    // https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1


#include<bits/stdc++.h>
using namespace std;




class DisjointUnionSets
{
    
public:

    vector<int> rank , parent ;
    int n ;
    DisjointUnionSets(int n)
    {
        rank.resize(n) ; parent.resize(n);
        this->n = n ; 
        for (int i1 = 0; i1 < n; i1++)
        {
            parent[i1] = i1 ;
        }
    }


    int find(int x)
    {
        if (parent[x]!=x)
        {
            parent[x] = find(parent[x]) ;
        }
        return parent[x] ;//parent of all
    }

    void Union(int x,int y)
    {
        int xRoot = find(x) ; int yroot = find(y) ;
        if (xRoot==yroot)
            return ;
        if (rank[xRoot]<rank[yroot])
            parent[xRoot] = yroot ;
        else if (rank[yroot]<rank[xRoot])
            parent[yroot] = xRoot ;
        else
            {parent[yroot] = xRoot ; rank[xRoot]+=1;}

    }

};







    int numIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size() ; int m = grid[0].size() ;


        DisjointUnionSets *obj = new DisjointUnionSets(n*m);



        for (int i1 = 0; i1 < n; i1++)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                if (grid[i1][j1]==0)
                {
                    continue ;
                }



                if (i1+1<n && grid[i1+1][j1]==1)
                {
                    obj->Union(i1*m+j1,(i1+1)*m + j1);
                }
                
                if (i1-1>=0 && grid[i1-1][j1]==1)
                {
                    obj->Union(i1*m+j1,(i1-1)*m + j1);
                }
                
                if (j1+1<m && grid[i1][j1+1]==1)
                {
                    obj->Union(i1*m+j1,(i1)*m + j1+1);
                }
                
                if (j1-1>=0 && grid[i1][j1-1]==1)
                {
                    obj->Union(i1*m+j1,(i1)*m + j1-1);
                }
                
                if (i1+1<n && j1+1<m && grid[i1+1][j1+1]==1)
                {
                    obj->Union(i1*m+j1,(i1+1)*m + 1+j1);
                }
                
                if (i1+1<n && j1-1>=0 && grid[i1+1][j1-1]==1)
                {
                    obj->Union(i1*m+j1,(i1+1)*m + j1-1);
                }
                
                if (i1-1>=0 && j1+1<m && grid[i1-1][j1+1]==1)
                {
                    obj->Union(i1*m+j1,(i1-1)*m + j1+1);
                }
                if (i1-1>=0 && j1-1>=0 && grid[i1-1][j1-1]==1)
                {
                    obj->Union(i1*m+j1,(i1-1)*m + j1-1);
                }
                
            }
            
        }
        






        int componenets = 0;

        int *freq1 = new int[n*m] ;
        int curent ;
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                if (grid[i1][j1]==1)
                {
                    curent = obj->find(i1*m+j1);
                    if (freq1[curent]==0)
                    {
                        componenets++;freq1[curent]++;
                    }
                    else
                        freq1[curent]++;
                }
                                    



        return componenets ;
    }
    
int main(void)
{
    vector<vector<int>>a = {{1, 1, 0, 0, 0},
                            {0, 1, 0, 0, 1},
                            {1, 0, 0, 1, 1},
                            {0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1}};
    cout << "Number of Islands is: "
         << numIslands(a) << endl;
}



