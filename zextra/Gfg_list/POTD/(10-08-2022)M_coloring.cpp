// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1      
    



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



// bool dfs_util(int src , int colours , vector<int> &visited, bool graph1[101][101])
// bool dfs_util(int src , int colours , int n ,vector<int> &visited, vector<int> *graph1)
// {
//     // int cur_color = visited[src];


//     //assing colour
//     vector<bool> array_current_colour(colours,false);
//     //check colour 
//     for (auto neig:graph1[src])
//         if(visited[neig]!=-1)
//         array_current_colour[visited[neig]] = true ; // done neighbors colours 

//     int colur_allowed = -1;
//     for (int i1 = 0; i1 < colours; i1++)
//         if(array_current_colour[i1]==false)    
//             colur_allowed = i1 ;
    
//     if(colur_allowed == -1)
//         return false ; // no colour left  

//     visited[src] = colur_allowed ; 


    
//     //new dfs util 
//     for (auto neigi1:graph1[src])
//         if(visited[neigi1]==-1)
//             if(!dfs_util(neigi1 ,colours,n, visited ,graph1))
//                 return false ;
    

//     return true ;


// }


// bool graphColoring(bool graph[101][101], int m, int n) 
// {
//     // your code here
//     vector<int> visted(n,-1);


//     vector<int> *new_graphp = new vector<int>[n];
//     for (int i1 = 0; i1 < n; i1++)
//         for (int j1 = 0; j1 < n; j1++)
//             if(graph[i1][j1])
//                 new_graphp[i1].push_back(j1);
    

//     for (int i1 = 0; i1 < n; i1++)
//         if(visted[i1]==-1)
//             if(!dfs_util(i1 ,m,n, visted , new_graphp))
//                 return false ;
    


//     return true ;

// }




bool is_colour_allowed(int src , int c1 , bool graph1[101][101],vector<int>colour_list , int n)
{
    for (int i1 = 0; i1 < n; i1++)
        if(graph1[src][i1] && (c1 == colour_list[i1]))
            return false ;
    return true ;
}





bool graph_colour_util1(bool graph[101][101] ,int m , vector<int>&color_list , int n , int src )
{
    if(src == n)
        return true ; 
    //try all clolurs 
    for (int  c1 = 0; c1 < m; c1++)
    {
        if(is_colour_allowed(src , c1 , graph , color_list ,n))    
        {
            color_list[src] = c1 ;

            if(graph_colour_util1(graph,m,color_list,n,src+1))
                return true ;


            color_list[src] = -1 ;//if fial backtracking 
        }
    }
    
    return false ;// no color list found 

}




bool graphColoring(bool graph[101][101], int m, int n) 
{
    vector<int>color_list(n,-1 )   ;
    if(!graph_colour_util1(graph , m , color_list , n , 0))
        return false ;

    return true ;
}





int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n;
    testcase=2 ;
    while (testcase--)
    {
        cin>>n;
        // cout<<nineDivisors(n);
    }
    return 0 ;
}








