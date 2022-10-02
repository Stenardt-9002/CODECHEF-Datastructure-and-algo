// Program to find k-th element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
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
                cout<<"DEBUG1 arr1 "<<arr1[0]<<" "<<"arr2 "<<arr2[0]<<" "<<end1[-1]<<" "<<end2[-1]<<" "<<k<<endl;
                return kth(arr1, arr2 + mid2 + 1, end1, end2,k - mid2 - 1);
            }
		else
			{
                cout<<"DEBUG2 arr1 "<<arr1[0]<<" "<<"arr2 "<<arr2[0]<<" "<<end1[-1]<<" "<<end2[-1]<<" "<<k<<endl;
                return kth(arr1 + mid1 + 1, arr2, end1, end2,k - mid1 - 1);
            }
	}
	else
	{
		if (arr1[mid1] > arr2[mid2])
			{
                cout<<"DEBUG3 arr1 "<<arr1[0]<<" "<<"arr2 "<<arr2[0]<<" "<<end1[-1]<<" "<<end2[-1]<<" "<<k<<endl;
                return kth(arr1, arr2, arr1 + mid1, end2, k);
            }
		else
			{
                cout<<"DEBUG4 arr1 "<<arr1[0]<<" "<<"arr2 "<<arr2[0]<<" "<<end1[-1]<<" "<<end2[-1]<<" "<<k<<endl;
                return kth(arr1, arr2, end1, arr2 + mid2, k);
            }
	}
}

// int main()
// {
// 	int arr1[5] = {2, 3, 6, 7, 9};
// 	int arr2[4] = {1, 4, 8, 10};

// 	int k = 5;
// 	cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
// 	return 0;
// }

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);


    int n , m ;
    cin>>n>>m ;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int k ; cin>>k ;
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1]    ;

    for (int i1 = 0; i1 < m; i1++)
        cin>>arr2[i1]    ;
    
    // for (int i1 = 1; i1 < n+m; i1++)
    // cout<<endl<<kthElement( arr1, arr2 , n, m, i1);
        
    
	cout << kth(arr1, arr2, arr1 + n, arr2 + m, k - 1);

    // cout<<endl<<kthElement( arr1, arr2 , n, m, k);

    return 0;
}

