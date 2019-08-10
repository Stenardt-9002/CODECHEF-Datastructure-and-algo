//bitchass recursion

#include<iostream>
using namespace std;
int cal_sqare(int b)
{
    int count = 0,val;
    if (b<4)
    {
        return 0 ;
    }
    val = b;
    // b = b-2;
    
    // while(b>1)
    // {
    //     count+=1;b = b-2;
    // }
    count = val/2 - 1;

    return count+cal_sqare(val-2);

}


int main(int argc, char const *argv[])
{
    int b,t,tsuma1;
    cin>>t;

    for(int i =0;i<t;i++)
    {
        cin>>b;
 
            tsuma1 = cal_sqare(b);
             
        cout<<tsuma1<<endl;
    }

    return 0;
}
