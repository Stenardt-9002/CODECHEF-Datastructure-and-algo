// You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed


#include<iostream>
#include<algorithm>
using namespace std;

struct dicdatak{
    int x,y,z;
};
int min (int x, int y) 
{ return (x < y)? x : y; } 


int max (int x, int y) 
{ return (x > y)? x : y; } 
int maxHeight(int[] ,int[],int[],int );

int main(int argc, char const *argv[])
{
    int testcaes;
    cin>>testcaes;

    while(testcaes--)
    {
        int n;
        cin>>n;

        int A[1000],B[1000],C[1000];
        for (int i1 = 0; i1 < n; i1++)
        {
            /* code */
            int a,b,c;
            cin>>a>>b>>c;
            A[i1] = a;
            B[i1] = b;
            C[i1] = c;
        }
        
    cout<<maxHeight(A,B,C,n);

    }
    return 0;
}

bool compare1(dicdatak a, dicdatak b)
{
   if ((((b.y)*(b.z))-((a.y)*(a.z)))>=0)
   {
       return 0;
   }
    
    return 1;


        // return (((b.d)*(b.w))-((a.d)*(a.w))>=0);


}



int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
   dicdatak array1[3*n]; 
   int traver = 0;
    for (int ij = 0; ij < n; ij++)
    {
        /* code */
        // array1[traver].x = height[ij];
        // array1[traver].y = width[ij]; array1[traver].z = length[ij];

        // traver+=1;
        // array1[traver].y = height[ij]; array1[traver].z = width[ij]; array1[traver].x = length[ij];


        // traver+=1;
        // array1[traver].z = height[ij]; array1[traver].x = width[ij]; array1[traver].y = length[ij];
        // traver+=1;


        array1[traver].x = height[ij];

        array1[traver].y = max(width[ij],length[ij]); array1[traver].z = min(width[ij],length[ij]);

        traver+=1;
        
        array1[traver].x = width[ij];

        array1[traver].y = max(height[ij],length[ij]); array1[traver].z = min(height[ij],length[ij]);


        traver+=1;
        
        array1[traver].x = length[ij];

        array1[traver].y = max(width[ij],height[ij]); array1[traver].z = min(width[ij],height[ij]);
        traver+=1;


    }
    
    sort(array1,array1+3*n,compare1);

    int lis1[3*n];
    for (int ji1 = 0; ji1 < 3*n; ji1++)
    {
        lis1[ji1] = array1[ji1].x; // save hieght to apply lis
    }
    //longest increasing no height be greater on above shit (no dimension allowed to be greater than base)

    for (int ji1 = 1; ji1 < 3*n; ji1++)
    {
        for (int ki1 = 0; ki1 < ji1; ki1++)
        {
            if ((array1[ji1].y < array1[ki1].y) && (array1[ji1].z<array1[ki1].z)&& (lis1[ji1] < lis1[ki1]+array1[ji1].x) )  //note y has been kept bigger
            {
                lis1[ji1] = lis1[ki1]+array1[ji1].x;
            }
            
        }
        
    }

    int max1 = -1;
    max1 = *max_element (lis1, lis1+3*n);
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     if (max1<)
    //     {
    //         /* code */
    //     }
        
    // }
    return max1;
    

}



// int pottyfunction()
