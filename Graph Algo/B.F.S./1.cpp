#include<list>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

vector <int> bfs(vector<int> g[] , int N);

int main(int argc, char const *argv[])
{
    int Testcaes;
    cin>> Testcaes;   

    while(Testcaes--)
    {
        int N,E ;
        cin>>N>>E;
        vector<int> adj[N];
        for (int i1 = 0; i1 < E; i1++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
     
        }
        vector<int> res = bfs(adj,N);
        for (unsigned int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
            cout<<endl;
        }
        
    }

    return 0;
}

vector <int> bfs(vector<int> g[],int N)
{
    //set of visited 
    vector<int> ans;
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    list<int> que;
    visited[0] = true;//start with
    que.push_back(0);
    // list<int>::iterator iter;
    int start;
    while (!que.empty())
    {
        start = que.front();
        ans.push_back(start);
        que.pop_front();

        for (auto i1 = g[start].begin(); i1!=g[start].end(); i1++)
        {
            if (!visited[*i1]) //iterator vale
            {
                /* code */
                que.push_back(*i1);
                visited[*i1] = true;

            }
            


        }
        

    }
    
    return ans;
}

