#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>
#include<climits>
using namespace std;



class Graph
{
private:
    int V;
    list<int> *adj ;
    bool *visited = new bool[V] ;

public:
    Graph(int V);
    void addEdge(int v,int w);
    // void dfsOfGraph(int s);
    void DFS_util(int src, int V , bool * &visited , list<int> adj[],vector<int> &answer);
    // vector<int> dfsOfGraph(int V, vector<int> adj[]) ;
    vector<int> dfsOfGraph(int V) ;


    // vector<int> DFS_util(int s);


};


Graph::Graph(int V)
{
    this->V = V ;
    this->adj = new list<int>[V];
}
void Graph :: addEdge(int v , int w)
{
    this->adj[v].push_back(w);
}

// // void Graph::BFS(int s)
// void Graph::BFS(int s)
// {
//     bool *visted = new bool[this->V] ;

//     for (int i1 = 0; i1 < this->V; i1++)
//     {
//         visted[s] = false ;
//     }


//     visted[s] = true ; //src visted 
//     //queue for BFS 
//     list<int> que1 ;
//     que1.push_back(s) ;//src s
//     vector<int> answer1 ;
//     while (!que1.empty())
//     {
//         s = que1.front() ;
//         answer1.push_back(s);
//         que1.pop_front() ;

//         //visit all children 
//         for (auto i2 = this->adj[s].begin(); i2 != this->adj[s].end(); i2++)
//         {
//             if (!visted[*i2])
//             {
//                 visted[*i2] = true ;// seen
//                 que1.push_back(*i2) ;
//             }
            
//         }
        


//     }
    
    



//     delete [] visted;

//     return answer1;
// }

    // vector<int> Graph:: dfsOfGraph(int V, vector<int> adj[]) 
    vector<int> Graph:: dfsOfGraph(int V) 
    {
        bool *visited  = new bool[V];
        vector<int> answer ;
        for(int i=0;i<V;i++)
        {
            visited[i] = 0;//no one vistedf yet ;
        }
        this->DFS_util(0,V,visited,this->adj,answer);
        
        return answer ;
        
    }
    void Graph:: DFS_util(int src, int V , bool * &visited , list<int> adj[],vector<int> &answer)
    {
        visited[src] = 1 ;
        
        answer.push_back(src) ;
        
        for(auto i1=adj[src].begin() ;i1!=adj[src].end();i1++)
        {
            if(!visited[*i1]){ DFS_util(*i1,V,visited,adj,answer) ;}
        }
        
        
    }













//correct solution 
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        bool *visited  = new bool[V];
        vector<int> answer ;
        for(int i=0;i<V;i++)
        {
            visited[i] = 0;//no one vistedf yet ;
        }
        DFS_util(0,V,visited,adj,answer);
        
        return answer ;
        
    }
    void DFS_util(int src, int V , bool * &visited , vector<int> adj[],vector<int> &answer)
    {
        visited[src] = 1 ;
        
        answer.push_back(src) ;
        
        for(auto i1=adj[src].begin() ;i1!=adj[src].end();i1++)
        {
            if(!visited[*i1]){ DFS_util(*i1,V,visited,adj,answer) ;}
        }
        
        
    }
    

int main(int argc, char const *argv[])
{
    // Graph g(4);
    // g.addEdge(0,1);
    // g.addEdge(0,2);

    // g.addEdge(0,2);
    // g.addEdge(2,0);
    // g.addEdge(2,3);
    // g.addEdge(3,3);



    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(4,3);



vector<int> ans = g.dfsOfGraph(0) ;
    cout<<endl;
    for (auto i1 = ans.begin(); i1!=ans.end(); i1++)
    {
        cout<<" "<<*i1;
    }
    




    return 0;
}

























