

#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std ; 


bool function1(vector<int>a1,vector<int>b1)
{
    return a1[0]<b1[0];
}







vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(),intervals.end(),function1)    ;

    int n1 = intervals.size() ;
    vector<vector<int>> return1(n1) ; 

    int index1 = 0;//start 
    int itr1 = 0;
    for (int i1 = 1; i1 < n1; i1++)
    {
        // vector<int>a1 = intervals[index1];
        if (intervals[index1][1]>=intervals[i1][0])
        {
            intervals[index1][1] = max(intervals[index1][1],intervals[i1][1]);
            intervals[index1][0] = min(intervals[index1][0],intervals[i1][0]);
        }
        else
        {
            return1[itr1++] = intervals[index1] ;
            index1 = i1 ;
        }
        
        


    }
    if (return1[itr1]!=intervals[index1])
    {
           return1[itr1] =  intervals[index1];
           itr1++;
    }
    
    cout<<endl ; 
    vector<vector<int>> return2 ;

    for (int i1 = 0; i1 < itr1; i1++)
    {
        cout<<return1[i1][0]<<" "<<return1[i1][1]<<endl ;
        return2.push_back(return1[i1]) ;
    }
    // return1.resize(n1,itr1);
    


    return return2 ;
}




int main(int argc, char const *argv[])
{
    // vector<vector<int>> var1{
    //     {1,2},{10,12},{14,18},{3,12},{7,12}
    // } ;

    //     vector<vector<int>> var1{
    //     {1,3},{2,6},{8,10},{15,18}
    // } ;

  vector<vector<int>> var1{
        {1,3}
    } ;



    // vector<int> a1 = {2,5} ;
    // vector<int> a1 = {2,5} ;
    // vector<int> a1 = {2,5} ;
    // vector<int> a1 = {2,5} ;
    // vector<int> a1 = {2,5} ;
    int n1 = var1.size() ;

    for (int i1 = 0; i1 < n1; i1++)
    {
        cout<<var1[i1][0]<<" "<<var1[i1][1]<<endl ;
    }

//     sort(var1.begin(),var1.end(),function1)    ;
//  for (int i1 = 0; i1 < n1; i1++)
//     {
//         cout<<var1[i1][0]<<" "<<var1[i1][1]<<endl ;
//     }

    vector<vector<int>> var2 ;

    var2 = merge(var1) ;





    return 0;
}








