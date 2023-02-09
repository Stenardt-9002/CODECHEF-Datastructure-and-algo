


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
	
// 	bool get_done
	
	
	int minimumOperations(int n,vector<int> &arr)
	{
		//code here
		if(n==1)
		    return 0 ;
		int max_ele = arr[0];
		for(int i = 1 ; i<n;i++)
		    max_ele = max(arr[i],max_ele);

		for (int i = 0; i < n; i++)
            if(arr[i]==max_ele)
                arr[i] = 1;
            else 
                arr[i] = 0;

        
		int start = 0 ;
		int counter = 0 ;
		bool last = 0;
        int i = arr.back();
		while(arr.size())
		{
		    int cnt = 0 ;
            while(arr.size() && arr.back()==i)
            {
                cnt++ ;
                arr.pop_back();
            }
            if(i==0)
            {
                counter+=(cnt+1)/2;
                if(last && cnt%2 && start==1 )
                {
                    counter-- ;
                    last = 0 ;
                    start = 0 ;
                }
                else 
                {
                    last = cnt%2 ;
                }
            }
            else 
                start = cnt ; 

            i = i^1 ;

		}
		
		return counter ;
	}
};
