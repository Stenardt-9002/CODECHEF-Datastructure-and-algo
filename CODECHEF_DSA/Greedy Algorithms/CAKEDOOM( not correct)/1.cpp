#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;




int conver_i(char c)
{
  int i = c - '0';
  return i;
}


char conver_s(int c)
{
  char i = c+48;
  return i;
}





int main(int argc, char const *argv[])
{

  int t,k,s;
  int i;
  int lenght = 0;
  int val ;
  string int1;
  cin>>t;
  bool correct = true ;
  while (t--)

  {
      cin>>k;
      cin>>int1;
      // getline(cin,int1);
      lenght = int1.size();
      correct = true;
      i=0;
      if (lenght==1)
      {
        int1[0]='0';
        lenght = 0;
        // std::cout << "Reached" << '\n';
      }
      while(i<lenght)
      {
          // cout<<int1[i]<<" ";
          if (int1[i]=='?')
          {
              //if not end
              if ((i!=0) && (i!=lenght-1))
              {
                int1[i] = '0';//greedy way
                val = 0;
                while (int1[i]==int1[i-1]|| int1[i+1]==int1[i])
                {
                  // int1[i]++;
                  val++;
                  int1[i] = conver_s(val);
                  if (conver_i(int1[i])==k)
                   {
                    correct = false;
                    break;
                  }
                }
              }






              // if end
              else if (i==0)
              {
                int1[i] = '0';//greedy way
                val = 0;

                while (int1[i]==int1[lenght-1]|| int1[i+1]==int1[i])
                {
                  // int1[i]++;
                  val++;
                  int1[i] = conver_s(val);
                  if (conver_i(int1[i])==k)
                   {
                    correct = false;
                    break;
                  }
                }
              }



            else if (i == lenght-1)
              {
                  int1[i] = '0';
                  val = 0;
                  while (int1[i]== int1[i-1] || int1[i]==int1[0])
                  {
                    val++;

                    int1[i] = conver_s(val);
                    if (conver_i(int1[i])==k)
                     {
                      correct = false;
                      break;
                     }

                  }


              }


          }


          if ((i!=0) && (i!=lenght-1))
          {
            if ((int1[i]==int1[i-1])||(int1[i+1]==int1[i]))
            {
              correct = false;
            }
          }

          else if (i==0)
          {
            if (int1[i]==int1[i+1] || int1[i]==int1[lenght-1])
            {
              correct = false;
            }
          }
          else
          {
            if (int1[i]==int1[0] || int1[i]==int1[i+1])
            {

              correct = false;
            }
          }





          if (correct==false)
          {
            break;
          }

          i++;



      }

      if(correct==true)
      {
      std::cout << endl <<int1<<'\n';

      }
      else
      {
        cout<<"NO"<<endl;
      }
  }

  return 0;
}
