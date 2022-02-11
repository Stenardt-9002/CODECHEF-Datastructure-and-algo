
#include "bits/stdc++.h"



using namespace std;



    void nextPermutation(vector<int>& nums) 
    {
        int ptr1 = nums.size()-2;
        int ptr2;
        int temp1 ;
        int temp2p ;
        while(ptr1>=0 &&(nums[ptr1]>=nums[ptr1+1]))
        {
            ptr1--;    
        }
        
        
        if(ptr1<0)
        {
            // sort(nums.begin(),nums.end());  
            reverse(nums.begin(),nums.end());
        }
        else
        {
            
            ptr2 = nums.size()-1 ;
            while(ptr1<ptr2 && nums[ptr1]>=nums[ptr2])
            {
                ptr2--;
            }
            
            temp1 = nums[ptr1]; //save last number to be swapped
            nums[ptr1] = nums[ptr2];
            nums[ptr2] = temp1;
            
            reverse(nums.begin()+ptr1+1,nums.end());
        }
        
    }



int main(int argc, char const *argv[])
{

    vector<int> a1 ;
    for (int i1 = 0; i1 < 3; i1++)
    {
        a1.push_back((i1+1)%3+1);
    }
     for (auto i1 = a1.begin(); i1 != a1.end() ; i1++)
    {
        cout<<*i1<<" ";
    }
    cout<<endl;
    nextPermutation(a1);
    cout<<endl;
    for (auto i1 = a1.begin(); i1 != a1.end() ; i1++)
    {
        cout<<*i1<<" ";
    }
    



    return 0;
}





    // void nextPermutation(vector<int>& nums) 
    // {
        // int ptr1 = nums.size()-2;
        // int temp1 ;
        // int temp2p ;
        // while(ptr1>=0 &&(nums[ptr1]>nums[ptr1+1]))
        // {
        //     ptr1--;    
        // }
        // if(ptr1<0)
        // {
        //     sort(nums.begin(),nums.end());    
        // }
        // else
        // {
        //     sort(nums.begin()+ptr1+1,nums.end()) ; //sort from ptr+1 , end()
        //     temp2p = ptr1+1 ;
        //     while(temp2p<nums.size()  && nums[ptr1]>=nums[temp2p])
        //     {
        //         temp2p++;
        //     }
        //     temp1 = nums[ptr1]; //save last number to be swapped
        //     nums[ptr1] = nums[temp2p];
        //     nums[temp2p] = temp1;
        // }
        
        
    // }












