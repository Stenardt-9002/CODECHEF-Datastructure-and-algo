

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;


    string countAndSay(int n) {
        if (n==1)
        {
            return "1" ;
        }

        string str1 = countAndSay(n-1) ;
        // string str1 = "3322255" ;
        string str2 = "" ;
        int lengthofstring1 = str1.length() ;
        char temp1 = str1[0] ;
        int count1 = 1 ;
        for (int i1 = 1; i1 < lengthofstring1; i1++)
        {
            if (temp1==str1[i1])
            {
                count1++ ;
            }
            else
            {
                str2 = str2+to_string(count1)+temp1 ;
                count1 = 1 ;
                temp1 = str1[i1] ;
            }
        }
    
        str2 = str2+to_string(count1)+temp1 ;
        return str2 ; 

        
    }



int main(int argc, char const *argv[])
{
    string str1 = countAndSay(4);
    cout<<str1;

    return 0;
}










