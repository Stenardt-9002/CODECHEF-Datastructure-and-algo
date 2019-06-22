#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{   
    stack <long long int>  s;
    string str1;
    cin>>str1;
 
    for (size_t i = 0; i < str1.length(); i++)
    {
        if (s.empty())
        {
            s.push(str1[i]);
        }
        else
        {
            if (str1[i]==s.top())
            {
                s.pop();
            }
            else
            {
                s.push(str1[i]);
                
            }
            
        }
        
    }
    if (s.empty())
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
            }
    
    
    return 0;
}

