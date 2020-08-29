#include<iostream>

using namespace std;

class Pair_Daat
{
    public:
    int a,b;
};






int main(int argc, char const *argv[])
{

    int n;
    cin>>n ;
    Pair_Daat *arr1 = new Pair_Daat[n];
    int *dp1 = new int[n];

    int count1=0 ;
    while (count1<n)
    {
        cin>>arr1[count1].a>>arr1[count1].b;
        dp1[count1] = 1;
        count1++;
    }

    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     for (int j1 = i1+1; j1 < n; j1++)
    //     {
    //         if (arr1[j1].a>=arr1[i1].b)
    //         {
    //             dp1[j1] = std::max(dp1[i1]+1,dp1[j1]);
                                
                
    //         }
            
    //     }
        

    // }


    for (int i1 = 1; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < i1; j1++)
        {
            if (arr1[i1].a>arr1[j1].b && dp1[i1]<dp1[j1]+1)
            {
                dp1[i1] = dp1[j1]+1;
            }
               
        }
        
    }
    






    int max1 = dp1[0];
    for (int i1 = 0; i1 < n; i1++)
    {
        if (max1 < dp1[i1] )
        {
            max1 = dp1[i1];
        }
        
    }
    cout<<endl;
    for (int i1 = 0; i1 < n; i1++)
    {
       cout<<dp1[i1]<<" "; 
    }
    

    cout<<max1;
    
    
    delete [] arr1;
    delete []dp1;
    
    return 0;
}














