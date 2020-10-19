#include<iostream>
#include<math.h>



using namespace std;


int main(int argc, char const *argv[])
{
    int testcases ;
    cin>>testcases;

    int n,k,temp1,asnwer1;
    while (testcases--)
    {
        cin>>n>>k;
        // k = pow(2,k-1);
        temp1 = 1<<(k);
        temp1 = n&temp1;

        
        if (k==0 || temp1==0)
        {
            // cout<<temp1<<endl;
            // cout<<temp1;
            cout<<"No\n";

        }
        else
        {
            cout<<"Yes\n";
        }
        
        



        // int x1 = n&temp1;
        // cout<<x1<<endl;
        // if (x1==k)
        // {
        //     cout<<"YES\n";
            
        // }
        // else
        // {
        // }
        
        



    }
    

    return 0;
}


























