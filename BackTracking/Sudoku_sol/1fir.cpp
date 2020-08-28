#include<iostream>
using namespace std;

bool find_next(int matr_ix[9][9],int &row_x1,int &row_y1)
{
    for (int r1 = 0; r1 < 9; r1++)
    {
        for (int c1 = 0; c1 < 9; c1++)
        {
            if (matr_ix[r1][c1]==0)
            {
                row_x1 = r1;row_y1 = c1;
                return true;
            }
            
        }
        
    }
    return false;
}
bool allowed(int matr_ix[9][9],int row_x1,int row_y1,int val)
{
     // row check
    for (int col = 0; col < 9; col++)
    {
        if (matr_ix[row_x1][col]==val+1 )
        {
            return false;
        }
    }

    for (int row = 0; row < 9; row++)
    {
        if (matr_ix[row][row_y1]==val+1 )
        {
            return false;
        }
    }
    
    // 3x3 value check
        


}

bool solve_Sudoku(int matr_ix1[9][9])
{
    int rowx,colx;

    //find next empty postion 
    
        if (!find_next(matr_ix1,rowx,colx))
        {
            return true;//all done
        }
        
        
    // if (rowx == -1) 
    // {
    //     return true;
    // }






    for (int i1 = 0; i1 < 9; i1++)
    {
        if (allowed(matr_ix1,rowx,colx,i1))
        {
            /* code */
        }
        
    }
    

}



int main(int argc, char const *argv[])
{
    int testcase;

    cin>>testcase;
    int sudoku_block;
    int arr1[9][9];

    while (testcase--)
    {
        for (int i1 = 0; i1 < 9; i1++)
        {
            for (int j1 = 0; j1 < 9; j1++)
            {
                cin>>arr1[i1][j1];
            }
            
        }
        
    }
    


    return 0;
}




