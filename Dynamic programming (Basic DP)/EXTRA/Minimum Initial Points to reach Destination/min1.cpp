#include <iostream>
using namespace std;

int mermax(int x ,int y)
{
  return x>y?x:y;
}



int mermin(int x ,int y)
{
    return x<y?x:y;
    
}


int main(int argc, char const *argv[])
{
    int testcaes;
    cin>>testcaes;

    while(testcaes--)
    {       
     int row,col;
        cin>>row>>col;
        int **points1;
        points1 = new int*[row];
        for (int i1j = 0; i1j < row;i1j++)
        {
            points1[i1j] = new int[col];
            for (int ik1 = 0; ik1 < col; ik1++)
            {
                //thjis stuff
                cin>>points1[i1j][ik1];
            }
       }
        //from src to destination
        int **dyna_table;
        dyna_table = new int*[row];
        for (int ik1 = 0; ik1 < row; ik1++)
        {
            dyna_table[ik1] = new int[col];
        }
    //find points on exit 
        if (points1[row-1][col-1]>0)
        {
            dyna_table[row-1][col-1] = 1;
        }
        else 
        {
            dyna_table[row-1][col-1] = -points1[row-1][col-1] + 1; //only mag to clear last m-1,n-1 threshold
        }
        
        for (int var1 = col-2; var1 >=0; var1--)
        {
            dyna_table[row-1][var1] = mermax(( dyna_table[row-1][var1+1]-points1[row-1][var1]),1) ;
        }
        
        for (int var1 = row-2; var1 >=0; var1--)
        {
            dyna_table[var1][col-1] = mermax(( dyna_table[var1+1][col-1]-points1[var1][col-1]),1) ;
        }


//last to top fill

        for (int i1 = row-2; i1 >=0 ; i1--)
        {
            for (int i1j = col-2; i1j >=0 ; i1j--)
            {
                int last_points = mermin(dyna_table[i1+1][i1j], dyna_table[i1][i1j+1]  );
                dyna_table[i1][i1j] = mermax(last_points-points1[i1][i1j],1) ;
            }


        }
        

        // dyna_table[row][col] = 
        
        cout<<dyna_table[0][0];






        for (int i1j = 0; i1j < row;i1j++)
        {
            // for (int ik1 = 0; ik1 < col; ik1++)
            // {
            //     //thjis stuff
            //     // cout<<points1[i1j][ik1]<<" ";
            //     cout<<dyna_table[i1j][ik1]<<" ";
            // }
            // cout<<"\n";
            delete [] points1[i1j];
            delete [] dyna_table[i1j];
        }
        

        delete [] points1;
            delete [] dyna_table;

        
        }

    // int dp[]
    return 0;
}




