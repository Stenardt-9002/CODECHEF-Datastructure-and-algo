// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1/?page=3&curated[]=2&sortBy=submissions


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

vector<int> numbertovector(int n)
{
  std::vector<int> re;
  if(n==0)
    return {0};
  while(n!=0)
  {
    re.push_back(n%10);
    n /=10 ;
  }
  reverse(re.begin(),re.end());
  return re ;
}


vector<int> add_vak(vector<int>a1 , vector<int> b1)
{
  int carry=0 ,val ;
  int n = a1.size();
  int m = b1.size();
  vector<int> ans1 ;
  reverse(a1.begin(),a1.end());
  reverse(b1.begin(),b1.end());


  if(m>n)
    a1.swap(b1),std::swap(n,m);

    // cout<<endl<<n<<" "<<m<<endl;
  for (int i1 = 0; i1 < m; i1++)
  {
    val = a1[i1]+b1[i1]+carry;
    if(val>9)
      carry = 1 ;
    else
      carry = 0 ;

    // cout<<endl<<val<<" "<<a1[i1]<<" "<<b1[i1]<<endl;

    ans1.push_back(val%10);
  }
  for (int i1 = m; i1 < n; i1++)
  {
    val = a1[i1]+carry;
    if(val>9)
      carry = 1 ;
    else
      carry = 0 ;

    ans1.push_back(val%10);
  }
  if(carry==1)
    ans1.push_back(1);


  reverse(ans1.begin(),ans1.end());
  return ans1 ;
}


vector<int> multiple(vector<int>a1 , int b1)
{
    int carry=0 ,val ;
    int n = a1.size();
    vector<int> ans1 ;
    reverse(a1.begin(),a1.end());



    for (int i1 = 0; i1 < n; i1++)
    {
      val = (a1[i1]*b1)+carry;
      carry = val/10 ;
      val = val%10 ;
      // cout<<endl<<val<<" "<<a1[i1]<<" "<<b1[i1]<<endl;
      ans1.push_back(val);
    }

    while(carry!=0)
    {
      ans1.push_back(carry%10);
      carry/=10;
    }
    reverse(ans1.begin(),ans1.end());
    return ans1;
  // vector<int> orig = a1;
  // for (int i1 = 1; i1 < b1; i1++)
  //   a1 = add_vak(a1,orig);
  //
  // return a1 ;
}

vector<int> factorial(int N)
{
    // code here
    if(N==0||N==1)  return {1} ;
    std::vector<int> nthfact = {1};
    for (int i1 = 2; i1 <=N; i1++)
      nthfact = multiple(nthfact,i1);

    // // vector<int> ans1 = add_vak({1,3,8},{9,8,5});
    // // vector<int> ans1 = multiple({1,3,8},3);
    //
      cout<<endl ;
      for(auto x : nthfact)
        cout<<" "<<x;


    return nthfact ;
}













static vector<int> multiple(vector<int>a1 , int b1)
{
    int carry=0 ,val ;
    int n = a1.size();
    vector<int> ans1 ;
    reverse(a1.begin(),a1.end());



    for (int i1 = 0; i1 < n; i1++)
    {
      val = (a1[i1]*b1)+carry;
      carry = val/10 ;
      val = val%10 ;
      // cout<<endl<<val<<" "<<a1[i1]<<" "<<b1[i1]<<endl;
      ans1.push_back(val);
    }

    while(carry!=0)
    {
      ans1.push_back(carry%10);
      carry/=10;
    }
    reverse(ans1.begin(),ans1.end());
    return ans1;
}



vector<int> factorial(int N)
{
    // code here
    if(N==0||N==1)  return {1} ;
    std::vector<int> nthfact = {1};
    for (int i1 = 2; i1 <=N; i1++)
      nthfact = multiple(nthfact,i1);

    return nthfact ;

}




int main(int argc, char const *argv[]) {
  factorial(7);
  return 0;
}
