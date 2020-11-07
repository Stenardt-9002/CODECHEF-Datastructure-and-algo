#include<iostream>



using namespace std;


int minmisKEY(int key[],bool mstSet[],int noofvertice)
{

    int min1 = INT_MAX; 
    int min_idx  ;
    for (int i1 = 0; i1 < noofvertice; i1++)
    {
        if (mstSet[i1]==false && key[i1<min1  )
        {
            min1 = key[i1];
            min_idx = i1;
        }
        

    }
    return min_idx;
    




}



void primMST(int **gra1ph,int noofvertice)
{

    int parent[noofvertice];
    int key[noofvertice];
    bool mstSet[noofvertice];

    //init keys 
    for (int i = 0; i < noofvertice; i++)
    {
        key[i] = INT_MAX ; 

        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1; // start node 
    for (int eachvertix = 0; eachvertix < noofvertice; eachvertix++)
    {
        // find vertice not in MST 

        int statvertx = minmisKEY(key,mstSet,noofvertice);
        mstSet[statvertx] = true ; 


        for (int edv = 0; edv < noofvertice; edv++)
        {
            if (gra1ph[statvertx][edv] != 0 && mstSet[edv]==false && gra1ph[statvertx][edv] < key[edv]  )
            {
                parent[edv]     = statvertx;
                key[edv] = gra1ph[statvertx][edv];
            }
            
        }
        




    }
    



}





int main(int argc, char const *argv[])
{
    int noofvertices ; 
    cin>>noofvertices;
    int **grap1h    ;

    grap1h = new int*[noofvertices];


    for (int i1 = 0; i1 < noofvertices; i1++)
    {
        grap1h[i1] = new int[noofvertices];
        for (int j1 = 0; j1 < noofvertices; j1++)
        {
            cin>>grap1h[i1][j1];
        }
        

    }

    primMST(grap1h);
    


    for (int i1 = 0; i1 < noofvertices; i1++)
    {
        delete [] grap1h[i1];
    }
    delete [] grap1h;


    return 0;
}










