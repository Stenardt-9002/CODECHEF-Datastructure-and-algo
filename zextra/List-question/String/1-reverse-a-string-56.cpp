

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;


void reverseString(vector<char>& s) 
{
    char temp1 ;
    int n1 = s.size();
    for (int i1 = 0; i1 < n1/2; i1++)
    {
        temp1 = s[i1];
        s[i1] = s[n1-i1-1];
        s[n1-i1-1] = temp1 ;

    }
    


}




int main(int argc, char const *argv[])
{

    vector<char> s{'a','b','c','d','e'} ;

    reverseString(s);

    cout<<endl ;
    for (auto itr : s)
    {
        cout<<" "<<itr ;
    }
    



    return 0;
}





















