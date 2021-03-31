
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int lld ;

int main(int argc, char const *argv[])
{
    lld n1 ,k1 ;
    lld array1[100010];
    lld array2[100010];
    lld sum1 = 0;
    cin>>n1>>k1 ;
    for (int i1 = 0; i1 < n1; i1++)
    {
       cin>> array1[i1];
    }
    sort(array1,array1+n1);
    for (int i1 = 0; i1 < n1; i1++)
    {

        sum1+=array1[i1];
        array2[i1] = sum1;
    }
    int count1 =-1;
    for (int i1 = 0; i1 < n1; i1++)
    {
        if (array2[i1]>k1 && count1<0)
        {
            count1 = i1;
            break ;
        }
        
    }
    
    cout<<count1 ;
    return 0;
}










