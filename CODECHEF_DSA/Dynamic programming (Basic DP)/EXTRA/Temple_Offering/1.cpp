// # dp solution psoible ?


#include<iostream>
using namespace std;



int max1(int x , int y)
{
    if (x>y)
    {
        return x;
    }
    return y;
    
}


int main(int argc, char const *argv[])
{

int testcaes ,n,tempeloffering = 0;
    cin>>testcaes;
    int *arr1;
    while (testcaes--)
    {
       cin>>n;
       tempeloffering = 0;
       arr1 = new int[n];
       for (int i=0;i<n;i++)
       {
           cin>>arr1[i];
       }
        for (int i1 = 0; i1 < n; i1++)
        {
            int left = 0,counter = i1 ;
            int right = 0;
            while (--counter>=0 )
            {
                if (arr1[counter]<arr1[counter+1])
                {
                    left++;
                }
                else
                {
                    break;
                }
            }
            counter = i1;
            while (++counter<n )
            {
                if (arr1[counter]<arr1[counter-1])
                {
                    right++;
                }
                else
                {
                    break;
                }
            }

        tempeloffering+=std::max(right,left);
        tempeloffering+=1;
        
        }
        



        cout<<tempeloffering<<endl;
        delete []arr1;
    }
    
    return 0;
}



