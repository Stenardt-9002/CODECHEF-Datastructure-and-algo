#include<iostream>
#include<limits.h>

using namespace std;

// int Findmincontestant(int dist[],bool sptSet[] ,int V)
// {
//     int min1 = INT_MAX ;
//     int min_idex;

//     for (int v1 = 0; v1 < V; v1++)
//     {
//         if (sptSet[v1]==false && dist[v1]<=min1  ) 
//         {
//             min1 = dist[v1];
//             min_idex = v1;
//         }
        
//     }
//     return min_idex; //give vertex of min distance and see all its neighbour


// }



int Findmincontestant(int dist[],bool sptSet[] ,int V,int src)
{
    int min1 = INT_MAX ;
    int min_idex;

    for (int v1 = 0; v1 < V; v1++)
    {
        if (sptSet[v1]==false && dist[v1]<=min1 &&v1!=src ) 
        {
            min1 = dist[v1];
            min_idex = v1;
        }
        
    }
    return min_idex; //give vertex of min distance and see all its neighbour


}









// void dijkstar1(int graph1[101][101],int src,int V)
// {


//     int Distance[V];
//     bool sptSet[V];

//     for (int allvert = 0; allvert < V; allvert++)
//     {
//         Distance[allvert] = INT16_MAX;
//         sptSet[allvert] = false;//noe of them included 
//     }
    
//     Distance[src] = 0;
//     for (int eeachvertix = 0; eeachvertix < V-1; eeachvertix++)
//     {
//         int min_idst_vert = Findmincontestant(Distance,sptSet , V);

//         sptSet[min_idst_vert] = true;

//         for (int v1 = 0; v1 < V; v1++)
//         {
//             if (!sptSet[v1] && graph1[min_idst_vert][v1]!=0 && Distance[min_idst_vert]!=0 && Distance[min_idst_vert]!=INT16_MAX &&
//                 Distance[min_idst_vert]+graph1[min_idst_vert][v1] < Distance[v1] 

//               ) 
//             {
//              Distance[v1] = Distance[min_idst_vert]+graph1[min_idst_vert][v1];
//             }
            
//         }
        



//     }
    


// }

void dijkstar1(int graph1[101][101],int src,int V)
{


    int Distance[V];
    bool sptSet[V];

    for (int allvert = 0; allvert < V; allvert++)
    {
        Distance[allvert] = INT16_MAX;
        sptSet[allvert] = false;//noe of them included 
    }
    
    Distance[src] = 0;
    for (int eeachvertix = 0; eeachvertix < V-1; eeachvertix++)
    {
        int min_idst_vert = Findmincontestant(Distance,sptSet , V,eeachvertix);

        sptSet[min_idst_vert] = true;

        for (int v1 = 0; v1 < V; v1++)
        {
            if (!sptSet[v1] && graph1[min_idst_vert][v1]!=0 && Distance[min_idst_vert]!=0 && Distance[min_idst_vert]!=INT16_MAX &&
                Distance[min_idst_vert]+graph1[min_idst_vert][v1] < Distance[v1] 
                &&v1!=min_idst_vert
              ) 
            {
             Distance[v1] = Distance[min_idst_vert]+graph1[min_idst_vert][v1];
            }
            
        }
        



    }
    


}







int main(int argc, char const *argv[])
{

    int testcazes ;int vertix  ;
    cin>>testcazes;
    int graph1[101][101];
    while (testcazes--)
    {
        cin>>vertix;
        
        for (int i1 = 0; i1 < vertix; i1++)
        {
            for (int j1 = 0; j1 < vertix; j1++)
            {
                cin>>graph1[i1][j1];
            }
            
        }
        

        dijkstar1(graph1,0,vertix);

    }
    



    
    return 0;
}
























