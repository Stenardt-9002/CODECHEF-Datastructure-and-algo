#include<iostream>
#include<vector>

using namespace std;





void setZeroes(vector<vector<int>>& matrix) 
{
            int n1 = matrix.size();
        int m1 = matrix[0].size() ;
        vector<int> row1(matrix.size())    ;
        vector<int> col1(matrix[0].size());
        
        
        int i1,j1 ;
        for(i1=0;i1<n1;i1++)
        {
            row1[i1] = -1;
        }
        for(i1=0;i1<m1;i1++)
        {
            col1[i1] = -1;
        }
        
        
        for(i1=0;i1<n1;i1++)
        {
            for(j1=0;j1<m1;j1++)
            {
                if(matrix[i1][j1]==0)
                {
                    row1[i1] = 2; col1[j1] = 2;
                }
            }
        }
        
        
        
        for(i1=0;i1<n1;i1++)
        {
            if(row1[i1]==2)
            for(j1=0;j1<m1;j1++)
            {
                matrix[i1][j1] = 0;
                
            }
        }
        
        
        for(j1=0;j1<m1;j1++)
        {
            if(col1[j1]==2)
            for(i1=0;i1<n1;i1++)
            {
                matrix[i1][j1] = 0;
                
            }
        }
        
    
}




int main(int argc, char const *argv[])
{
    
    return 0;
}





