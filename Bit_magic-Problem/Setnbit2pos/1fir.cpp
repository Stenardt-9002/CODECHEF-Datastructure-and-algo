


#include<iostream>

using namespace std;



int main(int argc, char const *argv[])
{

    int x,p1,n ,p2; 

    cin>>x;
    cin>>p1;
    cin>>n;
    cin>>p2;

    // unsigned int set1 = (x>>p1)&((1U<<n)-1);
    unsigned int set1 = (x>>p1)&((1U<<n)-1); //get number of stuff to be swapped
    
    unsigned int set2 = (x>>p2)&((1U<<n)-1); //get number of stuff to be swapped


    cout<<"set1 "<<set1<<" set2 "<<set2<<endl;

    unsigned int xor1 = set1^set2 ;
    cout<<" xor "<<xor1;

    xor1 = (xor1<<p1)|(xor1<<p2);
    cout<<" xor "<<xor1;

    unsigned int result = x^xor1 ; 

    cout<<result ;


    return 0;
}







