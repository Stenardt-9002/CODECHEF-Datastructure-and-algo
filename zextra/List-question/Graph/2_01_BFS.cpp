#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>
#include<climits>
#include<queue>

using namespace std;



// class Graph
// {
// private:
//     int V;
//     list<int> *adj ;
// public:
//     Graph(int V);
//     void addEdge(int v,int w);
//     vector<int> BFS(int s);


// };


// Graph::Graph(int V)
// {
//     this->V = V ;
//     this->adj = new list<int>[V];
// }
// void Graph :: addEdge(int v , int w)
// {
//     this->adj[v].push_back(w);
// }

// void Graph::BFS(int s)
// vector<int> Graph::BFS(int s)
// {
//     bool *visted = new bool[this->V] ;

//     for (int i1 = 0; i1 < this->V; i1++)
//     {
//         visted[i1] = false ;
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
// vector<int> Graph::BFS(int s)
// {
//     bool *visted = new bool[this->V] ;

//     for (int i1 = 0; i1 < this->V; i1++)
//     {
//         visted[i1] = false ;
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


    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        
        
          
        vector<int>adj1[V];
        for (int i1 = 0; i1 < V; i1++)
        {
            for (int j1 = 0; j1 < V; j1++)
            {
                
                adj1[i1].push_back(0);
            }
        }

        for(int i1 =0;i1<V;i1++)
        {
            for(int j1=0;j1<adj[i1].size();j1++)
            adj1[i1][adj[i1][j1]] = 1;
            // cout<<" "<<adj[i1][j1];
            // cout<<endl;
        }
        
        vector<bool> bvsited1(V,false);
        int src = 0;
        queue<int>q1 ;
        q1.push(src);
        // bvsited1[src] = true ;
        vector<int> ans1 ;
        // ans1.push_back(src) ;
        int nodes1 ;
        while (!q1.empty())
        {
            nodes1 = q1.front();
            q1.pop();
            if(!bvsited1[nodes1])
                {
                ans1.push_back(nodes1);
                bvsited1[nodes1] = true  ;
                }
            for (int i1 = 0; i1 < V; i1++)
            {
                if (i1!=nodes1 && adj1[nodes1][i1]==1 && !bvsited1[i1] ) //not a child 
                {
                    // bvsited1[i1] = true ;
                    q1.push(i1) ;
                    // ans1.push_back(i1);
                }
                
            }
            
            // ans1.push_back();

        }
        return ans1;
        
    }












int main(int argc, char const *argv[])
{
   
        int V ;
        cin>>V;
        vector<int>adj[V];
        for (int i1 = 0; i1 < V; i1++)
        {
            vector<int> a1(V,0);
            adj[i1] = a1;
            for (int j1 = 0; j1 < V; j1++)
            {
                cin>>adj[i1][j1] ;
            }
            
        }
        
        vector<int> asn1 = bfsOfGraph(V,adj);
        for (int i1 = 0; i1 < V; i1++)
        {
            cout<<" "<<asn1[i1];
        }
        

   
   
   
    // Graph g(4);
    // g.addEdge(0,1);
    // g.addEdge(0,2);

    // g.addEdge(0,2);
    // g.addEdge(2,0);
    // g.addEdge(2,3);
    // g.addEdge(3,3);



//     Graph g(5);

//     g.addEdge(0,1);
//     g.addEdge(0,2);

//     g.addEdge(0,3);
//     g.addEdge(2,4);



// vector<int> ans = g.BFS(0);
//     cout<<endl;
//     for (auto i1 = ans.begin(); i1!=ans.end(); i1++)
//     {
//         cout<<" "<<*i1;
//     }
    




    return 0;
}

























