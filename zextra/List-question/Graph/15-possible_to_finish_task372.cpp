
// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/




#include <bits/stdc++.h>
using namespace std;





// bool dfs_util(int src, vector<int> graph1[],vector<bool> recursivestack,vector<bool> vsited)
// {
//     if (vsited[src])
//     {
//         return false ; //detect no cyle 
//     }
//     //now vsited 
//     vsited[src] = true ;
//     //in path recursive stack
//     recursivestack[src] = true;

//     for (auto neigh : graph1[src] )
//     {
//         if (recursivestack[neigh])
//         {
//             return true;
//         }
//         else if (dfs_util(neigh,graph1,recursivestack,vsited))
//         {
//             return true ;
//         }
        
        
//     }
//     recursivestack[src] = false ;
//     return false;
// }


// bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
// {
//     // vector<unordered_set<int>>graph1[N];
//     vector<int>graph1[N];
//     for (auto node  : prerequisites)
//     {
//         graph1[node.second].push_back(node.first);
//     }
//     //got graph
//     //detect cyle using DFS directed 
//     vector<bool>recursivestack(N,false);
//     vector<bool>vsited(N,false);

//     for (int i1 = 0; i1 < N; i1++)
//     {
//         if (!vsited[i1] && dfs_util(i1,graph1,recursivestack,vsited) )
//         {
//             return false ;
//         }
        
//     }
//     return true;


    
// }



// bool dfs_util(int src, vector<unordered_set<int>>graph1 ,vector<bool> recursivestack,vector<bool> vsited)
// {
//     if (vsited[src])
//     {
//         return false ; //detect no cyle 
//     }
//     //now vsited 
//     vsited[src] = true ;
//     //in path recursive stack
//     recursivestack[src] = true;

//     for (auto neigh : graph1[src] )
//     {
//         if (recursivestack[neigh]||dfs_util(neigh,graph1,recursivestack,vsited))
//         {
//             return true;
//         }
        
//     }
//     recursivestack[src] = false ;
//     return false;
// }


// bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
// {
//     vector<unordered_set<int>>graph1(N);
//     for (auto node  : prerequisites)
//     {
//         graph1[node.second].insert(node.first);
//     }
//     //got graph
//     //detect cyle using DFS directed 
//     vector<bool>recursivestack(N,false);
//     vector<bool>vsited(N,false);

//     for (int i1 = 0; i1 < N; i1++)
//     {
//         if (!vsited[i1] && dfs_util(i1,graph1,recursivestack,vsited) )
//         {
//             return false ; //not poosible a cycle
//         }
        
//     }
//     return true;


    
// }









bool isPossible(int n, vector<pair<int, int> >& prerequisites) 
{
    
   vector<vector<int>> adj( n);   
   vector<int> indegree( n, 0);
   for (auto &p: prerequisites) {
       adj[p.second].push_back(p.first);
       indegree[p.first]++;                               
   }
   queue<int> q;
   for (int i = 0; i <  n; i++)
       if (indegree[i] == 0) 
         q.push(i);
   while (!q.empty()) 
    {
       int curr = q.front(); 
       q.pop();
        n--;   
  
       for (auto next: adj[curr])
        {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
            return n == 0;          
                
}








