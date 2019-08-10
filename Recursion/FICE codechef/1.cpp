#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    long int t,m,n;
    double phi;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        phi = (1 + sqrt(5)) / 2;
        n =  round(pow(phi, n) / sqrt(5));
        // n = n*(n-1)/2;
        n = 2*n;
        n =n%m;
        cout<<n;
    }
    

    return 0;
}
