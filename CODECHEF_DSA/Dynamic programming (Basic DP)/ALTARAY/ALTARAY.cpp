// #include <iostream>
// typedef long long ll;
//
// using namespace std;
//
//
// int main(int argc, char const *argv[])
// {
//
//   int t,n;
//   std::cin >> t;
//   while (t--)
//   {
//     // std::cout << endl << '\n';
//     cin>>n;
//       ll arr1[n];
//       ll ans1[n];
//     for (size_t i = 0; i < n; i++)
//     {
//       std::cin >> arr1[i];
//     }
//
//     //process
//     //
//     // for(ll x:arr1)
//     // {
//     //   std::cout << x << " ";
//     // }
// // std::cout << endl << '\n';
//     int n1 = n;
//     ans1[--n1] = 1;
//     while (n1--)
//     {
//         if ((arr1[n1]*arr1[n1+1])<0)
//         {
//           ans1[n1] = 1+ans1[n1+1];
//         }
//         else
//         {
//           // std::cout << "Reached " ;
//           ans1[n1] = 1;
//         }
//
//     }
// // cout<<endl;
// for(ll x:ans1)
// {
//   std::cout << x << " ";
// }
//
//   }
//
//
//   return 0;
// }



#include <iostream>
typedef long long ll;

using namespace std;


int main(int argc, char const *argv[])
{

  int t,n;
  std::cin >> t;
  while (t--)
  {

    cin>>n;
      ll arr1[n];
      ll ans1[n];
    for (size_t i = 0; i < n; i++)
    {
      std::cin >> arr1[i];
    }

    //process
   cout<<endl;
    int n1 = n;
    ans1[--n1] = 1;
    while (n1--)
    {
        if ((arr1[n1]*arr1[n1+1])<0)
        {
          ans1[n1] = 1+ans1[n1+1];
        }
        else
        {

          ans1[n1] = 1;
        }

    }
for(ll x:ans1)
{
  std::cout << x<<' ' ;
}

  }


  return 0;
}
