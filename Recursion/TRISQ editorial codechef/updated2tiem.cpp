//bitchass recursion
#include <bits/stdc++.h>
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
    b = b-2;
    
    while(b>1)
    {
        count+=1;b = b-2;
    }
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
   
   time_t start, end; 
  
    /* You can call it like this : start = time(NULL); 
     in both the way start contain total time in seconds  
     since the Epoch. */
    time(&start); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false); 
  
    
  
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



    // Recording end time. 
    time(&end); 
  
    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 




    return 0;
}
