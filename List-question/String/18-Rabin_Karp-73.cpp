

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

void rabin_karp(string txt , string pat)
{

    int sizen = txt.size() ;
    int sizem = pat.size() ;
    int hashpatter=0,hashtext=0 ;

    int pwer_val = 1;//needed in hash value calucation
    for (int i1 = 0; i1 < sizem-1; i1++)
        pwer_val = (pwer_val*256)%mod1;
    
    //hash sizem letters 
    for (int i1 = 0; i1 < sizem; i1++)
    {
        hashpatter = (hashpatter*256+(pat[i1]));
        hashtext = (hashtext*256+(txt[i1]));
    }
    
    for (int i1 = 0; i1 < sizen-sizem+1; i1++)
    {
        //if hash value matches then confirm by checking whether letters are same
        if (hashpatter==hashtext)
        {
            cout<<"\nHashvalue match \n";
            bool notsame = false ;
            for (int j1 = 0; j1 < sizem; j1++)
            {
                if(txt[i1+j1]!=pat[j1])
                    notsame = true ;
            }
            if (!notsame)
                cout<<"\nmatched at"<<i1<<endl ;
            
        }

        if(i1<sizen-sizem)
        {
            // update hash 
            //remove first character and add last one 
            hashtext = (256*(hashtext-(txt[i1]*pwer_val)) +txt[i1+sizem])%mod1;
            if(hashtext<0)
                hashtext+=mod1 ;
        }
    }
}





int main(int argc, char const *argv[])
{
    string txt = "EDDYABCDEEDDYABDEDDY";
    string pat = "EDDY";
    // char a = 97;
    // cout<<a ;
    rabin_karp(txt,pat);
    //     int sizen = txt.size() ;
    // int sizem = pat.size() ;
    // int hashpatter=0,hashtext=0 ;

    // int pwer_val = 1;//needed in hash value calucation
    // for (int i1 = 0; i1 < sizem-1; i1++)
    //     pwer_val = (pwer_val*256)%mod1;
    
    // //hash sizem letters 
    // for (int i1 = 0; i1 < sizem; i1++)
    // {
    //     hashpatter = (hashpatter*256+(pat[i1]));
    //     hashtext = (hashtext*256+(txt[i1]));
    //     cout<<endl<<hashtext<<" "<<hashpatter<<" ";
    // }
    return 0;
}


