


#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;



int isPlaindrome(char S[])
{

    // int n1 = sizeof(S)/sizeof(S[0]);
    int n1 = strlen(S);

    for (int i1 = 0; i1 < n1/2; i1++)
    {
        if (S[n1-i1-1] != S[i1])
        {
            return 0 ;
        }
    }
    return 1; 
}



	int isPalindrome(string S)
	{
	    // Your code goes here
	   int n1 = S.length();
        for (int i1 = 0; i1 < n1/2; i1++)
        {
            if (S[n1-i1-1] != S[i1])
                return 0 ;
                
        }
        return 1; 
	}



int main(int argc, char const *argv[])
{
    char S[] = {'a','b','b','a'} ;

    cout<<isPlaindrome(S);

    return 0;
}















