
  #include<iostream>
#include<vector> 
#include<algorithm>


using namespace std;
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
    {
        int row = -1;
        int col = m-1;
        for (int i1 = 0; i1 < n; i1++)
        {
            
            while (col>=0 && arr[i1][col]==1)
            {
                col-=1 ;
                row = i1 ; 
            }
            
        }
        return row ;

    }



int main(int argc, char const *argv[])
{

    int n,m ;

    cin>>n>>m ; 

    vector<vector<int>> arr(n,vector<int>(m));
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            cin>>arr[i1][j1] ; 
        }
        
    }

    // func(arr,m,\n)
    int asn = rowWithMax1s(arr,n,m) ;
    cout<<asn ;


    return 0;
}









