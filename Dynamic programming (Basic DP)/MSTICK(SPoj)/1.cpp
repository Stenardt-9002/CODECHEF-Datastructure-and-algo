#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
using namespace std;
typedef signed long long int lld;

class Datatpye1
{

public:
  int length,weight;

};

bool cmpre(Datatpye1 d1, Datatpye1 d2)
{
  if (d1.length>d2.length)
  {
    return true;
  }
  return false;
}


int main(int argc, char const *argv[])
{
  lld testcase1,countofstikcs,nestedcount = 0,max1;
std::cin >> testcase1;
while (testcase1--)
{
 std::cin >> countofstikcs;
 // lld arr1[20001][2] =  {0};
 Datatpye1 arr1[countofstikcs];
 lld dpval[countofstikcs];
 for (lld i = 0; i < countofstikcs; i++)
 {
   // std::cin >> arr1[i/2][i%2];
   std::cin >> arr1[i].length;
   std::cin >> arr1[i].weight;
 }
 sort(arr1,arr1+countofstikcs,cmpre);

 // for (lld i = 0; i < countofstikcs; i++)
 // {
 //   std::cout << arr1[i].length <<" ,";
 //   std::cout << arr1[i].weight<<"\n";
 // }

 memset(dpval,0,sizeof(dpval));
  for (lld i = countofstikcs-1; i >=1; i--)
  {
    //already sorted on basis of heght
    // val1 = dpval[i];

    for (lld j = i-1; j >=0; j--)
    {
      if (arr1[j].weight>=arr1[i].weight)
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
    // for (lld k = 0; k <countofstikcs; k++)
    // {
    //   std::cout << dpval[k] << ' ';
    // }
    // std::cout << "Enter" ;cin>>val1;

  }

  // std::cout << "\n";
  //
  // for (lld k = 0; k <countofstikcs; k++)
  // {
  //   std::cout << dpval[k] << ' ';
  // }



  int flag = 1;
  nestedcount = 0;

  //max val dpval[max1]
  while(1)
  {
    max1 =  0;//index

    for (lld j = 0; j < countofstikcs; j++)
    {
      if ((dpval[j]>dpval[max1])&&(dpval[j]!=-1))
      {
        max1 = j;//get index
      }

    }
    stack <int> rordindes;
    lld previousindex = max1;
    rordindes.push(previousindex);

    for (lld j = max1; j < countofstikcs; j++)
    {

      if (dpval[rordindes.top()]-dpval[j]==1)
      {
        rordindes.push(j);

      }

      // if (dpval[previousindex]-dpval[j]==1)
      // {
      //
      //   previousindex = j;
      // }

    }

  //make all -1 and increment count by 1

    while (!rordindes.empty())
    {
      dpval[rordindes.top()] = -1;
      rordindes.pop();

    }
    nestedcount++;


    flag = 1;
//break condition when every dpval element is -1

    for (lld i = 0; i < countofstikcs; i++)
    {
      if (dpval[i] !=-1)
      {
        flag = 123;
        break;
      }


    }

    if (flag!=123)
    {
      break;

    }

  }

  std::cout << nestedcount << '\n';










}

return 0;
}
