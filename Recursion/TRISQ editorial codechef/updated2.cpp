//bitchass recursion

#include<iostream>
using namespace std;
int record[10000] ;
// bool know[10000] = 
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

    if (record[val-2]==0 && val-2>3)
    {
            record[val-2] = cal_sqare(val-2);
   }
    return count+record[val-2];
    


}


int main(int argc, char const *argv[])
{
    int b,t,tsuma1;
    cin>>t;
    // cout<<record[3]<<endl;
    // cout<<record[7];
    for(int i =0;i<t;i++)
    {
        cin>>b;
        if (record[b]==0 && b>3)
        {
            tsuma1 = cal_sqare(b);
            record[b]=tsuma1;
        }
        else
        {
            tsuma1 = record[b];
        }
        
        cout<<tsuma1<<endl;
    }

    return 0;
}
