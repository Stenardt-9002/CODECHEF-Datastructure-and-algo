

// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1/?page=1&curated[]=5&sortBy=submissions


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


//start from (0,0) to (n-1,m-1)
int bfs_util(vector<vector<int>>&matr , int k ,int n , int m)
{
    vector<vector<int>>visisted(n,vector<int>(m,-1))    ;
    queue<tuple<int,int,int,int>> q1 ; //x , y , current path , k left

    q1.push(make_tuple(0,0,0,k));

    while(!q1.empty())
    {
        tuple<int,int,int,int> t1 = q1.front();
        int curx = get<0>(t1);
        int cury = get<1>(t1);
        int curd = get<2>(t1);
        int curk = get<3>(t1);
        q1.pop();
        // cout<<"reavcjed";
        if(curx<0||curx>=n||cury<0||cury>=m)
            continue ; //continue with loop

        //answer reached 
        if(curx==n-1&&cury==m-1)
            return curd;

        if(matr[curx][cury]==1)//wall found
        {
            if(curk<=0)
                continue ;
            curk-- ;
        }

        //NOT VISISTED 
        if(visisted[curx][cury]!=-1 && visisted[curx][cury]>=curk)//if better curk is not possible continue
            continue ;

        visisted[curx][cury] = curk ;//vsisted and curk is the better possibilty


        //queue push 4 direction 
        q1.push(make_tuple(curx+1,cury,curd+1,curk));
        q1.push(make_tuple(curx-1,cury,curd+1,curk));
        q1.push(make_tuple(curx,cury+1,curd+1,curk));
        q1.push(make_tuple(curx,cury-1,curd+1,curk));

    }

    return -1 ;
}




int shotestPath(vector<vector<int>> mat, int n, int m, int k) 
{
    // code here    
    return bfs_util(mat,k,n,m);
}

int main(int argc, char const *argv[])
{
    int n , m ,k ;
    cin>>n>>m>>k ;
    vector<vector<int>>matr(n,vector<int>(m,-1));
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            cin>>matr[i1][j1];


    // for (int i1 = 0; i1 < n; i1++)
    // {    
    //     cout<<endl;
    //     for (int j1 = 0; j1 < m; j1++)
    //         cout<<" "<<matr[i1][j1];

    // }

    cout<<" "<<shotestPath(matr,n,m,k);



    return 0;
}
