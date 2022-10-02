
#include <iostream>
// #include <stdio>
#include <vector>

using namespace std;
int max1(int a,int b)
{
  return (a>b)?a:b;
}


int eggDrop(int numegg,int numeroffloors)
{
  int answer1,minasnwer=9999;
  if (numeroffloors==1 || numeroffloors==0 )
  {
    return numeroffloors;//single floor only one trila
  }

  if (numegg==1)
  {
    return numeroffloors;//single egg start from grpound

  }

  //all floor

  for (int floorvar = 0; floorvar <numeroffloors; floorvar++)
  {
    answer1 = max1(eggDrop(numegg-1,floorvar),eggDrop(numegg,numeroffloors-floorvar-1));
    if (minasnwer>answer1)
    {
      minasnwer= answer1 ;
    }
  }



  return minasnwer+1;


}




int main(int argc, char const *argv[])
{
  int testcaes;
  int numofegg;
  int numerofloors;
  cin>>testcaes;
  while (testcaes>0)
  {
    testcaes--;
    std::cin >> numofegg>>numerofloors;

    int asnwer = eggDrop(numofegg,numerofloors);

    cout<<asnwer<<endl;

  }






  return 0;
}
