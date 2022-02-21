// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
#include<bits/stdc++.h>
using namespace std;


class Block
{
public:
    int x,y,dis ;
    Block(){};
    // Block(int x, int y , int dis):x(x),y(y),dis(dis){};
    Block(int x, int y , int dis){ this->dis=dis ;this->x=x ;this->y = y;};
};

  bool isInsidecheck(int x, int y,int N)
        {
            if(x>=1 && x<=N && y>=1 && y<=N)
                return true ;
        
            return false ;
        }


    
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    
	    
	        int dx1[] = {-2,-1,1,2,-2,-1,1,2} ;
            int dy1[] = {-1,-2,-2,-1,1,2,2,1} ; //posible moves
        
            queue<Block> q1 ;
            q1.push(Block(KnightPos[0],KnightPos[1],0));
        
            Block temp1;
            int newx,newy;
            vector<vector<bool>> visit;
            for (int i1 = 0; i1 < N+1; i1++)
            {
                visit.push_back(vector<bool>(N+1,false));
            }
            visit[KnightPos[0]][KnightPos[1]] = true ;
            //vistied
        
            while (!q1.empty())
            {
                temp1 = q1.front() ; q1.pop();
                if (temp1.x == TargetPos[0] && temp1.y == TargetPos[1])
                {
                    return temp1.dis ;
                }
                for (int i1 = 0; i1 < 8; i1++)
                {
                    newx = temp1.x + dx1[i1];newy = temp1.y+dy1[i1];
        
                    if (isInsidecheck(newx,newy,N)&&!visit[newx][newy])
                    {
                        visit[newx][newy] = true ; q1.push(Block(newx,newy,temp1.dis+1));
                    }
                }
            }
            return -1;
	}









int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    int dx1[] = {-2,-1,1,2,-2,-1,1,2} ;
    int dy1[] = {-1,-2,-2,-1,1,2,2,1} ; //posible moves

    queue<Block> q1 ;
    q1.push(Block(KnightPos[0],KnightPos[1],0));

    Block temp1;
    int newx,newy;
    vector<vector<bool>> visit;
    for (int i1 = 0; i1 < N+1; i1++)
    {
        visit.push_back(vector<bool>(N+1,false));
    }
    visit[KnightPos[0]][KnightPos[1]] = true ;
    //vistied

    while (!q1.empty())
    {
        temp1 = q1.front() ; q1.pop();
        if (temp1.x == TargetPos[0] && temp1.y == TargetPos[1])
        {
            return temp1.dis ;
        }
        for (int i1 = 0; i1 < 8; i1++)
        {
            newx = temp1.x + dx1[i1];newy = temp1.y+dy1[i1];

            if (isInsidecheck(newx,newy,N)&&!visit[newx][newy])
            {
                visit[newx][newy] = true ; q1.push(Block(newx,newy,temp1.dis+1));
            }
        }
    }
    return -1;
}





int main(int argc, char const *argv[])
{
    
    Block c1;
    
    return 0;
}












