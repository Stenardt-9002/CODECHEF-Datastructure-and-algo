// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/
#include <bits/stdc++.h>
using namespace std;



int minDistance(vector<int> distance , vector<bool> included,int V) 
{
	int min1 = INT_MAX ,min_indx=-1;
	for (int v = 0; v < V; v++)
	{
		if (!included[v] && min1>=distance[v])
		{
			min1 = distance[v] ; min_indx = v ;
		}
		
	}
	return min_indx ;
}

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here

		vector<int> distan(V,INT_MAX) ;
		vector<bool> included(V,false) ;

		distan[S] = 0 ;//src
		// included[S] = true ;

		for (int count1 = 0; count1 < V; count1++)
		{
			int u = minDistance(distan , included,V) ;
			included[u] = true ;
			// update neighbour of u
			for (int v = 0; v < adj[u].size(); v++)
			{
				if (!included[adj[u][v][0]])
				{
					if (distan[u]+adj[u][v][1] < distan[adj[u][v][0]])
					{
						distan[adj[u][v][0]] = distan[u]+adj[u][v][1];
					}
				}
			}

		}
		return distan ;
    }

















