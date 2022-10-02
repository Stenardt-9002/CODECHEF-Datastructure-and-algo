#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

int isallowed(vector<int> matrix[],int row,int col,int i1 ,int j1,bool **visited)
{
    return  ((i1>=0) && (i1<row) &&(j1>=0) &&(j1<col) && (matrix[i1][j1]=1) && (visited[i1][j1]==false));
}







void Util_DFS_func(vector<int> matrix[] ,int i1,int j1, int row,int col, bool **visited)
{

    int x_dir[] = {-1,-1,-1, 0, 0, 1,1,1};
    int y_dir[] = {-1,-0, 1, 1,-1,-1,0,1};
    visited[i1][j1] = true; //

    for (int k1 = 0; k1 < 8; k1++)
    {
        if (isallowed(matrix,row,col,i1+x_dir[k1],j1+y_dir[k1],visited))
        {
            // if tis is one the go uck thyself;
            Util_DFS_func(matrix,i1+x_dir[k1],j1+y_dir[k1],row,col,visited);
            cout<<endl<<"Michael Vsauce"<<i1<<" "<<j1<<" "<<k1<<"\n";
                       for (int i34t = 0; i34t < row; i34t++)
                            {
                                cout<<endl;
                                // vector<int> te1mp(M);
                                // Arr1[i34t] = te1mp;
                                for (int j1tra = 0; j1tra < col; j1tra++)
                                {
                                cout<<visited[i34t][j1tra]<<" ";
                                }
                        
                            }
                            cout<<endl;
        }
        
    }
    


}


int legalChanel(vector<int>A[],int N,int M)
{
    // bool visited[N][M];
// 3 3
// 1 1 0 0 0 1 1 0 1
        // for (int i1 = 0; i1 < N; i1++)
        // {
        //     cout<<endl;
        //     // vector<int> te1mp(M);
        //     // Arr1[i1] = te1mp;
        //     for (int j1 = 0; j1 < M; j1++)
        //     {
        //         cout<<A[i1][j1]<<" ";
        //     }
            
        // }

    
    bool **visited ;
    visited = new bool*[N];

    for (int i13 = 0; i13 < N; i13++)
    {
        visited[i13] = new bool[M];
        for (int j12 = 0; j12 < M; j12++)
        {
            visited[i13][j12] = 0;
        }
        

    }

    



    // memset(visited,0,sizeof(visited) );

    int count_1 = 0; // asnwer of islans
    for (int itravar1 = 0; itravar1 < N; itravar1++)
    {
        for (int j1tra = 0; j1tra < M; j1tra++)
        {
            if (A[itravar1][j1tra] && !visited[itravar1][j1tra] )
            {
                
                    Util_DFS_func(A,itravar1,j1tra,N,M,visited);
                           for (int i34t = 0; i34t < N; i34t++)
                            {
                                cout<<endl;
                                // vector<int> te1mp(M);
                                // Arr1[i34t] = te1mp;
                                for (int j1tra = 0; j1tra < M; j1tra++)
                                {
                                cout<<visited[i34t][j1tra]<<" ";
                                }
                        
                            }
                            cout<<endl;

                    count_1++;
            }
            
        }
        
    }
    
        //     for (int itravar1 = 0; itravar1 < N; itravar1++)
        // {
        //     cout<<endl;
        //     // vector<int> te1mp(M);
        //     // Arr1[itravar1] = te1mp;
        //     for (int j1 = 0; j1 < M; j1++)
        //     {
        //         cout<<visited[itravar1][j1]<<" ";
        //     }
            
        // }



    for (int i13 = 0; i13 < N; i13++)
    {
       delete [] visited[i13] ;//= new bool[i13];
    }
    

    delete []visited;

    return count_1;

// return 0;
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

        // for (int i1 = 0; i1 < N; i1++)
        // {
        //     cout<<endl;
        //     // vector<int> te1mp(M);
        //     // Arr1[i1] = te1mp;
        //     for (int j1 = 0; j1 < M; j1++)
        //     {
        //         cout<<Arr1[i1][j1]<<" ";
        //     }
            
        // }



        
        cout<< legalChanel(Arr1,N,M)<<endl;

    }
    return 0;
}



