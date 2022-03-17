
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;



int findBeing_Celeb(int n,vector<vector<int> >& M)
{
    if (n==0)
        return -1;

    int id = findBeing_Celeb(n-1,M);
    if (id==-1)
        return n-1;
    
    else if (M[id][n-1])
        return n-1;    

    else if (M[n-1][id])
        return id ;

    return -1;
}




int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    int id = findBeing_Celeb(n,M);

    if (id==-1)
        return -1; //not found     
    else
    {
        int indeg1 = 0,outdeg2=0;
        for ( int i = 0;i<n  ;i++ )
        {
            //visit every member  except id and verify indegree as n-1 and outdegree 0
            if (i!=id)
            {
                outdeg2+= M[id][i] ;
                indeg1+=M[i][id];
            }
        }

        if (indeg1==n-1 && outdeg2==0)
            return id ;        

        return -1 ;
    }
}






