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
  // int *arr1;
  // int arraysiez ;
  // Datatpye1 (int sizeof_array)
  // {
  //    arraysiez= sizeof_array ;
  //    arr1 = new int[arraysiez][2];
  // }

// private:
  /* data */

// public:
  // Datatpye1 (arguments);
//   virtual ~Datatpye1 ();
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
    // Datatpye1 t1(countodfolls);
    // lld **arr1 = new lld*[countodfolls+1];
    //
    // for (size_t i = 0; i < 2*countodfolls; i++)
    // {
    //   arr1[i] = new lld[2];
    //   cin>>arr1[i/2][i%2];//[][0] represents x axis
    // }
    //
    // for (size_t i = 1; i <= 2*countodfolls; i++)
    // {
    //   cout<<arr1[i/2][i%2]<<" ";//[][0] represents x axis
    // }
    // std::cout << "\n" << '\n';
    //
    for (lld i = 0; i < countodfolls; i++)
    {
      // std::cin >> arr1[i/2][i%2];
      std::cin >> arr1[i].height;
      std::cin >> arr1[i].width;
    }
    std::cout << "\n" << '\n';
    // for (lld i = 0; i < countodfolls; i++)
    // {
    //   std::cout << arr1[i][i%2]<<" ";
    // }

    for (lld i = 0; i < countodfolls; i++)
    {
      // std::cout << arr1[i][i%2]<<" ";
      std::cout << arr1[i].height<<",";
      std::cout << arr1[i].width<<" ";
    }
    std::cout << "\n" << '\n';
    
    sort(arr1,arr1+countodfolls,cmpre);

    for (lld i = 0; i < countodfolls; i++)
    {
      // std::cout << arr1[i][i%2]<<" ";
      std::cout << arr1[i].height<<",";
      std::cout << arr1[i].width<<" ";
    }

    std::cout << "\n" << '\n';


  }

  // cin>>a;
  // cout<<a;
  return 0;
}
