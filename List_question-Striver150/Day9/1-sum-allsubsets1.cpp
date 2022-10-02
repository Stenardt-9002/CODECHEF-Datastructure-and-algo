    
//     #include <bits/stdc++.h>
// using namespace std;
    
    
    
    
    
    
    
//     void recursive1(vector<int> arr1,int l , int r , int sum , vector<int> &answert1)
//     {
//         if(l>r){answert1.push_back(sum);}
        
//         recursive1(arr1,l,r,sum,answert1);
//         recursive1(arr1,l+1,r,sum+arr1[l],answert1);
        
//     }


//     vector<int> subsetSums(vector<int> arr, int N)
//     {
//         vector<int>answer1 ;
//         recursive1(arr,0,N-1,0,answer1);
         
//         return answer1;
        
//     }


// int main(int argc, char const *argv[])
// {
//     int n;cin>>n ;
//     vector<int> arr1;int ans1 ;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         cin>>ans1; 
//         arr1.push_back(ans1);
//     }
//     vector<int> ans2 = subsetSums(arr1,n);

//     for (auto i1 : ans2)
//     {
//         cout<<" "<<i1 ;
//     }
    

//     return 0;
// }



// C++ program to print sums of all possible
// subsets.
#include <bits/stdc++.h>
using namespace std;

void subsetSums(int arr[], int n)
{
    int totla = 1<<n;
    int sum1 ;
    vector<int> a1 ;
    for (int i1 = 0; i1 < totla; i1++)
    {
        sum1 = 0 ;
        for (int j1 = 0; j1 < n; j1++)
        {
            if (i1&&(1<<j1))
            {
                sum1+=arr[j1];
            }
        }
        a1.push_back(sum1)        ;

    }
    
}

void fuc1(int ind , int sum,vector<int> &arr1,int N,vector<int>&ans_set)
{
    if (ind==N)
    {
        ans_set.push_back(sum);
    }
    fuc1(ind+1,sum+arr1[ind],arr1,N,ans_set);
    fuc1(ind+1,sum,arr1,N,ans_set);//not taken

}



// Driver code
int main()
{
	int arr[] = { 5, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	subsetSums(arr, n);
	return 0;
}





