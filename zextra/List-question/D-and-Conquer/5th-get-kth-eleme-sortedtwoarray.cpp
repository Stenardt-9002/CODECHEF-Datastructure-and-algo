#include <iostream>
using namespace std;




void printarra(int* arr1,int *end1)
{
    cout<<endl;
    for (int i1 = 0; i1 <end1-arr1 ; i1++)
    {
        cout<<arr1[i1]<<" ";
    }
    
}



int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{

    cout<<"OK\n";
    printarra(arr1,end1);
    printarra(arr2,end2);
    cout<<"OK2\n";

	if (arr1 == end1)
		return arr2[k];
	if (arr2 == end2)
		return arr1[k];
	int mid1 = (end1 - arr1) / 2;
	int mid2 = (end2 - arr2) / 2;
	if (mid1 + mid2 < k)
	{
		if (arr1[mid1] > arr2[mid2])
        {
            cout<<"PP1";
			return kth(arr1, arr2 + mid2 + 1, end1, end2,
				k - mid2 - 1);
        }
		else
        {   
            cout<<"PP2";
			return kth(arr1 + mid1 + 1, arr2, end1, end2,
				k - mid1 - 1);
        }
	}
	else
	{
		if (arr1[mid1] > arr2[mid2])
			{
                cout<<"PP3";
                return kth(arr1, arr2, arr1 + mid1, end2, k);
            }
		else
			{
                cout<<"PP4";
                return kth(arr1, arr2, end1, arr2 + mid2, k);}
	}
}

int main()
{
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int k = 5;
	cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
    // printarra(arr1,arr1+5);
	return 0;
}
