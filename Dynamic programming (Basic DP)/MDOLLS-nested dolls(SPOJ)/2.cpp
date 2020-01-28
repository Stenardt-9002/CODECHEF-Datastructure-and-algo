#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef signed long long int lld;

class Datatpye1
{

public:
  int height,width;

};

bool cmpre(Datatpye1 d1, Datatpye1 d2)
{
  if (d1.height>d2.height)
  {
    return true;
  }
  return false;
}


int main(int argc, char const *argv[])
{

   lld testcase1,countodfolls;
  std::cin >> testcase1;
  while (testcase1--)
  {
    std::cin >> countodfolls;
    // lld arr1[20001][2] =  {0};
    Datatpye1 arr1[countodfolls];
    lld dpval[countodfolls];
    for (lld i = 0; i < countodfolls; i++)
    {
      // std::cin >> arr1[i/2][i%2];
      std::cin >> arr1[i].height;
      std::cin >> arr1[i].width;
    }
    sort(arr1,arr1+countodfolls,cmpre);

    lld val1 ;
    memset(dpval,0,sizeof(dpval));
    for (lld i = countodfolls-1; i >=1; i--)
    {
      //already sorted on basis of heght
      // val1 = dpval[i];

      for (lld j = i-1; j >=0; j--)
      {
        if (arr1[j].width>arr1[i].width)
        {
          if (dpval[j]<dpval[i]+1)
          {
            dpval[j] = dpval[i]+1;

            /* code */
          }

        }


      }
      // std::cout << "\n";
      //
      // for (lld k = 0; k <countodfolls; k++)
      // {
      //   std::cout << dpval[k] << ' ';
      // }
      // std::cout << "Enter" ;cin>>val1;

    }

    std::cout << "\n" << '\n';



    for (lld i = 0; i<countodfolls; i++)
    {
      std::cout << dpval[i] << ' ';
    }

  }

  return 0;
}
