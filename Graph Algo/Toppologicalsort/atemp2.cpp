#include<iostream>
#include<stack>
#include<list>
#include<vector>



using namespace std;

void topUtilfuc(int ver,bool visted[],stack<int>&sta,vector<int> adj[])
{

    // not this vertex is visted 
    visted[ver] = true;
    // all its connection 
    for (auto i1 = adj[ver].begin(); i1!=adj[ver].end()  ; i1++)
    {
        if (visted[*i1]==false)
        {
            //add to recursion go to stack
            topUtilfuc(*i1,visted,sta,adj);

        }
        
    }

    //finally end recursion added to stack 
    sta.push(ver);
    


}






vector<int> topSort(int N,vector<int> adj[])
{

    // uagwe of stack 
    vector<int> asnwe;
    stack<int> stac_k1;


    bool *visited = new bool[N];//no of vertex
    for (int i1 = 0; i1 < N; i1++)
    {
        visited[i1] = false;
    }

    for (int eachver = 0; eachver < N; eachver++)
    {
        // if not visted 
        if (visited[eachver]==false )
        {
            // visted all directed shiz 
            topUtilfuc(eachver,visited,stac_k1,adj);
            
        }
        
    }
    while (!stac_k1.empty())
    {   
        asnwe.push_back(stac_k1.top());
        stac_k1.pop();
    }
    
    


    return asnwe;





}




int main(int argc, char const *argv[])
{
    int testcaes;

    cin>>testcaes;

    while (testcaes--)
    {

        
        int no_edges,no_vertex;
        cin>>no_edges>>no_vertex;

        int ver1,ver2;

        vector<int> *list_gra;
        list_gra = new vector<int>[no_vertex];


        for (int i1 = 0; i1 < no_edges; i1++)
        {
            cin>>ver1>>ver2;
            list_gra[ver1].push_back(ver2);
        }
        

        vector<int> asnwer = topSort(no_vertex,list_gra);




    }








    return 0;
}













