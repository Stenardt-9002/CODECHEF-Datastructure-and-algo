#include <bits/stdc++.h>
using namespace std;

bool comapre1(string a , string b)
{
    return a.compare(b)<0 ;
}
void recurs1ive(string a,vector<string>&ss1,int l,int r)
{
    if (l==r)
    {
        ss1.push_back(a);
    }
    else
    {
        for (int i1 = l; i1 <=r; i1++)
        {
            swap(a[l],a[i1]);
            recurs1ive(a,ss1,l+1,r) ;
            swap(a[l],a[i1]);

        }
    }
}





string getPermutation(int n, int k) 
{    
    string s1="" ;
    for (int i1 = 0; i1 < n; i1++)
    {
        s1+=to_string(i1+1);
    }
    // cout<<s1;
    vector<string> ans1 ;
    recurs1ive(s1,ans1,0,n-1);


    for (int i1 = 0; i1 < ans1.size(); i1++)
    {
        cout<<endl<<ans1[i1];
    }
    sort(ans1.begin(),ans1.end(),comapre1);
    cout<<endl<<endl;
    for (int i1 = 0; i1 < ans1.size(); i1++)
    {
        cout<<endl<<ans1[i1];
    }

    return ans1[k];
}







///better solution
int factorial(int n,int *dp1)
{
    dp1[0] =1 ;
    for (int i1 = 1; i1 <=n; i1++)
    {
        dp1[i1] = (i1)*dp1[i1-1];
    }

}



// int get


string getPermutation(int n, int k) 
{    
    string s1="" ;
    for (int i1 = 0; i1 < n; i1++)
    {
        s1+=to_string(i1+1);
    }
    // cout<<s1;
    vector<string> ans1 ;
    int fact1[n+1];
    int x1 = factorial(n,fact1);
    int ptr1 = n-1;

    int remo ,quotie ;
    int curentindx = k;
    while (ptr1>0)
    {
        quotie = curentindx/fact1[ptr1];
        remo = curentindx%fact1[ptr1]
        
        ptr1--;
    }
    



}



















int main(int argc, char const *argv[])
{

    getPermutation(3,5) ;
    return 0;
}
