#include<queue>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int M=2;
    vector <int> dist(M+1,-1);
    cout<<"\n Ditansce size  "<<dist.size();
    for (size_t i = 0; i < dist.size(); i++)
    {
        cout<<endl<<dist[i];
    }
    
    return 0;
}
