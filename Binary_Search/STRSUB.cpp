#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lld;

int main(int argc, char const *argv[])
{
  lld testcases;
  std::cin >> testcases;

  string str_1;
  int *arr1;
  lld n1,k1,q1,temep1,tem1p2;

  while (testcases--)
  {
    cin>>n1>>k1>>q1;
    cin>>str_1;
    while(q1--)
    {
      cin>>temep1>>tem1p2;
      g1.push_back(temep1,tem1p2);

    }

    std::cout << "\nTEST" << '\n';
    for (auto i = g1.begin(); i != g1.end(); ++i)
        {cout << *i << " "; }


  }



  return 0;
}
