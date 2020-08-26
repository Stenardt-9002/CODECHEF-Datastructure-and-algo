// #include <bits/stdc++.h> 
#include<iostream>
#include<vector>
#include<cstring>




using namespace std; 







int allowed(vector <int> matrix[], int i1, int j1,bool **visited,int ROW ,int COL)  
{ 
	return (i1 >= 0) && (i1 < ROW) && (j1 >= 0) && (j1 < COL) && (matrix[i1][j1] && !visited[i1][j1]); 
} 






void util_dfs_IL(vector <int> M[], int row, int col, 
		bool **visited,int ROW ,int COL) 
{ 
	int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

	visited[row][col] = true; 

	for (int k = 0; k < 8; ++k) 
    {

		if (allowed(M, row + xdir[k], col + ydir[k], visited,ROW,COL)) 
        {
			util_dfs_IL(M, row + xdir[k], col + ydir[k], visited,ROW,COL); 
        }
    }
} 
int countIslands(vector <int> matrix[],int ROW,int COL)
{ 
	bool **visited = new bool*[ROW]; 

    for (int i1 = 0; i1 < ROW; i1++)
    {
        visited[i1] = new bool[COL];
        for (int j1 = 0; j1 < COL; j1++)
        {
            visited[i1][j1] = 0;
        }
        
    }
    
	int answer1 = 0; 
	for (int i = 0; i < ROW; ++i) 
    {
		for (int j = 0; j < COL; ++j) 
        {
			if (matrix[i][j] && !visited[i][j]) { 
				util_dfs_IL(matrix, i, j, visited,ROW,COL); 

				answer1++; 
			} 
        }

    }   

    for (int i1 = 0; i1 < ROW; i1++)
    {
        delete[] visited[i1];       
    }
    delete[] visited;


	return answer1; 
} 

int main() 
{ 




    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int ROW,COL;
        cin>>ROW>>COL;
        vector<int> Arr1[ROW];
        
        for (int i1 = 0; i1 < ROW; i1++)
        {
            vector<int> te1mp(COL);
            Arr1[i1] = te1mp;
            for (int j1 = 0; j1 < COL; j1++)
            {
                cin>>Arr1[i1][j1];
            }
            
        }      
    cout<<countIslands(Arr1,ROW,COL)<<endl;

    }

	return 0; 
} 

