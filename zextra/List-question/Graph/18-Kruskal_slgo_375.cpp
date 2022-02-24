

// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/
#include<bits/stdc++.h>
using namespace std;



class Unionoject
{
public:
    int *parent     ;
    int *rank ;
    Unionoject(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i1 = 0; i1 < n; i1++)
        {
            parent[i1] = -1 ; rank[i1] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i]==-1)
            return i ;//topper
        return parent[i] = find(parent[i]) ;
    }

    void unite(int x , int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1!=s2)
        {
            if (rank[s1]<rank[s2])
            {
                parent[s1] = s2 ; //s1 parents is s2 
                rank[s2] +=rank[s1] ; //both union 
            }
            else
            {
                parent[s2] = s1 ;
                rank[s1]+=rank[s2] ;
            }
        }
    }



};




int spanningTree(int V, vector<vector<int>> adj[])

 {    int v = V;
        vector<vector<int>> graph1;
        for(int i1 =0;i1<V;i1++)
        {
            for(auto j: adj[i1])
            {
                graph1.push_back({j[1],i1,j[0]});
            }
        }
        
    
            sort(graph1.begin(),graph1.end()) ;
    
        Unionoject obj1(v);
        int asn1 = 0 ;
    
        for (auto edge : graph1)
        {
            int wegiht = edge[0] ;
            int src = edge[1] ;
            int des = edge[2] ;
    
            if (obj1.find(src)!=obj1.find(des)) //not in same set
            {
                obj1.unite(src,des) ;
                asn1+=wegiht ;
            }
        }
        return asn1 ;    
    
            
        
    }


int kruskal_mst(int v , vector<vector<int> > graph1)
{

    sort(graph1.begin(),graph1.end()) ;
    // /select shotreset weight and check if not cycle
    Unionoject obj1(v);
    int asn1 = 0 ;

    for (auto edge : graph1)
    {
        int wegiht = edge[0] ;
        int src = edge[1] ;
        int des = edge[2] ;

        if (obj1.find(src)!=obj1.find(des)) //not in same set
        {
            obj1.unite(src,des) ;
            asn1+=wegiht ;
        }
    }
    return asn1 ;    




}




int main(int argc, char const *argv[])
{
    int V;
    vector<vector<int> > graph1;


//src dest weight

    graph1.push_back({ 10, 0, 1 });
    graph1.push_back({ 15, 1, 3 });
    graph1.push_back({ 4, 2, 3 });
    graph1.push_back({ 6, 2, 0 });
    graph1.push_back({ 5, 0, 3 });


    return 0;
}












