#include "bits/stdc++.h"



using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool compratr1(Job a1,Job b1)
{
    return a1.profit>b1.profit ;
}




int main(int argc, char const *argv[])
{

    int n ;
    cin>>n ;
    Job arr1[n];
    int max_dealline = 0 ;
    int numofjobs = 0;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1].id>>arr1[i1].dead>>arr1[i1].profit ;
        if (max_dealline<arr1[i1].dead)
        {
            max_dealline = arr1[i1].dead;
        }
        
    }
    // cout<<"\nDEBUG "<<max_dealline<<endl;
    sort(arr1,arr1+n,compratr1);



    bool *arrbool = new bool[max_dealline];
    for (int i1 = 0; i1 < max_dealline; i1++)
    {
        arrbool[i1] = false ;
    }
    


    int profit1 = 0;
    int temp1  ;
    bool thisjibdone = false;
    for (int i1 = 0; i1 < n; i1++)
    {

        temp1 = arr1[i1].dead-1;
        // cout<<"\nDEBUG "<<temp1<<endl;

        thisjibdone = false ;
        
        while (temp1>=0&& thisjibdone==false)
        {

            if (!arrbool[temp1])//available
            {
                arrbool[temp1] = true;//deadlones occupied
                profit1+=arr1[i1].profit ;//job done
                // cout<<"\nDEBUG3 "<<profit1<<endl;

                thisjibdone = true;
                numofjobs++;
            }
            temp1--;

        }
        
        // cout<<" "<<arr1[i1].id<<" "<<arr1[i1].dead<<" "<<arr1[i1].profit<<endl ;
    }
    cout<<     profit1 ;
    
    delete []arrbool ;
    return 0;
}




















