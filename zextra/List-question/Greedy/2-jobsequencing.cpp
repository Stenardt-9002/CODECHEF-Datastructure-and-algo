
#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool sortqacrdoing(Job var1 ,Job var2)
{
    return var1.profit>var2.profit ;
}

int index1(int *arr , int curridnex )
{

// cout<<endl;
//         for (int i1 = 0; i1 < curridnex; i1++)
//         {
//             cout<<" "<<arr[i1]<<" ";
//         }
        



    for (int i1 = curridnex-1; i1 >=0; i1--)
    {
        if(arr[i1]==-1)
        {
            //empty slot 
            return i1;
        }
    }
    return -1;

}




// void JobScheduling(Job *arrvar, int n) 
vector<int> JobScheduling(Job *arrvar, int n) 
{ 
       sort(arrvar,arrvar+n,sortqacrdoing);
    // cout<<endl;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<arrvar[i1].profit<<" ";
        
    // }
    int macdeadline = -1;
    for (int i1 = 0; i1 < n; i1++)
    {
        if (arrvar[i1].dead>macdeadline)
        {
            macdeadline = arrvar[i1].dead;
        }
        
    }
    // cout<<macdeadline<<endl;

    int arr1[macdeadline] ;
    for (int i1 = 0; i1 < macdeadline; i1++){arr1[i1] = -1;}
            
    
 
    int sum1 = 0;
    int cntjobs = 0;
    int curdead ;
    for (int i1 = 0; i1 < n; i1++)
    {
        curdead = arrvar[i1].dead ;
        // cout<<"HEHE  "<<curdead<<endl;
        // for (int j2 = 0; j2 < macdeadline; j2++){cout<<" "<<arr1[j2];}
        // cout<<endl;
            
        
        
        curdead = index1(arr1,curdead);
        if (curdead!=-1)
        {
            arr1[curdead] = arrvar[i1].id;
            sum1+=arrvar[i1].profit;
            cntjobs++ ;
        }
        
        // cout<<"HEHE  "<<curdead<<endl;
    }
    return {cntjobs,sum1};
    // cout<<endl<<cntjobs<<" "<<sum1 ;




} 


int main(int argc, char const *argv[])
{
    int n ; cin>>n;
    Job *arr2 = new Job[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr2[i1].id ;
        cin>>arr2[i1].dead ;
        cin>>arr2[i1].profit ;
    }
//     sort(arr2,arr2+n,sortqacrdoing);

//    for (int i1 = 0; i1 < n; i1++)
//     {
//         cout<<arr2[i1].profit<<" " ;
//     }
    vector<int> asnwer1 ;
    asnwer1 = JobScheduling(arr2,n);

    cout<<endl ;
    cout<< asnwer1[0]<<" "<<asnwer1[1];

    delete []arr2;
    return 0;
}
    












/*
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    
    
    static bool sortqacrdoing(Job var1 ,Job var2)
    {
        return var1.profit>var2.profit ;
    }
    
    int index1(int *arr , int curridnex )
    {
    
    // cout<<endl;
    //         for (int i1 = 0; i1 < curridnex; i1++)
    //         {
    //             cout<<" "<<arr[i1]<<" ";
    //         }
            
    
    
    
        for (int i1 = curridnex-1; i1 >=0; i1--)
        {
            if(arr[i1]==-1)
            {
                //empty slot 
                return i1;
            }
        }
        return -1;
    
    }
    


    
    
    
    
    // vector<int> JobScheduling(Job arr[], int n) 
    vector<int> JobScheduling(Job *arrvar, int n) 
    { 
        // your code here
        
               sort(arrvar,arrvar+n,sortqacrdoing);
            
                int macdeadline = -1;
                for (int i1 = 0; i1 < n; i1++)
                {
                    if (arrvar[i1].dead>macdeadline)
                    {
                        macdeadline = arrvar[i1].dead;
                    }
                    
                }
                // cout<<macdeadline<<endl;
            
                int arr1[macdeadline] ;
                for (int i1 = 0; i1 < macdeadline; i1++){arr1[i1] = -1;}
                        
                
             
                int sum1 = 0;
                int cntjobs = 0;
                int curdead ;
                for (int i1 = 0; i1 < n; i1++)
                {
                    curdead = arrvar[i1].dead ;
        
                    curdead = index1(arr1,curdead);
                    if (curdead!=-1)
                    {
                        arr1[curdead] = arrvar[i1].id;
                        sum1+=arrvar[i1].profit;
                        cntjobs++ ;
                    }
                    
                    
                }
                return {cntjobs,sum1};
                
    } 
};



*/





