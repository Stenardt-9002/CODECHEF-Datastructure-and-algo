

#include "bits/stdc++.h"



using namespace std;

struct Item{
    int value;
    int weight;
};

    
bool comprator(Item a1 , Item a2)
{
    double x1 , x2 ;
    x1 = float(a1.value)/float(a1.weight);
    x2 = float(a2.value)/float(a2.weight);
    
    return x1>x2;
    
}

    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        int restweight =0,i1,lastpr=n+1;
        double answer = 0 ;
        sort(arr,arr+n,comprator) ;
        bool d1one = false;
        for(i1=0;i1<n&&d1one==false;i1++)
        {
            if(restweight+arr[i1].weight<=W)
            {
                restweight = restweight+arr[i1].weight ;
                answer += arr[i1].value ;
            }
            else
            {
                d1one = true;
                lastpr = i1;
            }
        }
        //cout<<" "<<i1<<" "<<restweight ;
        
        if(i1!=n+1&&lastpr<n && restweight<W)
        {
            float frac = (float(W-restweight)*float(arr[lastpr].value) )/float(arr[lastpr].weight) ;
            answer+=frac ;
        }
        
        return answer ;
        
        
    }