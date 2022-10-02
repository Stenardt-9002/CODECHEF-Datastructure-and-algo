


#include<vector>
#include<iostream>
#include<climits>

using namespace std ; 



// int findDuplicate(vector<int> &nums )
// {

//     int n1 = nums.size(),temp1 ; 

//     int toalsize = ((n1-1)*n1)/2 ; 

//     for (auto itr = nums.begin(); itr != nums.end(); itr++)
//     {
//         temp1 = *itr;
//         toalsize-=temp1 ;

//     }
    
//     return -toalsize;


// }


// int findDuplicate(vector<int> &nums )
// {

//     int n1 = nums.size(),temp1 ; 

//     int toalsize = ((n1-1)*n1)/2 ; 

//     // for (auto itr = nums.begin(); itr != nums.end(); itr++)
//     // {
//     //     // temp1 = *itr;
//     //     // toalsize-=temp1 ;
//     //     // frequency based method 
//     // }
//         for (int i1 = 0; i1 < n1; i1++)
//         {
//             nums[nums[i1]%n1] = nums[nums[i1]%n1] + n1 ;

//         }
//     int element ; 
//         for (int i1 = 0; i1 < n1; i1++)
//         {
//             if(nums[i1]>=n1*2 )
//             {
//                 element = i1 ;
//                 break ;
//             }

//         }


//     return element ;

// }


int findDuplicate(vector<int> &nums )
{

        int n1 = nums.size() ; 

        for (int i1 = 0; i1 < n1; i1++)
        {
            nums[nums[i1]%n1] = nums[nums[i1]%n1] + n1 ;

        }
        for (int i1 = 0; i1 < n1; i1++)
            {
                if(nums[i1]>=n1*2 )
                {
                    return i1 ;
                }

            }


    return -1;

}








// cyle detection 
int main(int argc, char const *argv[])
{








    return 0;
}































