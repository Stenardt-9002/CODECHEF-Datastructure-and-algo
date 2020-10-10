#include<iostream>
#include<stdio.h>

#include<climits>


using namespace std;


int main(int argc, char const *argv[])
{

    int testcaes;
    
    cin>>testcaes;
    while (testcaes--)
    {
        int Nm,difk,inm1=INT_MAX;
        int tem_p1,final_snwer = 0;
        int *pilesw;
        cin>>Nm>>difk;
        pilesw = new int[Nm];
        for (int i1 = 0; i1 < Nm; i1++)
        {
            cin>>pilesw[i1];
            if (inm1>pilesw[i1])
            {
                inm1 = pilesw[i1] ;
            }
            
        }

        //min will never bereduce
        for (int i1 = 0; i1 < Nm; i1++)
        {
            tem_p1 = pilesw[i1]-inm1;

            if (tem_p1>difk)
            {
                    final_snwer+=(tem_p1-difk);
            }
            

        }
        
        cout<<final_snwer;

        delete []pilesw;
    }
    






    return 0;
}




