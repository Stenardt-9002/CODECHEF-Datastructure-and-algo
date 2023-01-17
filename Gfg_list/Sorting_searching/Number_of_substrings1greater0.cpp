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

// tuple <char, int, float> geek ;
// get<0>(geek)


// pair<int, char> PAIR1;
// PAIR1.first ;
void print_tack(stack<int> a)
{
    cout<<endl<<endl ;
    while (a.empty()==false)
    {
        cout<<a.top()<<endl ;
        a.pop() ;
    }
    cout<<endl<<endl ;
}


// https://www.delftstack.com/howto/cpp/cpp-split-string-by-space/#:~:text=in%20C%2B%2B.-,Use%20std%3A%3Astring%3A%3Afind%20and%20std%3A%3Astring,value%20or%20a%20single%20character.
void processLine_cpp()
{
     string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed laoreet sem leo, in posuere orci elementum.";
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    words.push_back(text);

}


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to merge two partitions
// such that the merged array is sorted
void merge(vector<int>& v, int left,
		int mid, int right, int& inversions)
{
	vector<int> temp(right - left + 1);

	int i = left;
	int j = mid + 1;
	int k = 0;
	int cnt = 0;

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
	for (int a = left; a <= right; a++) {
		v[a] = temp[k++];
	}
}

// Function to implement merge sort
void mergeSort(vector<int>& v, int left,
			int right, int& inversions)
{
	if (left < right) 
	{
		int mid = (left + right) / 2;
		cout<<left<<" "<<right<<endl ;
		mergeSort(v, left, mid, inversions);
		cout<<endl<<left<<" "<<mid<<" "<<inversions<<endl ; 
		mergeSort(v, mid + 1, right, inversions);
		cout<<endl<<mid+1<<" "<<right<<" "<<inversions<<endl ; 
		merge(v, left, mid, right, inversions);
	}
}

// Function to calculate number of
// inversions in a given array
int CountInversions(vector<int>& v)
{
	int n = v.size();
	int inversions = 0;

	// Calculate the number of inversions
	mergeSort(v, 0, n - 1, inversions);

	// Return the number of inversions
	return inversions;
}

// Function to count the number of
// substrings that contains more 1s than 0s
int getSubsCount(string& input)
{
	int n = input.length();

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		nums[i] = input[i] - '0';

		if (nums[i] == 0)
			nums[i] = -1;
	}

	// Stores the prefix sum array
	vector<int> pref(n);

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += nums[i];
		pref[i] = sum;
	}

	int cnt = 0;

	// Stores the count of valid substrings
	for (int i = 0; i < n; i++) {
		if (pref[i] > 0)
			cnt++;
	}

	reverse(pref.begin(), pref.end());

	int inversions = CountInversions(pref);

	// int ans = cnt + inversions;
	int ans = inversions;

	return ans;
}

// Driver Code
int main()
{

	// Given Input
	string input = "110011";

	// Function Call
	int ans = getSubsCount(input);

	cout << ans << endl;

	return 0;
}



//Back-end complete function Template for C++
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

