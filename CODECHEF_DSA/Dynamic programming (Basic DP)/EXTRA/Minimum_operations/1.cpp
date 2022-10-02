#include<iostream>
#include<algorithm>
using namespace std; 




int main(int argc, char const *argv[])
{
    int testcaes ;
    cin>>testcaes;
        int n;

    while (testcaes--)
    {
        // int n;
        cin>>n;
        int count = 0;
        int a1 =n;
    while (a1!=0)
    {
        if (n%2==0)
        {
            a1 = n/2;
        }
        else
        {
            a1 = n-1;
        }
        n = a1;
        count++;
                
    }

        
        std::cout<<count;
    }
    



    return 0;
}

