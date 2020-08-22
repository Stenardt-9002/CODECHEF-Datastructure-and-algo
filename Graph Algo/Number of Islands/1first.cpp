#include<iostream>
#include<vector>



using namespace std;

int legalChanel(vector<int>A[],int N,int M)
{
    
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



