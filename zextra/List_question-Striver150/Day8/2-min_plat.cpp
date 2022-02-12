
#include "bits/stdc++.h"



using namespace std;



    int findPlatform(int arr[], int dep[], int n)
    {




// O(logn*n) solution 


        sort(arr,arr+n);
        sort(dep,dep+n);

        int platallow = 1 ;
        int maxanswer1 = 1 ;

        int i1 = 1,j1 = 0; //i1 is 1 because platform is 1


        while (i1<n&&j1<n)
        {
            if (arr[i1]<=dep[j1])
            {
                i1++ ;
                platallow ++;
            }
            else if(arr[i1]>=dep[j1])
            {
                j1++ ; platallow--;
            }
               
            if (platallow>maxanswer1)
            {
                maxanswer1 = platallow ; 
            }
            



        }
        

        return maxanswer1;
    }


