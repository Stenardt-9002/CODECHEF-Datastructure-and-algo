// #using dfs metohdology



#include<iostream>
#include<vector>
#include<cstring>





using namespace std; 









void findIslands(vector <int> Aray[])
{

    vector<int>temp1(2);
    temp1[0] = 616;
    temp1[1] = 452;
    Aray[1] = temp1;


}


int main(int argc, char const *argv[])
{
    
long long int rows,cols;
    int testcases;

    vector<int>Aray[10];
    vector<int>temp1(2);
    temp1[0] = 23;
    temp1[1] = 42;
    Aray[0] = temp1;

    for (int i1 = 0; i1 < 1; i1++)
    {
        for (int k1 = 0; k1 < 2; k1++)
        {
            cout<<Aray[i1][k1]<<" ";
        }
        cout<<endl;
    }
    findIslands(Aray);


    for (int i1 = 0; i1 < 2; i1++)
    {
        for (int k1 = 0; k1 < 2; k1++)
        {
            cout<<Aray[i1][k1]<<" ";
        }
        cout<<endl;
    }



    return 0;
}






















