#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;





int min_dsiatnce(vector<int> dist,bool sptSet[],int vertex1)
{
    int min1 = INT_MAX ; int min_idx ;
    for (int v1 = 0; v1 < vertex1; v1++)
    {
        if (sptSet[v1]==false && dist[v1]<=min1)
        {
            min1 = dist[v1];min_idx = v1;
        }
        
    }
    return min_idx;
    

}





vector<int> dijkstar1(vector<vector<int>> grah1,int src,int vertix  )
{

    vector<int> distanc1e(vertix);
    bool sptSet[vertix];

    for (int i1 = 0; i1 < vertix; i1++)
    {
        distanc1e[i1] = INT_MAX;
        sptSet[i1] = false;
    }
    
    distanc1e[src] = 0;

    for (int eachvertix = 0; eachvertix < vertix-1; eachvertix++)
    {
        int findcontendervertix = min_dsiatnce(distanc1e,sptSet,vertix);

        sptSet[findcontendervertix] = true;


        for (int adcentvertix = 0; adcentvertix < vertix; adcentvertix++)
        {
            if (grah1[findcontendervertix][adcentvertix]!=0 && distanc1e[findcontendervertix]!=INT_MAX && distanc1e[findcontendervertix]+grah1[findcontendervertix][adcentvertix]<distanc1e[adcentvertix] )
            {
                distanc1e[adcentvertix] = distanc1e[findcontendervertix]+grah1[findcontendervertix][adcentvertix];
            }
            
        }
        


    }
    

    return distanc1e;




}



int main(int argc, char const *argv[])
{
        int testcazes ;int vertix  ;
    cin>>testcazes;
    int graph1[101][101];
    while (testcazes--)
    {
        cin>>vertix;
        vector<vector<int>>grah1(vertix);

        for (int j1 = 0; j1 < vertix; j1++)
            {
                // cin>>graph1[i1][j1];
                vector<int> temp1(vertix);
                grah1[j1] = temp1;

            }


        
        for (int i1 = 0; i1 < vertix; i1++)
        {
            for (int j1 = 0; j1 < vertix; j1++)
            {
                // cin>>graph1[i1][j1];
                cin>>grah1[i1][j1];

            }
            
        }
        

        
        
        // dijkstar1(graph1,0,vertix);


        int src;
        cin>>src;




        vector<int> res = dijkstar1(grah1,src,vertix);





    }
    



    
    return 0;

}





















