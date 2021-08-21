#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;



string longestpalindrome(string str)
{
    int len = str.length() ;
    int asnwerlenght = 1;
    int startindex = 0 ;
    string asnwerstring = "" ;
    int left , right ;
    for (int i1 = 0; i1 < len; i1++)
    {
        //odd 
        left = i1-1 ;
        right = i1 ;
        while(left>=0 && right<len&& str[left]==str[right])
        {
            left-- ; right ++ ;
        }
        left++; right--;

        if (str[left]==str[right] && right-left+1>asnwerlenght )
        {
            asnwerlenght = right-left+1 ; 
            startindex = left ;
        }
        


        left = i1-1 ;
        right = i1+1 ;
        while(left>=0 && right<len&& str[left]==str[right])
        {
            left-- ; right ++ ;
        }
        left++; right--;

        if (str[left]==str[right] && right-left+1>asnwerlenght )
        {
            asnwerlenght = right-left+1 ; 
            startindex = left ;
        }
        



        






    }
    


        for (int i1 = startindex; i1 < asnwerlenght+startindex; i1++)
            {
                asnwerstring+=str[i1];
            }
            


    return asnwerstring;


}

int main(int argc, char const *argv[])
{
        string str1 = "tesetfoftest" ;
    str1 = "forgeeksskeegfor";
    cout<<longestpalindrome(str1);
    return 0;
    return 0;
}














