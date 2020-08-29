#include<iostream>
#include<algorithm>
using namespace std;

class Pair_Daat
{
    public:
    int a,b;
};


bool compare1(Pair_Daat a1,Pair_Daat b1)
{
    return a1.b<b1.b;
}



int main(int argc, char const *argv[])
{

    int n;
    cin>>n ;
    Pair_Daat *arr1 = new Pair_Daat[n];
    // int *dp1 = new int[n];
    int max1 = 1;
    int count1=0 ;
    while (count1<n)
    {
        cin>>arr1[count1].a>>arr1[count1].b;
        // dp1[count1] = 1;
        count1++;
    }
    sort(arr1,arr1+n,compare1);

    int begin = arr1[0].b;

    for (int i1 = 1; i1 < n; i1++)
    {
        if (arr1[i1].a>begin)
        {
            max1++;
            begin = arr1[i1].b;
        }
        
    }
    



    cout<<max1;
    
    
    delete [] arr1;
    
    return 0;
}














