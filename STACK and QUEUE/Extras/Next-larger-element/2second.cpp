
// storemaxtack method 
#include<iostream>
#include<stack>
typedef long long int lld;
using namespace std;

int main(int argc, char const *argv[])
{


    int testcaes ,n;
    cin>>testcaes;

    while (testcaes--)
    {
        cin>>n;
        lld *arr1 = new lld[n];
        lld *arr2 = new lld[n];

        for (lld i1 = 0; i1 < n; i1++)
        {
            cin>>arr1[i1];
        }
        stack<lld> storemax;
        stack<lld> storemax_idx;

        // lld counter1 = 0;
        storemax.push(arr1[0]);
        storemax_idx.push(0);
        for (lld i1 = 1; i1 < n; i1++)
        {
            //empty unitl stack has smaller element than encounterd element
            while (storemax.empty()==false && storemax.top()<arr1[i1])
            {
                /* code */
                // cout<<arr1[i1]<<" ";
                arr2[storemax_idx.top()] = arr1[i1];

                storemax.pop();
                storemax_idx.pop();
            }

            storemax.push(arr1[i1]);
            storemax_idx.push(i1);
            
        }


        //right hand side of elements

        while (storemax.empty()==false)
        {
            // cout<<-1<<" ";
            arr2[storemax_idx.top()] = -1;
            storemax_idx.pop();

            storemax.pop();
        }
        



        for (lld io1 = 0; io1 < n; io1++)
        {
            cout<<arr2[io1]<<" ";
        }
        cout<<endl;
        





        delete [] arr1;
        delete [] arr2;


    }
    



    return 0;

}





