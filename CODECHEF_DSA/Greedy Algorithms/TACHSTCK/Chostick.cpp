#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n,d;
    cin>>n>>d;
    ll in[n];
    for (long long i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    //sort aray
    sort(in,in+n);
    ll count = 0;
    for (ll i = 0; i <n;i++)
    {
      if (in[i+1]-in[i]<=d)
      {
          count++;
          i++;
      }
    }
    std::cout << count << '\n';
  return 0;
}
