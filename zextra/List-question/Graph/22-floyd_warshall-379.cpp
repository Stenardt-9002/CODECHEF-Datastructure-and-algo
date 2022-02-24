
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix)
{
    int V = matrix.size() ;


    for(int k=0;k<V;k++)
        for (int i1 = 0; i1 < V; i1++)
        {
            for (int j1 = 0; j1 < V; j1++)
            {
                if ( (matrix[i1][k]!=0 &&matrix[k][j1]!=0) &&(matrix[i1][j1] > matrix[i1][k]+matrix[k][j1] ))
                {
                    matrix[i1][j1] = matrix[i1][k]+matrix[k][j1];
                }
                
            }
            
        }
}




