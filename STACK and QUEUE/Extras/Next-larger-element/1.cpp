#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int testcaes ,n;
    cin>>testcaes;

    while (testcaes--)
    {
        cin>>n;
        int max1 = -1;
        int *arr1 = new int[n];
        int *arr2 = new int[n];

        for (int i1 = 0; i1 < n; i1++)
        {
            cin>>arr1[i1];
            if (max1<arr1[i1])
            {
                max1 = arr1[i1] ;

            }
            arr2[i1] = max1;
            if (max1 == arr1[i1])
            {
                arr2[i1]  = -1;
            }
            
            
        }
        cout<<endl;

        for (int i1 = 0; i1 < n; i1++)
        {
            cout<<arr2[i1]<<" ";            
        }
        

        delete [] arr1;
        delete [] arr2;


    }
    



    return 0;
}




