

// https://practice.geeksforgeeks.org/problems/alien-dictionary/1




#include <bits/stdc++.h>
using namespace std;


void top_dfs(int src, vector<vector<int>> graph1 , int n, vector<bool> &visited,stack<int> &var1)
{
    visited[src] = true ;

    for (auto i1 = graph1[src].begin(); i1 !=graph1[src].end(); i1++)
    {
        if (!visited[*i1])
        {
            top_dfs(*i1,graph1,n,visited,var1);
        }
        
    }
    var1.push(src);
}



string topological_sort(vector<vector<int>> graph1,int n)
{
    string ans1 = "" ;
    stack<int>var1 ;
    vector<bool> visited(n,false );
    for (int i1 = 0; i1 < n; i1++)
    {
        if (!visited[i1])
        {
            top_dfs(i1,graph1,n,visited,var1);
        }
        
    }
    char c1 ;
    while (!var1.empty())
    {
        c1 = (char)(var1.top()+'a');
        var1.pop();
        ans1 +=c1 ;
    }
    
    return ans1 ;
}




string findOrder(string dict[], int N, int K) 
{
    // N : words 
    // K : letters
    int n = K ;
    vector<vector<int>> graph1(n);
    //all adjacent words in sorted order 

    string firstword ,secondword ;

    for (int i1 = 0; i1 < N-1; i1++)
    {
        firstword = dict[i1] ;
        secondword = dict[i1+1];

        //all letter comparision 
        for (int curentletter = 0; curentletter < min(firstword.length(),secondword.length()); curentletter++)
        {
            if (firstword[curentletter]!=secondword[curentletter])
            {
                graph1[firstword[curentletter]-'a'].push_back(secondword[curentletter]-'a') ;
                //no continue
                break ;//break for loop
            }
        }
    }
    
    //call top sort 
    string ans1 = topological_sort(graph1,n) ;
    return ans1;
}









