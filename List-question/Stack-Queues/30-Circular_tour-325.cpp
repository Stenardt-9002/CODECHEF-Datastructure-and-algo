#include <bits/stdc++.h>
using namespace std;


struct petrolPump
{
    int petrol;
    int distance;
};

    int tour(petrolPump p[],int n)
    {
       //Your code here       
       int count = 0,i=0;
       int sum1 = 0;
       while(count!=n)
       {
            if(sum1+p[i%n].petrol-p[i%n].distance<0)
            {
                    count = 0;//reset 
                    sum1 = 0;
            }
            else
            {
                sum1 += (p[i%n].petrol-p[i%n].distance) ;
                count++ ;
            }
            i++ ;
            if(i>=2*n) //all starting points have been seen once
                return -1;
       }
       return i-count ;
    }