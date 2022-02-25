
// https://leetcode.com/problems/snakes-and-ladders/








#include <bits/stdc++.h>
using namespace std;

struct queuedata
{
    int vertex,distance ;
};



int snakesAndLadders(vector<vector<int>>& board) 
{
    int N = board.size() ;
    vector<bool>vsited(N*N,false) ;
    vector<int> moevs(N*N);
    bool reserve = true ;
    for (int i1 = 0; i1 < N; i1++)
    {
        if (reserve)
        {
            for (int j1 = 0; j1 < N; j1++)
            {
                moevs[i1*N+j1] = board[i1][j1];
            }    
        }
        else
        {
            for (int j1 = 0; j1 < N; j1++)
            {
                moevs[i1*N+j1] = board[i1][N-1-j1];
            }    
        }
        
        reserve = !reserve ;
        
    }
    
    queue<queuedata>q1 ;

    vsited[0] = true ;
    q1.push({0,0}); //0 vertex // distance 

    queuedata qtemp1 ,qtemp2  ;
    int v ;
    while (!q1.empty())
    {
        qtemp1 = q1.front()     ;
        v = qtemp1.vertex ;

        if (v==(N*N)-1)
            break ;

        q1.pop()         ;

        for (int j1 = v+1; j1 <=v+6 && j1<N*N; j1++)
        {
            if (!vsited[j1])
            {
                qtemp2.distance = qtemp1.distance+1 ;
                vsited[j1] = true ;

                if (moevs[j1]!=-1)
                    qtemp2.vertex = moevs[j1];

                else
                    qtemp2.vertex = j1 ;

                q1.push(qtemp2)                 ;

            }
        }
    }

    return qtemp1.distance ;

}



