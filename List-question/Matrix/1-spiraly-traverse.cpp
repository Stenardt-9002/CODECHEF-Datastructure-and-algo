#include<iostream>
#include<vector> 

using namespace std;
  vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> asnwer ;
        asnwer.assign(r*c,0);
        int i1 = 0 ,starti = 0,startj = 0;
        while (i1<(r*c))
        {
            //fist quadrant 
            for (int x1 = startj; x1 <c-startj ; x1++)
            {
                // asnwer.push_back(matrix[starti][x1]);
                asnwer[i1] = matrix[starti][x1];
                i1++;
            }
            //second quad
            if (i1>=(r*c))
            {
                break;
            }
            

            starti++;
            for (int x1 = starti; x1 <=r-starti ; x1++)
            {
                // asnwer.push_back(matrix[x1][c-startj-1] );
                asnwer[i1] = matrix[x1][c-startj-1];
                i1++;
            }

              if (i1>=(r*c))
            {
                break;
            }
            
            startj++;
            for (int x1 = c-startj-1; x1 >=startj-1 ; x1--)
            {
                // asnwer.push_back(matrix[r-starti][x1] );
                asnwer[i1] = matrix[r-starti][x1];

                i1++;
            }
              if (i1>=(r*c))
            {
                break;
            }
            

            for (int x1 = r-starti-1; x1 >=starti ; x1--)
            {
                // asnwer.push_back(matrix[x1][startj-1] );
                asnwer[i1] = matrix[x1][startj-1] ;
                i1++;
            }
              if (i1>=(r*c))
            {
                break;
            }
            
            

        }
        
        return asnwer;

    }

int main(int argc, char const *argv[])
{
    int r,c ;
    cin>>r>>c ;

    vector<vector<int>> ma1trix(r) ;

    for (int i1 = 0; i1 < r; i1++)
    {

        // vector<int> temp1(c);

        // for (int j1 = 0; j1 < c; j1++)
        // {
        //     cin>>temp1[j1];
        // }
        // ma1trix[i1] = temp1;

        ma1trix[i1].assign(c,0) ;

        for (int j1 = 0; j1 < c; j1++)
        {
            cin>>ma1trix[i1][j1];
        }
        



    }


    // cout<<endl ; 
    // for (int i1 = 0; i1 < r; i1++)
    // {
    //     for (int j1 = 0; j1 < c; j1++)
    //     {
    //         cout<<ma1trix[i1][j1]<<" ";
    //     }
    //     cout<<endl;
    // }
    



    vector<int> asnwer ;asnwer= spirallyTraverse(ma1trix,r,c);
    cout<<endl ; 
    for (int i1 = 0; i1 < r*c; i1++)
    {
        cout<<asnwer[i1]<<" ";
    }
    





    return 0;
}










