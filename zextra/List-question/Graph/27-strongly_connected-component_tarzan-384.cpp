





#include <bits/stdc++.h>
using namespace std;


void dfs_util(int src , vector<int> &disc ,vector<int> &low , vector<bool> &visted , vector<int> &answer1,int &time1,vector<int> adj[],int V,stack<int> *st)
{
    disc[src] = low[src] = ++time1 ;
    // answer1.push_back({src}) ; 
    st->push(src);
    visted[src] = true ;
    vector<int>::iterator i ;
    int des ;
    for (i=adj[src].begin() ;i!=adj[src].end() ;++i )
    {
        des = *i ;

        if (disc[des]==-1)
        {
            dfs_util(des,disc,low,visted,answer1,time1,adj,V,st);
            low[src] = min(low[src],low[des]);
        }
        else if (visted[des])
        {
            low[src] = min(low[src],disc[des]);
        }
        
    }

    int topval = 0;
    // vector<int> temp1 ;
    if (low[src]==disc[src])
    {
        while (st->top()!=src)
        {
            topval = (int)(st->top());
            // cout<<topval<<" ";

            answer1.push_back(topval);

            // temp1 = answer1[answer1.size()-1];
            // answer1.pop_back();
            // temp1.push_back(topval);
            // answer1.push_back(temp1) ;
            visted[topval] = false ;
            st->pop();
        }
        topval = (int)(st->top());
        // cout<<topval<<"\n";

        answer1.push_back(topval);
        answer1.push_back(-1);

        // temp1 = answer1[answer1.size()-1];
        // answer1.pop_back();
        // temp1.push_back(topval);
        // answer1.push_back(temp1) ;
        // answer1.push_back({}) ;
        visted[topval] = false ;
        st->pop();
    }

}


bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
 





    //of strongly connected components in the given graph.
vector<vector<int>> tarjans(int V, vector<int> adj[])
{
        //same as articulation point and bridges
    vector<int>disc(V,-1) ;
    vector<int>low(V,-1) ;
    vector<bool>visted(V,false) ;
    vector<vector<int>> answer1 ;
    vector<int> asnwer2 ;
    stack<int> *st = new stack<int>();
    int time1 = 0;

    for (int i1 = 0; i1 < V; i1++)
        if (disc[i1]==-1)
            dfs_util(i1,disc,low,visted,asnwer2,time1,adj,V,st);
    

    vector<int> temp1 ; 
    for (auto i: asnwer2)
    {
        if (i==-1)
        {
            sort(temp1.begin(),temp1.end());
            answer1.push_back(temp1) ;
            temp1 = {};
            // cout<<endl ;
        }   
        else
        {
            temp1.push_back(i) ;
            // cout<<i<<" ";
        }
    }
    
    sort(answer1.begin(),answer1.end(),sortcol);
    return answer1;
            
}




void addedge(int src,int des,vector<int>adj[])
{
    adj[src].push_back(des);
}

int main(int argc, char const *argv[])
{
    int V ,E;
    cin>>V>>E ;
    // V = 10 ;
    vector<int> adj1[V];
    int val1 , val2 ;
    for (int i1 = 0; i1 < E; i1++)
    {
        cin>>val1>>val2;
        addedge(val1,val2,adj1);
    }
    



    // addedge(0,1,adj1);
    // addedge(1,5,adj1);
    // addedge(5,0,adj1);
    // addedge(0,2,adj1);


    // addedge(2,3,adj1);
    // addedge(3,4,adj1);
    // addedge(4,2,adj1);


    // addedge(1,6,adj1);
    // addedge(6,7,adj1);
    // addedge(7,8,adj1);





    // addedge(8,9,adj1);
    // addedge(9,7,adj1);



    vector<vector<int>> asn1 = tarjans(V,adj1);
    for (auto i1 =asn1.begin(); i1 !=asn1.end(); i1++)
    {
        cout<<endl ;
        for (auto j:*i1 )
        {
            cout<<j<<" ";
        }
        
    }
    

    return 0;
}



