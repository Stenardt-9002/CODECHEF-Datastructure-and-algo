// https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int t , rows ,cols;
  std::cin >> t;
  while (t--)
  {
    std::cin >> rows>>cols;
    int **ar1 = new int*[rows];
    int **dpar1 = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
      ar1[i] = new int[cols];
      dpar1[i] = new int[cols];

    for (int j = 0; j < cols; j++)
      {
        cin>>ar1[i][j];

        if (ar1[i][j]>0)
        {
          dpar1[i][j] = 1;
        }
        else
        {
          dpar1[i][j] = -ar1[i][j]+1;
        }

      }



    }
// std::cout << "\n" << '\n';

    // for (int i = 0; i < rows; i++)
    // {
    // for (int j = 0; j < cols; j++)
    //   {
    //     cout<<ar1[i][j]<<" " ;
    //
    //   }
    //   std::cout << '\n';
    // }

    for (int i = rows-2; i >= 0; i--  )
    {
      dpar1[i][cols-1] = 1;
      if (dpar1[i][cols-1]<dpar1[i+1][cols-1]-ar1[i][cols-1])
      {
        dpar1[i][cols-1] = dpar1[i+1][cols-1]-ar1[i][cols-1];

      }
    }

    for (int k = cols-2; k >= 0; k--  )
    {
      dpar1[rows-1][k] = 1;
      if (dpar1[rows-1][k]<dpar1[rows-1][k+1]-ar1[rows-1][k])
      {
        dpar1[rows-1][k] = dpar1[rows-1][k+1]-ar1[rows-1][k];
      }
    }

    int recordpoints;

    for (int i=rows-2; i>=0; i--)
   {
       for (int j=cols-2; j>=0; j--)
       {
           recordpoints = dpar1[i+1][j];
          if (dpar1[i][j+1]<recordpoints)
          {
            recordpoints = dpar1[i][j+1];

          }

           dpar1[i][j] = 1;
          if (dpar1[i][j]<(recordpoints - ar1[i][j]))
          {
             dpar1[i][j] = recordpoints - ar1[i][j];

          }

       }
    }


    std::cout << dpar1[0][0]<<endl;


  }



  return 0;
}
