
#include<iostream>
#include<algorithm>
typedef long long int lld;
using namespace std;

struct datatipe{
    long long int  startime,endtiem;
    int index1;
} ;


bool compare1(datatipe a1, datatipe b1)
{
    return a1.endtiem<b1.endtiem;
}





int main(int argc, char const *argv[])
{
    int testcaes;
    cin>>testcaes;

    int n;

    datatipe arr1[101];
    int asnwer1[101];

    while (testcaes--)
    {
        int cunt1 = 1; //get array count

        cin>>n;

        for (int i1 = 0; i1 < n; i1++)
        {
            cin>>arr1[i1].startime;
            arr1[i1].index1 = i1;
        }
            
        for (int i1 = 0; i1 < n; i1++)
        {
            cin>>arr1[i1].endtiem;
        }
            
        sort(arr1,arr1+n,compare1);

        // cout<<endl;
        // for (int i1 = 0; i1 < n; i1++)
        // {
        //     cout<<arr1[i1].startime<<" "<<arr1[i1].endtiem<<" ,";
        // }
        
        asnwer1[0] = arr1[0].index1;
        int trverse = 1;
        lld end1 = arr1[0].endtiem;

        while (trverse<n)
        {
            if (arr1[trverse].startime>end1)
            {
                asnwer1[cunt1++] = arr1[trverse].index1;
                end1 = arr1[trverse].endtiem;
            }
                        





            
            trverse++;
        }
        





        for (int i1 = 0; i1 < cunt1; i1++)
        {
            cout<<asnwer1[i1]+1<<" ";
        }

        cout<<endl;





    }
    






    return 0;
}






