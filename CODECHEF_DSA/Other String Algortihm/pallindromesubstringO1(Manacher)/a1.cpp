#include<iostream>
#include<cstring>
#include<stdio.h>


int mymin(int x, int y)
{
    return x>y?y:x;
}


using namespace std;



string function1(string str1)
{
    int n = str1.length();
    cout<<n;

    int new_len = 2*n+1;

    int L[new_len]; //LPS array

    L[0] = 0; L[1] = 1;
    int centerpos = 1; int centerright =  2; 
    int currentright = 0; int currentleft ; 
    int maxLPSLength = 0,maxLPSLengthcenterposition = 0;
    int start = -1;int end = -1;int diff = -1;



    for (currentright = 2; currentright < new_len; currentright++)
    {
        currentleft = 2*centerpos-currentright;
        L[currentright] = 0;
        diff = centerright-currentright;

        if (diff>0)
        {
            L[currentright] = mymin( L[currentleft],diff  );
        }
        
        while ( ( ( currentright+L[currentright]  <new_len ) && (currentright-L[currentright]>0 ) ) && (((currentright+L[currentright]+1)%2==0) || ( str1[(currentright+L[currentright]+1)/2 ] == str1[(currentright-L[currentright]-1)/2 ] )   ) )
        {
            L[currentright]+=1;
        }
        















    }
    





    return str1;
}






int main(int argc, char const *argv[])
{
    string str1;    
    str1 = "cdbabcbabdbab";
    // cout<<str1.length();
    // function1(str1);
    int x1 = mymin(19,15);
    cout<<endl<<x1;


    return 0;
}


