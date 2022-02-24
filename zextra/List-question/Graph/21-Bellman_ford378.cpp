// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1


#include<bits/stdc++.h>
using namespace std;



int isNegativeWeightCycle(int n, vector<vector<int>>edges)
{
    int noofedeg = edges.size() ;
    // n // nodes 
    vector<int>di1st(n,INT_MAX) ;
    di1st[0] = 0;

    int src,des,weight ;
    for (int i = 0; i < n-1; i++)
    {
        //for all edges
        for (int alle = 0; alle < noofedeg; alle++)
        {

            src = edges[alle][0] ;
            des = edges[alle][1] ;
            weight = edges[alle][2] ;
            if (di1st[src]!=INT_MAX && di1st[src]+weight<di1st[des])
            {
                di1st[des] = di1st[src]+weight;
            }
        }
    }   
    //now check once more if updation takes place then negative cycle 

    for (int alle = 0; alle < noofedeg; alle++)
        {

            src = edges[alle][0] ;
            des = edges[alle][1] ;
            weight = edges[alle][2] ;
            if (di1st[src]!=INT_MAX && di1st[src]+weight<di1st[des])
            {
                return 1 ;
                // di1st[des] = di1st[src]+weight;
            }
        }

        return 0 ;


}

