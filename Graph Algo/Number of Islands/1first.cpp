#include<iostream>
#include<vector>
#include<stdio.h>


using namespace std;

void Util_DFS_func(vector<int> matrix[] ,int i1,int j1, int row,int col, int **visited)
{

    int x_dir[] = {-1,-1,-1, 0,0, 1,1,1};
    int y_dir[] = {-1,-0, 1,-1,1,-1,0,1};
    visited[i1][j1] = true;

    for (int k1 = 0; k1 < 8; k1++)
    {
        if (isSafe())
        {
            
        }
        
    }
    


}


int legalChanel(vector<int>A[],int N,int M)
{
    bool visited[N][M];
    memset(visited,0,sizeof(visited) );

    int count_1 = 0; // asnwer of islans
    for (int i1 = 0; i1 < N; i1++)
    {
        for (int j1 = 0; j1 < M; j1++)
        {
            if (A[i1][j1] && !visited[i1][j1] )
            {
                
                    Util_DFS_func(A,i1,j1,N,M,visited);
                    count_1++;
            }
            
        }
        
    }
    







}


int main(int argc, char const *argv[])
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int N,M;
        cin>>N>>M;
        vector<int> Arr1[N];
        
        for (int i1 = 0; i1 < N; i1++)
        {
            vector<int> te1mp(M);
            Arr1[i1] = te1mp;
            for (int j1 = 0; j1 < M; j1++)
            {
                cin>>Arr1[i1][j1];
            }
            
        }
        
        cout<< legalChanel(Arr1,N,M)<<endl;

    }
    return 0;
}



