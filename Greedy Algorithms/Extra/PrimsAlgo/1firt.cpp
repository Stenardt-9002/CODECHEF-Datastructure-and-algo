#include <iostream>
#include <list>
#include <utility>
#include<queue>
#include<climits>

using namespace std;


class Graph1
{
    
public:

    int V;

    list< pair<int,int> > *adj;

    Graph1(int V1)
    {
        this->V = V1;
        adj = new list<pair<int,int>>[V1];
    };

    void addEdge(int u,int v,int w)
    {
        //src u ,v and //weight w
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }

    void primMSTcreator()
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >pqueue1;

        int src = 0;

        vector<int> parent(V,-1); //initialise all elements to -1

        //store parent array which in turn store MST 
        vector<int>MSTstroage(V,false);

        vector<int>key(V,INT_MAX);
        
        pqueue1.push(make_pair(0,src));

        key[src] = 0;

    while (!pqueue1.empty())
    {
        int tempsrc = pqueue1.top().second; 

        MSTstroage[tempsrc] = true;
        pqueue1.pop();
        // auto i1;
        // every connetction to src 
        for (auto i1 = adj[src].begin(); i1 != adj[src].end() ; i1++)
        {
            int v = (*i1).first; //get second vertex 
            int weight = (*i1).second; //get weight
            if (MSTstroage[v] == false && key[v] > weight  ) //v is not part of MST
            {
                    key[v] = weight; //update least wieght
                    pqueue1.push(make_pair(key[v],v)); //least weight and vertex
                    parent[v] = tempsrc;
            }
            



        }
        


    }




    }

};






int main(int argc, char const *argv[])
{

    int vertic1 = 9;
    Graph1 g1(vertic1);
    
    return 0;
}




