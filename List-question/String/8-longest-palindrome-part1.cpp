#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;



string longestpalindrome(string str)
{
    int n = str.size();
    bool table[n][n] ;
    int firstindex ;
    string asnwerstring = "";
    memset(table,0,sizeof(table));
    int asnwerlength = 1;
    for (int i1 = 0; i1 < n; i1++)
    {
        table[i1][i1] = 1 ;
    }
    // length 2 
    for (int i1 = 0; i1 < n-1; i1++)
    {
        if (str[i1]==str[i1+1] )
        {
            table[i1][i1+1] = 1;
            asnwerlength = 2;
        }
        

    }
    
    //lenghts greater


    for (int k = 3; k < n; k++)
    {
        // k is length of string 
        for (int i1 = 0; i1 < n-k+1; i1++)
        {
            int j1 = i1+k-1 ;
            if(table[i1+1][j1-1]==1 && str[i1]==str[j1])
            {
                table[i1][j1]=1 ;
                if (k>=asnwerlength)
                {
                    firstindex = i1 ;
                    asnwerlength = k; 
                }
                

            }


        }
        
    }
    
    for (int i1 = firstindex; i1 < asnwerlength+firstindex; i1++)
    {
        asnwerstring+=str[i1];
    }
    
    return asnwerstring ;

}








int main(int argc, char const *argv[])
{
    string str1 = "tesetfoftest" ;
    str1 = "forgeeksskeegfor";
    cout<<longestpalindrome(str1);
    return 0;
}























