


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






int count_trainlge(vector<vector<int>> graph1,int V , bool isDirected)
{
    int cunt_triangle = 0 ;
    for (int i1 = 0; i1 < V; i1++)
        for (int j1 = 0; j1 < V; j1++)
            for (int k1 = 0; k1 < V; k1++)
                if(graph1[i1][j1] && graph1[i1][k1] && graph1[k1][j1] )
                    cunt_triangle++ ;

    if(isDirected)
        return cunt_triangle/3 ;

    else
        return cunt_triangle/6 ;
    

}




