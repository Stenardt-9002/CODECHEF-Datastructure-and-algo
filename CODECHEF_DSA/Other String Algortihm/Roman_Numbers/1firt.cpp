
#include<iostream>

#include<cstring>
using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
int romanToDecimal(string &str)
{
    int answer1 = 0;
    int lengt_h = str.length();
    int iter1 = 0 ;
    int value1 = 0,value2=0 ; 
    while (iter1<lengt_h)
    {
        value1 = value(str[iter1]);
        if (iter1+1<lengt_h)
        {
            value2 = value(str[iter1+1]); 
            if (value2>value1)
            {
                answer1 = answer1+value2-value1 ; 
                iter1++ ; 
            }
            else
            {
                answer1 = answer1+value1 ; 
            }
            




        }
        else
        {
            answer1 += value1 ;
        }
        
        



        iter1++ ; 
    }
    


    return answer1 ;



}


int main()
{

    int testcaes ; 
    cin>>testcaes ;
    int roamn ;
    while (testcaes--)
    {
        string s1 ; 
        cin>>s1 ; 
        roamn = romanToDecimal(s1) ; 
        cout<<roamn<<endl ; 
    }
    



}








