
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Solution{
public:

    void merge1(vector<long long int>& v,long long int left,
               long long int mid,long long int right,long long int& inversions)
    {
        vector<int> temp(right - left + 1);
     
        long long int i = left;
        long long int k = 0;
        long long int j = mid + 1;
        long long int cnt = 0;
     
        while (i <= mid && j <= right) {
            if (v[i] <= v[j]) {
                temp[k++] = v[i++];
            }
            else {
                // Counting inversions
                inversions += (mid - i + 1);
     
                temp[k++] = v[j++];
            }
        }
     
        while (i <= mid)
            temp[k++] = v[i++];
     
        while (j <= right)
            temp[k++] = v[j++];
     
        k = 0;
        for (long long int a = left; a <= right; a++) {
            v[a] = temp[k++];
        }
    }
     

void merge_Sort(vector<long long int>& v,long long int left,
               long long int right,long long int& inversions)
{
    if (left < right) {
        long long int mid = (left + right) / 2;
 
        merge_Sort(v, left, mid, inversions);
        merge_Sort(v, mid + 1, right, inversions);
        merge1(v, left, mid, right, inversions);
    }
}
 



    long long int recusion_fuc(vector<long long >prefix_s)
    {
        int n = prefix_s.size();
        long long int inversion = 0;
        merge_Sort(prefix_s , 0 , n-1 , inversion);
        return inversion ;
    }

  long long countSubstring(string S)
  {
    // code here
    int n = S.length();
    vector<short>nums(n,0);
    for(int i=0;S[i];++i)
        nums[i] = S[i]=='1'?1:-1;
    vector<long long int>prefix_s(n,0);
    long long int sum1 = 0 ;
    for(int i=0;i<n;++i)
    {
        sum1+=nums[i];
        prefix_s[i] = sum1 ;
    }
    long long int count = 0 ;
    for(int i = 0;i<n;i++)
        if(prefix_s[i]>0)
            count++;
            
    reverse(prefix_s.begin(),prefix_s.end());
    long long int invers = recusion_fuc(prefix_s);
    return count+invers;
    
  }
};


































class Solution{
public:
  long long countSubstring(string S){
    int n=S.size();
    long long ans=0,zero=n,minus=0;
    int mp[2*n+5];
    memset(mp,0,sizeof(mp));
    int cur=zero;
    for(auto i:S){
      if(i=='0')
        cur--;
      else
        cur++;
      if(cur<=zero){
        minus++;
      }
      mp[cur]++;
    }
    for(int i=0;i<n;i++){
      ans+=(n-i-minus);
      if(S[i]=='1'){
        mp[zero+1]--;
        zero++;
        minus+=mp[zero];
      }
      else{
        mp[zero-1]--;
        zero--;
        minus--;
        minus-=mp[zero+1];
      }
    }
    return ans;
  }
};




class Solution{
public:
  long long countSubstring(string S)
  {
    int n=S.size();
    long long ans=0;
    long long int zero=n,minus=0;
    vector<int> dp(2*n+5,0);
    long long int cur=zero;
    for(auto i:S)
    {
      if(i=='0')
        cur--;
      else
        cur++;
      if(cur<=zero)
        minus++;
      
      dp[cur]++;
    }
    for(int i=0;i<n;i++)
    {
      ans+=(n-i-minus);
      if(S[i]=='1')
      {
        dp[zero+1]--;
        zero++;
        minus+=dp[zero];
      }
      else
      {
        dp[zero-1]--;
        zero--;
        minus--;
        minus-=dp[zero+1];
      }
    }
    return ans;
  }
};




















