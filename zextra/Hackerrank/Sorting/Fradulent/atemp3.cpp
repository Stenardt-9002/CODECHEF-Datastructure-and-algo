
#include<iostream>
#include<vector>

#include<map>
#include<set>
#include<algorithm>

#define MAXV 210

using namespace std;

int A1[200100];
int F[MAXV];


int median2(int d1)
{
    int p =0 ;
    for (int i1 = 0; i1 < MAXV; i1++)
    {
        p+=F[i1] ; 
        if (p*2>d1)
        {
            return 2*i1 ;
        }
        else if(p*2 == d1)
        {
            for (int j1 = i1+1 ;; j1++)
            {
                if (F[j1])
                {
                    return i1+j1;
                }
                
            }
            
        }        



    }
    return -1;



}







int main(int argc, char const *argv[])
{

    int n1 ,d1 ;
    cin>>n1>>d1;
    for (int i1 = 0; i1 < n1; i1++)
    {
        cin>>A1[i1];
    }
    






    int cunt1 = 0;
    for (int i1 = 0; i1 < n1; i1++)
    {
        if (i1>=d1)
        {
            if (A1[i1]>=median2(d1))
            {
                cunt1++;
            }
            F[A1[i1-d1]]-- ; 
        }
        F[A1[i1]]++;
        
    }
    cout<<cunt1;
    

    return 0;
}








