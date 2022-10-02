#include<iostream>
using namespace std;


bool find_next(int m1atr_ix[9][9], int& rowx, int& coly) 
{ 
	for (rowx = 0; rowx < 9; rowx++) 
		for (coly = 0; coly < 9; coly++) 
			if (m1atr_ix[rowx][coly] == 0) 
            {
				return true; 
            }
	return false; 
} 
bool checkrow(int m1atr_ix[9][9], int row, int i1val) 
{ 
	for (int col = 0; col < 9; col++) 
		if (m1atr_ix[row][col] == i1val) 
            {	return true; }
	return false; 
} 


bool checkcol(int m1atr_ix[9][9], int col, int i1val) 
{ 
	for (int row = 0; row < 9; row++) 
		if (m1atr_ix[row][col] == i1val) 
            {	return true; }

	return false; 
} 


bool checkalong3x3(int m1atr_ix[9][9], int rowsidx,	int rowscol, int i1val) 
{ 
	for (int row = rowsidx; row < rowsidx+3; row++) 
		for (int col = rowscol; col < rowscol+3; col++) 
			if (m1atr_ix[row ][col]	== i1val) 
				{
                    return true; 
                }
	return false; 
} 


bool isSafe(int m1atr_ix[9][9], int row, int col, int i1val) 
{ 

	return !checkrow(m1atr_ix, row, i1val) && !checkcol(m1atr_ix, col, i1val) && !checkalong3x3(m1atr_ix, row - row % 3, col - col % 3, i1val) && m1atr_ix[row][col] == 0; 
} 



bool solve_sudoku_fuc(int m1atr_ix[9][9]) 
{ 
	int row, col; 

	if (!find_next(m1atr_ix, row, col)) 
    {
		return true; 
    }

	for (int i1val = 0; i1val < 9; i1val++) 
    {

		if (isSafe(m1atr_ix, row, col, i1val+1)) { 
			m1atr_ix[row][col] = i1val+1; 

			if (solve_sudoku_fuc(m1atr_ix)) 
				return true; 

			m1atr_ix[row][col] = 0; 
		} 
	} 
	return false; 
} 








int main() 
{ 


     int testcase;

    cin>>testcase;
    // int sudoku_block;
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

      if (solve_sudoku_fuc(arr1) )
      {
          
        

        for (int i1 = 0; i1 < 9; i1++)
        {
            cout<<endl;
            for (int j1 = 0; j1 < 9; j1++)
            {
                cout<<arr1[i1][j1]<<" ";
            }
            
        }
      
      }

       else
       {
           cout<<"\nFailed Algo";
       }
       

    }



	return 0; 
} 


