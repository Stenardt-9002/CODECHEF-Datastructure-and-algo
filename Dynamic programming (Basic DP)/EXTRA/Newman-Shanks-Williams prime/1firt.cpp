




//newman shanks Williams prime 




#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    
    int n ;
    cin>>n;
    cout<<n<<endl;
    int *dp1 = new int[n+1];
    dp1[0] = dp1[1] = 1;
    for (int i1 = 0; i1 <= n-2; i1++)
    {
        dp1[2+i1] = 2*dp1[i1+1]+dp1[i1];
        
    }
    
cout<<endl;

    for (int i1 = 0; i1 <= n; i1++)
    {
       cout<< dp1[i1]<<" ";
        
    }



    delete [] dp1;




    return 0;
}

















