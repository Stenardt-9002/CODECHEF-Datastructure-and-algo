

// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

void pinrt_heap(priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> >heap1 , int ele)
{
        cout<<endl;
        while (!heap1.empty())
        {
                tuple<int,int,int> temp1 = heap1.top();
                cout<<" "<<get<0>(temp1)<<" "<<get<1>(temp1)<<" "<<get<2>(temp1)<<"    " ;
                heap1.pop() ;
        }
        cout<<endl<<ele<<endl;
}

// pair<int,int> findSmallestRange( int n, int k,int **KSortedArray)
// {
//         //code here

//         int min_ele = INT_MAX ;
//         int max_ele = INT_MIN ;
//         priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> >heap1 ;
//         for (int i1 = 0; i1 < k; i1++)
//         {
//                 if(KSortedArray[i1][0]>max_ele)
//                         max_ele = KSortedArray[i1][0] ;
//                 if(KSortedArray[i1][0]<min_ele)
//                         min_ele = KSortedArray[i1][0] ;
                
//                 heap1.push(make_tuple(KSortedArray[i1][0],i1,0));
//         }
//         bool flag_break = false ;
//         // cout<<endl;
//         // while(!heap1.empty())
//         // {
//         //         auto x=  heap1.top();heap1.pop();
//         //         cout<<" "<<get<0>(x);
//         // }

//         int minRange = max_ele-min_ele;
//         int ans1=min_ele , ans2=max_ele ;

//         while (!flag_break)
//         {
//                 // cout<<"DEBUG";
//                 pinrt_heap(heap1,minRange);
//              tuple<int,int,int> temp1 = heap1.top();
//              heap1.pop() ;
//              min_ele= get<0>(temp1);
//              if(minRange>max_ele-min_ele)
//              {
//                      minRange = max_ele-min_ele;
//                         ans1 = min_ele ; 
//                         ans2 = max_ele ;
//              }

//                 int arr_indx = get<1>(temp1) ;
//                 int pos_in_arr = get<2>(temp1);
//                 if(pos_in_arr<n-1)
//                 {
//                         heap1.push(make_tuple(KSortedArray[arr_indx][pos_in_arr+1],arr_indx,pos_in_arr+1));
//                         max_ele = max(max_ele,KSortedArray[arr_indx][pos_in_arr+1]);
//                 }
//                 else 
//                 flag_break = true ;
        

//         }
        
//         return {ans1,ans2};
// }


pair<int,int> findSmallestRange( int n, int k,int **KSortedArray)
{
        //code here

        int min_ele = INT_MAX ;
        int max_ele = INT_MIN ;
        // priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> >heap1 ;
        multiset<tuple<int,int,int>>heap1;
        for (int i1 = 0; i1 < k; i1++)
        {
                if(KSortedArray[i1][0]>max_ele)
                        max_ele = KSortedArray[i1][0] ;
                if(KSortedArray[i1][0]<min_ele)
                        min_ele = KSortedArray[i1][0] ;
                
                heap1.insert(make_tuple(KSortedArray[i1][0],i1,0));
        }
        bool flag_break = false ;
        // cout<<endl;
        // while(!heap1.empty())
        // {
        //         auto x=  heap1.top();heap1.pop();
        //         cout<<" "<<get<0>(x);
        // }

        int minRange = max_ele-min_ele;
        int ans1=min_ele , ans2=max_ele ;

        while (!flag_break)
        {
                // cout<<"DEBUG";
                // pinrt_heap(heap1,minRange);
             tuple<int,int,int> temp1 = *heap1.begin();
        //      heap1.pop() ;
                heap1.erase(heap1.begin());
             min_ele= get<0>(temp1);
             if(minRange>max_ele-min_ele)
             {
                     minRange = max_ele-min_ele;
                        ans1 = min_ele ; 
                        ans2 = max_ele ;
             }

                int arr_indx = get<1>(temp1) ;
                int pos_in_arr = get<2>(temp1);
                if(pos_in_arr<n-1)
                {
                        heap1.insert(make_tuple(KSortedArray[arr_indx][pos_in_arr+1],arr_indx,pos_in_arr+1));
                        max_ele = max(max_ele,KSortedArray[arr_indx][pos_in_arr+1]);
                }
                else 
                flag_break = true ;
        

        }
        
        return {ans1,ans2};
}

int main(int argc, char const *argv[])
{
        int n,k;
        cin>>n>>k;
        int **arr1 = new int*[k];
        for (int i1 = 0; i1 < k; i1++)
        {
                arr1[i1] = new int[1000];
                for (int j1 = 0; j1 < n; j1++)
                        cin>>arr1[i1][j1];
        }
        auto x =findSmallestRange(n,k,arr1);
        cout<<"\nDEBUG1 "<<x.first<<" "<<x.second;
        delete[]arr1 ;
        return 0;
}


