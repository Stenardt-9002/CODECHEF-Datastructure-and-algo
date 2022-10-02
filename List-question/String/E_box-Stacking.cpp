#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


int compar1e(vector<int> a , vector<int> b)
{
    return (a[1]*a[2])>(b[1]*b[2]);
}



int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<vector<int>> struct_array ;

    for (int i1 = 0; i1 < n; i1++)
    {
        vector<int>temp1(3,0);
        temp1[0]= height[i1];
        temp1[1] = max(width[i1],length[i1]);
        temp1[2] = min(width[i1],length[i1]);
        struct_array.push_back(temp1);

        temp1[0]= width[i1];
        temp1[1] = max(length[i1],height[i1]);
        temp1[2] = min(length[i1],height[i1]);
        struct_array.push_back(temp1);


        temp1[0]= length[i1];
        temp1[1] = max(height[i1],width[i1]);
        temp1[2] = min(height[i1],width[i1]);
        struct_array.push_back(temp1);

    }
    sort(struct_array.begin(),struct_array.end(),compar1e);

    // for (auto x : struct_array)
    //     cout<<endl<<x[0]<<" "<<x[1]<<" "<<x[2];
    

    vector<int>dp1(3*n,0);
    for (int i1 = 0; i1 < 3*n; i1++)
        dp1[i1] = struct_array[i1][0];

    for (int i1 = 1; i1 < 3*n; i1++)
    {
        for (int j1 = 0; j1 < i1; j1++)
            if(struct_array[i1][2]<struct_array[j1][2]&&struct_array[i1][1]<struct_array[j1][1] && dp1[i1]<dp1[j1]+struct_array[i1][0]  )
                dp1[i1] = dp1[j1]+struct_array[i1][0];
    }
    int ans1 = INT_MIN;
    for (int i1 = 0; i1 < 3*n; i1++)
        ans1 = max(ans1,dp1[i1]);

    return ans1 ;
}


int main(int argc, char const *argv[])
{
    int height[] = {4,1,4,10};
    int width[] = {6,2,5,12};
    int length[] = {7,3,6,32};
    maxHeight(height,width,length,4);

    return 0;
}





