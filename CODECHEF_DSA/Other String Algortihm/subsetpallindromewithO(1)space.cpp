#include <iostream>
#include <string.h>
using namespace std;



int logestPalSubstr(string str)
{
  int maxLenghtofpallindromefoundyet = 1;
  int start = 0;
  int len1 = str.size();
  // int len1 = strlen(str);

  int low,high ;

  std::cout << len1 << '\n';
  for (int j = 1; j < len1; j++)
  {
// j is point from where pallindrome middle is reached
    low  =j-1;
    high = j;
    //even pallindromes
    while (str[low]==str[high]&&low>=0&&high<len1)
    {

      if (high-low+1>maxLenghtofpallindromefoundyet)
      {
          start = low;
          maxLenghtofpallindromefoundyet = high-low+1;

      }
      if (low==0)
      {
        break;
      }
      low--;high++;
    }









        low  =j-1;
        if (j!=len1-1)
        {
          high = j+1;
        }
        else
        {
          high = j;
        }
        // high = j+1;

    //odd pallindrome
    while (str[low]==str[high]&&low>=0&&high<len1)
    {

      if (high-low+1>maxLenghtofpallindromefoundyet)
      {
          start = low;
          maxLenghtofpallindromefoundyet = high-low+1;

      }
      if (low==0)
      {
        break;
      }
      low--;high++;
    }


      //start from middle keep on checking whgtetr you have pallindrom ekeep updating the length of longest pallindrome foiund yet and keep updating start variable

  }

return maxLenghtofpallindromefoundyet;


}




int main(int argc, char const *argv[])
{


  // char str[] = "skooks";

  string str;
  std::cin >> str;
  int x = logestPalSubstr(str);
  std::cout << x << '\n';


  return 0;
}
