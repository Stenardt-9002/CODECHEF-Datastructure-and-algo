
#include<iostream>
#include<algorithm>

using namespace std;

int func_gre(int n,int k ,int *arr1)
{
    sort(arr1,arr1+n);
    int count_1 = 0;
    int sum1 = 0,var1=0;
    while (sum1<arr1[var1])
    {
        sum1+=arr1[var1];
        var1++;
    }
    
    return var1+1;

}


    int toyCount(int n,int k ,int *arr1)
    {
        sort(arr1,arr1+n);
        int count_1 = 0;
        int sum1 = 0,var1=0;
        while (sum1<k)
        {
            sum1+=arr1[var1];
            var1++;
        }
    
        if(sum1==k)
        {
            return var1;
        }
    
        return var1-1;

    }






int main(int argc, char const *argv[])
{
    
    int testcaes ,n,k;
    cin>>testcaes;
    while (testcaes--)
    {
        cin>>n>>k;
        int *arr1;
        arr1 = new int[n];

        for (int i2 = 0; i2 < n; i2++)
        {
            cin>>arr1[i2];  
        }
        cout<<func_gre(n,k,arr1)<<endl;;




        delete []arr1;


    }
    





    return 0;
}










