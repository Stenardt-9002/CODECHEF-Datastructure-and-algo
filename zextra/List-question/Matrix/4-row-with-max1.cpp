
  #include<iostream>
#include<vector> 
#include<algorithm>


using namespace std;
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
    {
        int j1 = 0 ;
        while (j1<m)
        {    
            for (int i1 = 0; i1 < n; i1++)
            {
                if(arr[i1][j1]==1)
                {
                    return i1 ;
                }
            }
            j1++ ; 
        }    
        return -1 ;

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









