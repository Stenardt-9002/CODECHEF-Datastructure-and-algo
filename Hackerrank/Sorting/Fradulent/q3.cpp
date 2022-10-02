#include <bits/stdc++.h>

using namespace std;


// Complete the activityNotifications function below.

// #nth element
int main(int argc, char const *argv[])
{
    int n1;
    int d1 ;
    cin>>n1>>d1;
    vector<int> a1(n1) ;
    int *a2 ;
    // vector<int> a2(n1) ;
    a2 = new int[n1];
    int cunt = 0;
    for(int i1 = 0;i1<n1;i1++)
    {
        cin>>a2[i1];
    }
    float median1 ;
    for (int j1 = 0; j1 <=n1-d1; j1++)
    {

        for(int i1 = 0;i1<n1;i1++)
            {
                a1[i1] = a2[i1];
            }

        //aray size is odd
        if (d1%2==1)
        {
            nth_element(a1.begin()+j1, a1.begin()+j1+d1/2,a1.begin()+j1+d1);
            median1 = a1[j1+d1/2];
        }
    //array size is even

        else
        {
            nth_element(a1.begin()+j1, a1.begin()+j1+d1/2,a1.begin()+j1+d1);
            int m1 = a1[j1+d1/2];
            nth_element(a1.begin()+j1, a1.begin()+j1-1+d1/2,a1.begin()+j1+d1);
            int m2 = a1[j1+d1/2];
            median1 = (float)(m1+m2)/2.0;

        }
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
    delete []a2;




    return 0;
}






