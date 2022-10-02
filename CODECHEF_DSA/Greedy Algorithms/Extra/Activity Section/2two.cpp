
#include<iostream>
#include<algorithm>

using namespace std; 
struct daat{
    int start,end;//,diff;
};


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



    satlitearray = new struct daat[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>satlitearray[i1].start;
    }

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>satlitearray[i1].end;
        // satlitearray[i1].diff = satlitearray[i1].end - satlitearray[i1].start;
    }
    
    sort(satlitearray,satlitearray+n,compareTwodaat);
 

    count1 = 1;counter = 0; //first min activity always selected

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


