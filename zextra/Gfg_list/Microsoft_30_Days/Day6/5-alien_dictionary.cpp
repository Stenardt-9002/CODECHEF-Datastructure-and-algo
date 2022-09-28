// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day6/problem/alien-dictionary







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void topoligval_sort_util( char src , unordered_map<char,bool> &visisted , stack<char> &s1 ,unordered_map<char , set<char>> graph1)
{
    visisted[src] = true ;
    
    for (auto chil : graph1[src])
        if(!visisted[chil])
            topoligval_sort_util(chil , visisted , s1 ,graph1 );
    
    s1.push(src);
}

string topological_sort(unordered_map<char , set<char>> graph1)
{
    stack<char> s1 ;
    unordered_map<char,bool> visisted;
    for (auto key : graph1)         
        visisted[key.first] = false;

    for (auto vertices : graph1)         
        if(!visisted[vertices.first])
            topoligval_sort_util(vertices.first , visisted , s1 , graph1);
    
    string ans1 = "";
    while(!s1.empty())
    {
        ans1+=s1.top();
        s1.pop();
    }
    
    return ans1 ;

}

string findOrder(string dict[], int N, int K) 
{
    //code here
    // vector<int> *graph1 = new vector<int>[K];
    // vector<vector<bool>> graph1(K,vector<bool>(K,false));
    unordered_map<char , set<char>> graph1 ;

    for (int i1 = 0; i1 < N-1; i1++)
    {
        string words1 = dict[i1] ;
        string words2 = dict[i1+1] ;
        for (int j1 = 0; j1 <min(words1.length() , words2.length()); j1++)
            if(words1[j1]!=words2[j1])
            {
                if(graph1[words2[j1]].find(words1[j1])!=graph1[words2[j1]].end())
                    return "-1";//this means ordereing is wrong
                graph1[words1[j1]].insert(words2[j1]);
                break ;
            }
        
    }
    
    return topological_sort(graph1);
}















