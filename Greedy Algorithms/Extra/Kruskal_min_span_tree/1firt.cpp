#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

class Edge
{
    public:
    int src,dest,weight ;
};


class Graph
{
    public:
    int V,E;
    Edge *edgelist;
};

class subset  
{  
    public: 
    int parent;  
    int rank;  
}; 


Graph* createGraph(int V,int E)
{
    Graph* graphvar = new Graph;
    graphvar->V = V;
    graphvar->E = E;
    graphvar-> edgelist = new Edge[E];
    return graphvar;

}


int find(subset subsets[],int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}



void Union(subset subsets[] ,int x1 ,int y1)
{
    //combining new edge

    int xrotpar = find(subsets,x1);
    int yrotpar = find(subsets,y1);


    if (subsets[xrotpar].rank<subsets[yrotpar].rank )
    {
        subsets[xrotpar].parent = yrotpar;

    }
    
    else if (subsets[xrotpar].rank>subsets[yrotpar].rank )
    {
        subsets[yrotpar].parent = xrotpar;
        
    }
    else
    {
        // both rank equal 
        subsets[yrotpar].parent = xrotpar;
        subsets[xrotpar].rank++;
    }
    
    



}



bool compare1(Edge a1,Edge b1)
{
    // Edge* a1 = (Edge*)a;
    // Edge* b1 = (Edge*)b;
    // return a1->weight>b1->weight;
    return a1.weight<b1.weight;

}

void KruskMSTcreate(Graph *graph12)
{
    int V = graph12->V;
    Edge result[V];
    sort(graph12->edgelist,graph12->edgelist+graph12->E,compare1);
    // for (int i1 = 0; i1 < graph12->E; i1++)
    // {
    //     cout<<endl<<" "<<graph12->edgelist[i1].src<<" "<<graph12->edgelist[i1].weight;
    // }
    
    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  

    int edges_til = 0 , itra = 0;


    while (edges_til<V-1 && itra < graph12->E)
    {
        Edge next_contender = graph12->edgelist[itra++];

    //using disjoint subset union 
        int x1 = find(subsets,next_contender.src); //parent
        int y1 = find(subsets,next_contender.dest); //parent

        if (x1!=y1)
        {
            result[edges_til++] = next_contender;
            //allowed now add to rank 
            Union(subsets,x1,y1);


        }
        



    }
    









}








int main(int argc, char const *argv[])
{
    int V,E;

    cin>>V>>E;

    Graph *grahp_oper = createGraph(V,E);

    grahp_oper->edgelist[0].src = 0;  
    grahp_oper->edgelist[0].dest = 1;  
    grahp_oper->edgelist[0].weight = 10;  
  
    // add edgelist 0-2  
    grahp_oper->edgelist[1].src = 0;  
    grahp_oper->edgelist[1].dest = 2;  
    grahp_oper->edgelist[1].weight = 6;  
  
    // add edgelist 0-3  
    grahp_oper->edgelist[2].src = 0;  
    grahp_oper->edgelist[2].dest = 3;  
    grahp_oper->edgelist[2].weight = 5;  
  
    // add edgelist 1-3  
    grahp_oper->edgelist[3].src = 1;  
    grahp_oper->edgelist[3].dest = 3;  
    grahp_oper->edgelist[3].weight = 15;  
  
    // add edge 2-3  
    grahp_oper->edgelist[4].src = 2;  
    grahp_oper->edgelist[4].dest = 3;  
    grahp_oper->edgelist[4].weight = 4;
    KruskMSTcreate(grahp_oper);

    delete [] grahp_oper;
    return 0;
}
