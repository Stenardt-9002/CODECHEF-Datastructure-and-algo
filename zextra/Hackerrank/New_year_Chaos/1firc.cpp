

#include<iostream>


using namespace std;



int count_brieb(int *arr1,int n1)
{
    bool sorvatcheck = true ; 

    for (int x1 = 0; x1 < n1; x1++)
    {
        if (arr1[x1]-(x1+1)>2)
        {
            sorvatcheck = false ; 
            break ; 
        }
        
    }
    if (sorvatcheck)
    {
        int c = 0;
        int t ; 
        sorvatcheck = false;
        for (int y1 = 0; y1 < n1; y1++)
        {
            if (sorvatcheck)
            {
                break ;  
            }
            sorvatcheck = true ; 
            for (int x1 = 0; x1 < n1-y1-1; x1++)
            {
                if (arr1[x1+1]<arr1[x1])
                {
                    t = arr1[x1];
                    arr1[x1] = arr1[x1+1];
                    arr1[x1+1] = t ; 
                    sorvatcheck = false ; 
                    c++;
                }
                
            }
            
            
        }
        printf("%d\n",c);

    }
    else
    {
        printf("Too chaotic\n");
    }
    
    
    



}






int main(int argc, char const *argv[])
{
    int testcaes ;
     
    cin>>testcaes ; 
    int n1 ; 
     while (testcaes--)
     {
        cin>>n1;    
        int *arr1 = new int[n1];
        for (int i1 = 0; i1 < n1; i1++)
        {
            cin>>arr1[i1];

        }

        int answer = count_brieb(arr1);



            delete[] arr1;
        
     }
     

    return 0;
}

















