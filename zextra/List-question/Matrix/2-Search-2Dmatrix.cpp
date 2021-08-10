#include<iostream>
#include<vector> 

using namespace std;

//modified binary search to find the number or else tell the range between the number might exist
// used when you need to search first column 
// int binarysearch1(vector<int> arr1,int l1,int r1,int x1)
// {
//     if (r1>=l1)
//     {
//         int mid = l1+(r1-l1)/2 ;
//         if (arr1[mid]==x1)
//         {
//             return mid ;//found succesfully
//         }
//         else if (r1-l1==1||mid==l1)
//         {
//             return l1 ;// found first one 
//         }
//         if (arr1[mid]>x1)
//         {
//             return binarysearch1(arr1,l1,mid,x1 );
//         }
//             return binarysearch1(arr1,mid,r1,x1 );
//     }
    
//     return -1;


// }


int binarysearch1(vector<vector<int>> arr1,int l1,int r1,int x1)
{
    if (r1>=l1)
    {
        int mid = l1+(r1-l1)/2 ;
        if (arr1[mid][0]==x1)
        {
            return mid ;//found succesfully
        }
        else if (r1-l1==1||mid==l1)
        {
            return l1 ;// found first one 
        }
        if (arr1[mid][0]>x1)
        {
            return binarysearch1(arr1,l1,mid,x1 );
        }
            return binarysearch1(arr1,mid,r1,x1 );
    }
    
    return -1;


}

int binarySearch2(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return binarySearch2(arr, l, mid - 1, x);
  
        return binarySearch2(arr, mid + 1, r, x);
    }
  
    return -1;
}






int main(int argc, char const *argv[])
{
    
    

    int r,c ,target1;
    cin>>target1;
    cin>>r>>c ; 
    vector<vector<int>> a1(r) ;
    for (int i1 = 0; i1 < r; i1++)
    {
        vector<int> temp1;temp1.assign(c,0) ;
        for (int j1 = 0; j1 < c; j1++)
        {
            cin>>temp1[j1];
        }

        a1[i1] = temp1;
    }
    // for (int i1 = 0; i1 < r; i1++)
    // {
    //     cout<<endl;
    //     for (int j1 = 0; j1 < c; j1++)
    //     {
    //         cout<<a1[i1][j1]<<" ";
    //     }

        
    // }
    int whichrow = binarysearch1(a1,0,r,target1);
    cout<<endl<<whichrow;
    if (a1[whichrow][0]==target1)
    {
        cout<<"TRUE1" ;
    }

    else if (a1[whichrow][0]>target1)
    {
        //this row doesnt contains it
        cout<<"FALSE1" ;
    }
    else
    {
        int asnwer1 = binarySearch2(a1[whichrow],0,c-1,target1);
        cout<<endl<<asnwer1 ;
    }
    
    
    

    return 0;
}












