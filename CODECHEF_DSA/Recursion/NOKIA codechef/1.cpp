#include<iostream>
using namespace std;

int cal_min(int a,int b)
{
    int sum,mid ;
    mid = a+b;
    mid = mid/2;
    //case wehther the bumber is middle even or odd?
    if(b-a==2)
    {
        return 2;
    }
    else if (b-a<2)
    {
        return 0;
    }
    sum = b-a;
    sum = cal_min(a,mid)+cal_min(mid,b)+sum ;

    return sum;
}


int main(int argc, char const *argv[])
{
    int n,m;
    int min,max,t;//?
    
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {    
        cin>>n>>m;
        max = 0;
        for (size_t i = n+1; i >= 2; i--)
        {
            max = max+i;
        }
        
        int test = cal_min(0,n+1);
        // cout<<test;
        // cout<<max;
        // cout<<'\n'<<min<<'\n';
        min = test;
        if(m<min)
        {
            cout<<-1;
        }
        else if (m>=min && m<=max)
        {
            cout<<0;
        }
        else
        {
            cout<<m-max;
        }
        cout<<endl;
        
    }

    return 0;
}


