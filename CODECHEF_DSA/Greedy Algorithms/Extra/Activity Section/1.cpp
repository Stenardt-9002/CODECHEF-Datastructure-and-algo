
#include<iostream>
#include<algorithm>

using namespace std; 
struct daat{
    int start,end,diff;
};

// bool compareTwodaat(struct daat a , struct daat b)
// {
//     if (a.diff!=b.diff)
//     {
//         // return true;
//         return a.diff < b.diff;
//     }
//     else
//     {
//         return a.start<b.start;
//     }
    
    
//     // return false;
// }


bool compareTwodaat(struct daat a, struct daat b)
{
    return a.end < b.end ;
}


int main(int argc, char const *argv[])
{
    int testcaes    ;
    cin>>testcaes;
    int n;
    // int *input_array,*output_array;
    struct daat *satlitearray;
    int count1,counter;

    while (testcaes--)
    {
    cin>>n;
    count1 = 0;
    // input_array = new int[n];
    // output_array = new int[n];
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cin>>input_array[i1];
    // }

    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cin>>input_array[i1];
    // }    



    // delete [] input_array;
    // delete [] output_array;    


    satlitearray = new struct daat[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>satlitearray[i1].start;
    }

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>satlitearray[i1].end;
        satlitearray[i1].diff = satlitearray[i1].end - satlitearray[i1].start;
    }
    
    sort(satlitearray,satlitearray+n,compareTwodaat);



//    for (int i1 = 0; i1 < n; i1++)
//     {
//         cout<<satlitearray[i1].start<<" "<<satlitearray[i1].end<<" "<<satlitearray[i1].diff<<endl;
//     }    

    count1 = 1;counter = 0;

    for (int i1 = 1; i1 < n; i1++)
    {
        if (satlitearray[counter].end <= satlitearray[i1].start)
        {
            counter = i1;
            count1++;

        }
        
    }
    

    delete [] satlitearray;
    cout<<count1<<endl;

    }

    return 0;
}


