

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


class Curreny_Block
{
public:
    int x,y,dis  ; 
    Curreny_Block(){};
    Curreny_Block(int x,int y, int dis)
    {
        this->x = x ;
        this->y = y ; 
        this->dis = dis ; 
    };
};

bool isInside_check(int x , int y ,int N)
{
    if(x>=1&&x<=N && y>=1 && y<=N)
        return true ;
    return false ;
}



int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    // Code here
    int dx1[] = {-2,-1,1,2,-2,-1,1,2};
    int dy1[] = {-1,-2,-2,-1,1,2,2,1};

    queue<Curreny_Block> q1 ;
    q1.push(Curreny_Block(KnightPos[0],KnightPos[1],0));
    
    vector<vector<bool>> ifvisited(N,vector<bool>(N,false));
    ifvisited[KnightPos[0]-1][KnightPos[1]-1] = true ;

    Curreny_Block Temp1 ;
    int newx , newy ;

    while (!q1.empty())
    {
        Temp1 = q1.front() ;
        q1.pop() ;
        if(Temp1.x==TargetPos[0] && Temp1.y == TargetPos[1] )
            return Temp1.dis ;
        for (int i1 = 0; i1 < 8; i1++)
        {
            newx = Temp1.x+dx1[i1];
            newy = Temp1.y+dy1[i1];
            if(isInside_check(newx,newy,N)&& !ifvisited[newx-1][newy-1])
            {
                ifvisited[newx-1][newy-1] = true ;
                q1.push(Curreny_Block(newx,newy,Temp1.dis+1));
            }
        }
    }
    return - 1;

}























