#define VALUE1 1009


#include <iostream>
// #include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

  int n;
  int i,j;
  int t;
  int ans = 0;
  // std::cout << "REached" << '\n';

  // char arr1[VALUE1][VALUE1];
  int xmem[VALUE1][VALUE1] = {};
  int ymem[VALUE1][VALUE1] = {};
  // std::cout << "REached" << '\n';
  cin >> t;
  while (t--)
  {

    string arr1[VALUE1];


    cin >> n;

    //
    for ( i = 0; i < n; i++)
    {

        cin >> arr1[i];


    }


    // for ( i = 0; i < n; i++)
    // {
    //   for ( j = 0; j < n; j++)
    //   {
    //         cin >> arr1[i][j];
    //
    //   }
    //
    //
    // }


ans = 0;
// std::cout << "Forked" << '\n';
//clear xmem and ymem
// for ( i = 0; i < n; i++)
// {
//   for ( j = 0; j < n; j++)
//   {  cout << arr1[i][j];}
//
//
// }
// for (int a = 0; a < n; a++)
// {
//   for (int b = 0; b < n; b++)
//   {
//
//     std::cout << arr1[a][b];
//   }
//   std::cout << '\n';
// }



memset(xmem,-1,sizeof(xmem));
memset(ymem,-1,sizeof(ymem));
//ananlsysi

      // for ( i = (n-1); i >= 0; i--)
      // {
      // //start from end beacuse tis clear
      //   for (j = (n-1); j >= 0; j--)
      //   {
      //
      //     if (arr1[i][j]=='#')
      //       {
      //         continue;//shrtft
      //
      //       }
      //
      //       if (j==(n-1) && i==(n-1))
      //       {
      //         xmem[i][j] = 1;
      //         ymem[i][j] = 1;
      //       }
      //
      //       else if(j==(n-1))
      //       {
      //         // #path clear in x
      //         xmem[i][j] = 1;
      //         if(ymem[i+1][j]==1)
      //         {
      //             ymem[i][j]==1;
      //         }
      //
      //
      //       }
      //
      //       else if(i==(n-1))
      //       {
      //         // #path clear in y
      //         ymem[i][j] = 1;
      //         if(xmem[i][j+1]==1)
      //         {
      //             xmem[i][j]==1;
      //         }
      //
      //
      //       }
      //
      //
      //       else
      //       {
      //         if(xmem[i][j+1]==1)
      //         {
      //           xmem[i][j]==1;
      //         }
      //
      //         if(ymem[i+1][j]==1)
      //         {
      //             ymem[i][j]==1;
      //         }
      //
      //
      //       }
      //
      //   }
      // }

      for(i=n-1; i>=0; i--)
        {
          for(j=n-1; j>=0; j--)
          {
              if(arr1[i][j]=='#')
              continue;

              if(i==n-1 && j==n-1)
              {
                xmem[i][j]=1;
                ymem[i][j]=1;
              }
              else if(j==(n-1))
              {
                  xmem[i][j]=1;
                  if(ymem[i+1][j]==1)
                    ymem[i][j]=1;
              }
              else if(i==(n-1))
              {
                  ymem[i][j]=1;
                  if(xmem[i][j+1]==1)
                    xmem[i][j]=1;
              }
              else
              {
                  if(ymem[i+1][j]==1)ymem[i][j]=1;
                  if(xmem[i][j+1]==1)xmem[i][j]=1;
              }
          }
        }







  for ( i = 0; i < n; i++)
  {
    for ( j = 0; j < n; j++)
    {
      if (xmem[i][j]==1 && ymem[i][j]==1)
      {

        ans++;
      }

    }

  }

  cout << ans << '\n';

//   for (i = 0; i <= n-1; i++)
//   {
//     for (j = 0; j <= n-1; j++)
//     {
//       std::cout << xmem[i][j] ;
//     }
// std::cout << '\n';
//   }
//
//   std::cout << "Dp" << '\n';
//   for (i = 0; i <= n-1; i++)
//   {
//     for (j = 0; j <= n-1; j++)
//     {
//       std::cout << ymem[i][j] ;
//     }
// std::cout << '\n';
//   }


  }//end while

  return 0;
}
