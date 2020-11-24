
#include<iostream> 
#include<vector> 
#include<cstring>
#include<map>
using namespace std;





void checkMagazine(vector<string> magazine , vector<string> noet)
{
    int n1 = magazine.size() ; 
    int n2 = noet.size() ; 

    map<string,int> var1 ;
    for (int i1 = 0; i1 < n1; i1++)
    {
        if (var1.find(magazine[i1])== var1.end())
        {
            //not find 
            var1[magazine[i1]] = 1 ; 
        }
        else
        {
            var1[magazine[i1]] += 1 ; 
        }
        
    }
    int clear = 1 ;

    for (int i1 = 0; i1 < n2; i1++)
    {
        if (var1.find(noet[i1])== var1.end())
        {
            //not find 
            clear = 2;
            break ;
        }
        else
        {
            if (var1[noet[i1]]>0)
            {
                var1[noet[i1]] -= 1 ; 
            }
            else
            {
                clear = 2 ; 
                break ;
            }
            
            
        }
        
    }


    if (clear==1)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    
    

    




}








