
#include<iostream>
using namespace std;



int max1(int x , int y)
{
    if (x>y)
    {
        return x;
    }
    return y;
    
}
struct daat1{
    int L,R,vale;
};


int main(int argc, char const *argv[])
{
    

int testcaes ,n,tempeloffering = 0;
    cin>>testcaes;
    // int *arr1;
    while (testcaes--)
    {
    struct daat1 *arr1;
       cin>>n;
       tempeloffering = 0;
       arr1 = new struct daat1[n];
    //    arr1 = new int[n];
       for (int i=0;i<n;i++)
       {
        //    cin>>arr1[i];
        cin>>arr1[i].vale;
        arr1[i].L = arr1[i].R = -1;
       }
    //    cout<<endl;
    //     for (int i1 = 0; i1 < n; i1++)
    //     {
    //         cout<<arr1[i1].vale<<" ";
        
    //     }

        arr1[0].L = 1;arr1[n-1].R = 1;

        //left dp 
        for (int i2 = 1; i2 < n; i2++)
        {
            if (arr1[i2].vale>arr1[i2-1].vale)
            {
                /* code */
                arr1[i2].L = arr1[i2-1].L+1;
            }
            else
            {
                arr1[i2].L = 1;
            }
            
        }


        for (int i2 = n-2; i2 >=0; i2--)
        {
            if (arr1[i2+1].vale<arr1[i2].vale)
            {
                /* code */
                arr1[i2].R = arr1[i2+1].R+1;
            }
            else
            {
                arr1[i2].R = 1;
            }
            
        }


        for (int i21 = 0; i21 < n; i21++)
        {
            tempeloffering+=std::max(arr1[i21].L,arr1[i21].R);
        }
        
        cout<<tempeloffering<<endl;


        delete [] arr1;
    }
    return 0;
}












