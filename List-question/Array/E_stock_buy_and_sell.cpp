
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;







// void stockBuySell(int price[], int n) 
// {

//     if (n==1)
//         return ;


//     int i1 =0 ;
//     while (i1<n)
//     {
//         while ((i1<n-1 ) && (price[i1+1]<=price[i1]) )
//         i1++;

//         if (i1==n-1)
//             break ;

//         int init = i1++ ;

//         while ((i1<n) && (price[i1]>=price[i1-1]))
//         i1++ ;

//         int finsis = i1-1 ;
//         cout<<init<<" "<<finsis<<endl;
//     } 
// }




// void stockBuySell(int price[], int n) 
// {

//     if (n==1)
//         return ;

//     int init =-1,finsis =-1;
//     int i1 =0 ;
//     int cunt1 = 0;
//     int flafg1 = true ;
//     while (i1<n)
//     {
//         while ((i1<n-1 ) && (price[i1+1]<=price[i1]) )
//         i1++;

//         if (i1==n-1)
//             break ;

//         init = i1++ ;

//         while ((i1<n) && (price[i1]>=price[i1-1]))
//         i1++ ;

//         finsis = i1-1 ;
//         // if(finsis!=init)
//         // {
//         //     cout<<"("<<init<<" "<<finsis<<") ";
//         //     cunt1++;
//         // }
        
//         if(flafg1)
//             {
//                 cout<<"("<<init<<" "<<finsis<<")";
//                 flafg1 = false;
//                 cunt1++ ;
//             }
//         else 
//         cout<<" ("<<init<<" "<<finsis<<")";
//     } 
//     if(cunt1==0)
//         cout<<"No Profit";
// }



//gfg accepted solution 
void stockBuySell(int price[], int n) 
{
    if (n==1)
        return ;
    
    vector<pair<int,int>> a1 ;

    int init =-1,finsis =-1;
    int i1 =0 ;
    int cunt1 = 0;
    int flafg1 = true ;
    while (i1<n)
    {
        while ((i1<n-1 ) && (price[i1+1]<=price[i1]) )
        i1++;

        if (i1==n-1)
            break ;

        init = i1++ ;
        //init is i1-1 now
        while ((i1<n) && (price[i1]>=price[i1-1]))
        i1++ ;

        finsis = i1-1 ;
        if(finsis!=init)
        {
            // cout<<"("<<init<<" "<<finsis<<") ";
            a1.push_back({init,finsis});
            cunt1++;
        }
        
        // if(flafg1)
        //     {
        //         cout<<"("<<init<<" "<<finsis<<")";
        //         a1.push_back({init,finsis});
        //         flafg1 = false;
        //         cunt1++ ;
        //     }
        // else 
        // cout<<" ("<<init<<" "<<finsis<<")";
    } 
    if(cunt1==0)
        cout<<"No Profit";
    else
    {
        for(auto x:a1)
        {
            cout<<"("<<x.first<<" "<<x.second<<") ";
        }
        
    }
    cout<<endl;
}







int main(int argc, char const *argv[])
{

    int n ;
    cin>>n ;
    int *arr1 = new int[n];
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1];
    
    stockBuySell(arr1,n);


    delete []arr1 ;

    return 0;
}




