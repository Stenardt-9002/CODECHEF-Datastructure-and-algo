#include <iostream>


#define VALUE1 1009


using namespace std;

int main(int argc, char const *argv[])
{


  int i,j,k,n;
  int t;
  int ans = 0;

  char arr1[VALUE1][VALUE1];
  int xmem[VALUE1][VALUE1];
  int ymem[VALUE1][VALUE1];


  cin>>t;
  std::cout << "REached" << '\n';
  std::cout << t << '\n';

  while (t--)
  {
    std::cin >> n;;
    for ( i = 0; i < n; i++)
    {

      for ( j = 0; j < n; j++)
      {
        cin >> arr1[i][j];


      }
    }


  }



  std::cout << "REached" << '\n';
  std::cout << n << '\n';





  return 0;
}
