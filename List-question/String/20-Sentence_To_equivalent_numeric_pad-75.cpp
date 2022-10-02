
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



string get_sequence(string mapping[],string input)
{
    string output = "";
    int n = input.size();
    for (int i1 = 0; i1 < n; i1++)
    {
        if(input[i1]==' ')
            output+="0" ;

        
        else 
        {
            int position = input[i1]-'A';
            output += mapping[position];
        }
    }
    return output ;
}



int main(int argc, char const *argv[])
{
    string maping[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888", "9","99","999","9999"};
    string inpt = "Hi how are you" ;
    cout<<endl<<get_sequence(maping,inpt);
    return 0;
}
