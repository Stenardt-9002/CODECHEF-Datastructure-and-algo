// #using dfs metohdology



#include<iostream>
#include<vector>
#include<cstring>





using namespace std; 



int isallowed(vector<int>Aray[],int rows,int cols,vector<bool>vsited[],int ROWS,int COLS)
{
    // rows>=0
    // rows<ROWS 
    // cols>=0
    // cols<COLS
    // vsited[rows][cols]==false
    // Aray[rows][cols]==1 some node of island 

    return (rows>=0 && cols<COLS && rows<ROWS && cols>=0 && (vsited[rows][cols]==false) && (Aray[rows][cols]==1)  );


}







// void DFSutil(vector <int>Aray[],int rows,int cols,bool **vsited)
// void DFSutil(vector <int>Aray[],int rows,int cols,vector <bool>vsited[])
void DFSutil(vector <int>Aray[],int rows,int cols,vector <bool>vsited[],int ROWS,int COLS)
{

    static int rowX[] = {-1,0,1,-1,0,1,-1,0,1};
    static int rowY[] = {-1,-1,-1,0,0,0,1,1,1};

    vsited[rows][cols] = true; //now is visteds find connected parts

    for (int i1 = 0; i1 < 8; i1++)
    {
        if (isallowed(Aray,rows+rowX[i1],cols+rowY[i1],vsited,ROWS,COLS ) )
        {
            DFSutil(Aray,rows+rowX[i1],cols+rowY[i1],vsited,ROWS,COLS);
        }
        

    }



}










int findIslands(vector <int> Aray[],int rows,int cols)
{

    // bool vsited[rows][cols];
    vector<bool>vsited[rows];
    for (long long int iv = 0; iv < rows; iv++)
    {
        vector<bool>twemp1(cols);
        vsited[iv] = twemp1;
        for (long long int jv = 0; jv < cols; jv++)
        {
            vsited[iv][jv] = false;
        }
        
    }


    long long int countisla= 0;
    for (long long int iv = 0; iv < rows; iv++)
    {
        for (long long int jv = 0; jv < cols; jv++)
        {
            if (Aray[iv][jv]==1 and vsited[iv][jv]==false     )
            {
                DFSutil(Aray,iv,jv,vsited,rows,cols);

                countisla++;

            }
        }
    }

    return countisla;


}


int main(int argc, char const *argv[])
{
    
long long int rows,cols;
    int testcases;
    while (testcases-->0)
    {
        cin>>rows>>cols     ;   

        vector<int> inp_ut1[rows];

        for (long long int ivar = 0; ivar < rows; ivar++)
        {
            vector <int>temp1(cols);

            inp_ut1[ivar] = temp1;
            for (long long int jvar = 0; jvar < cols; jvar++)
            {
                cin>>inp_ut1[ivar][jvar];
            }
            
        }

        
        cout<< findIslands(inp_ut1,rows,cols);




    }



    return 0;
}






















