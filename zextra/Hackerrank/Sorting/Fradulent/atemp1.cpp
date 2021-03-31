#include <bits/stdc++.h>

using namespace std;


double findmediano(vector<int> a1,int size1)
{
    //even
    if (size1%2==0)
    {
        nth_element(a1.begin(),a1.begin()+size1/2,a1.end());

        nth_element(a1.begin(),a1.begin()+(size1-1)/2,a1.end());

        return (double)(a1[(size1-1)/2]+a1[(size1)/2] )/2.0 ;


    }
    //odd
    else
    {
        nth_element(a1.begin(),a1.begin()+size1/2,a1.end());
        return (double)a1[size1/2];
    }
    
    
}




// #nth element
int main(int argc, char const *argv[])
{
    int n1;
    int d1 ;
    cin>>n1>>d1;
    vector<int> a1(n1) ;
    vector<int> a2(d1) ;
    // int *a2 ;
    // vector<int> a2(n1) ;
    // a2 = new int[d1];
    int cunt = 0;
    for(int i1 = 0;i1<n1;i1++)
    {
        cin>>a1[i1];
    }
    float median1 ;
    for (int j1 = 0; j1 <=n1-d1; j1++)
    {
        for (int k1 = j1; k1 < j1+d1; k1++)
        {
            a2[k1-j1] = a1[k1] ;
        }
        
    

    //     //aray size is odd
    //     if (d1%2==1)
    //     {
    //         nth_element(a1.begin()+j1, a1.begin()+j1+d1/2,a1.begin()+j1+d1);
    //         median1 = a1[j1+d1/2];
    //     }
    // //array size is even

    //     else
    //     {
    //         nth_element(a1.begin()+j1, a1.begin()+j1+d1/2,a1.begin()+j1+d1);
    //         int m1 = a1[j1+d1/2];
    //         nth_element(a1.begin()+j1, a1.begin()+j1-1+d1/2,a1.begin()+j1+d1);
    //         int m2 = a1[j1+d1/2];
    //         median1 = (float)(m1+m2)/2.0;

    //     }



    median1 = findmediano(a2,d1);



        // cout<<"array ";
        // for (int i2 = j1; i2 < d1+j1; i2++)
        // {
        //     cout<<a1[i2]<<" ";
        // }
        
        // cout<<endl<<median1<<" "<<endl;

        if (2*median1<=a1[j1+d1])
        {
            cunt++;
        }
        


    }

    cout<<cunt ;
    // delete []a2;




    return 0;
}






