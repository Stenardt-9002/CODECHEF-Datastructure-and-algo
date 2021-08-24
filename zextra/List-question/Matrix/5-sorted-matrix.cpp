
  #include<iostream>
#include<vector> 
#include<algorithm>


using namespace std;



vector<vector<int>> sortedMatrix(int N , vector<vector<int>> Mat)
{
    vector<int> temp1 ;
    // int sizeN = N ;
    for (int i1 = 0; i1 < N; i1++)
    {
        for (int j1 = 0; j1 < N; j1++)
        {
            temp1.push_back(Mat[i1][j1]);
        }
    }
    
    std::sort(temp1.begin(),temp1.end());
    vector<vector<int>> arr(N,vector<int>(N));

    for (int i1 = 0; i1 < N; i1++)
    {
        for (int j1 = 0; j1 < N; j1++)
        {
            // temp1.push_back(Mat[i1][j1]);
            arr[i1][j1] = temp1[i1*N+j1];


        }
    }
    return arr;

}








