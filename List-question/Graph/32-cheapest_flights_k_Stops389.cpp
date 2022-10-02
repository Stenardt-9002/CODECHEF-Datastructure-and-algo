
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;


//use priority queue
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    // {
    //     //get graph 
    //     vector<vector<vector<int>>> grah1p(n);
    //     //src : dest,weight 
    //     for (auto flig: flights )
    //         grah1p[flig[0]].push_back({flig[1],flig[2]});


    //     priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> heap1 ;
    //     heap1.push(make_tuple(0,src,0)) ;//distance , src , atmost covered
    //     tuple<int,int,int> temp1 ;
    //     // tuple<int,int> forgraph;
    //     while (!heap1.empty())
    //     {
    //         temp1 = heap1.top() ;heap1.pop() ;
    //         int cost = get<0>(temp1);//distance
    //         int nod_e = get<1>(temp1);//node 
    //         int curek = get<2>(temp1);//current k

    //         if (nod_e==dst)//destination reached
    //             return cost ;

    //         if (curek>k)
    //             continue ;//cant do anything now stops crossed 

    //         //now children
    //         for (auto child : grah1p[nod_e] )
    //         {
    //             //src: //destination,weight
    //             // heap1.push({cost+child[1],child[0],curek+1 });
    //             heap1.push(make_tuple(cost+child[1],child[0],curek+1 ));

    //         }
    //     }
    //     return -1;
    // }



//use set
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        //get graph 
        vector<vector<vector<int>>> grah1p(n);
        //src : dest,weight 
        for (auto flig: flights )
            grah1p[flig[0]].push_back({flig[1],flig[2]});


        // priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> heap1 ;
        set<vector<int>> heap1;
        heap1.insert({0,src,0}) ;//distance , src , atmost covered
        vector<int> temp1 ;
        // tuple<int,int> forgraph;
        while (!heap1.empty())
        {
            temp1 = *heap1.begin()  ; heap1.erase(heap1.begin());
            int cost = temp1[0];//distance
            int nod_e = temp1[1];//node 
            int curek = temp1[2];//current k

            if (nod_e==dst)//destination reached
                return cost ;

            if (curek>k)
                continue ;//cant do anything now stops crossed 

            //now children
            for (auto child : grah1p[nod_e] )
            {
                //src: //destination,weight
                heap1.insert({cost+child[1],child[0],curek+1 });
                // heap1.push(make_tuple(cost+child[1],child[0],curek+1 ));

            }
        }
        return -1;
    }



int main(int argc, char const *argv[])
{
    int n,k,e;
    cin>>n>>k>>e ;
    int temo1,temp2,temp3;
    vector<vector<int>> flights;
    while (e--)
    {
        cin>>temo1>>temp2>>temp3;
        flights.push_back({temo1,temp2,temp3});
    }
    cout<<findCheapestPrice(n,flights,0,2,k);

    return 0;
}




