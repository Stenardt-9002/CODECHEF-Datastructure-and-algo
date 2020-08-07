// storemaxtack method 
#include<iostream>
#include<stack>

using namespace std;


int main(int argc, char const *argv[])
{


    int testcaes ,n;
    cin>>testcaes;

    while (testcaes--)
    {
        cin>>n;
        int *arr1 = new int[n];
        int *arr2 = new int[n];

        for (int i1 = 0; i1 < n; i1++)
        {
            cin>>arr1[i1];
        }
        stack<int> storemax;
        stack<int> storemax_idx;

        // int counter1 = 0;
        storemax.push(arr1[0]);
        storemax_idx.push(0);
        for (int i1 = 1; i1 < n; i1++)
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
        



        for (int io1 = 0; io1 < n; io1++)
        {
            cout<<arr2[io1]<<" ";
        }
        cout<<endl;
        





        delete [] arr1;
        delete [] arr2;


    }
    



    return 0;

}





