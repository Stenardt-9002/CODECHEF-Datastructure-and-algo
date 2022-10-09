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



// Function to get the bit at the
// ith position
bool getBit(int num, int i)
{
	return ((num & (1 << i)) != 0);
}


// Function to set the ith bit of the
// given number num
int setBit(int num, int i)
{
	return num | (1 << i);
}

// Function to clear the ith bit of
// the given number N
int clearBit(int num, int i)
{
	int mask = ~(1 << i);
	return num & mask;
}

int clearMSBtoith(int num , int i)
{
    int mask = (1 << i) - 1;
    num &= mask;
    return num ;
}


int clearLSBtoith(int num , int i)
{
    int mask = ~((1 << i+1 ) - 1);
    num &= mask;
    return num ;
}

// x >>= 1;
// x <<= 1;
//toggle pos th bit
void toggle(int& num, int pos) { num ^= (1 << pos); }

int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x-1);
        count++;
    }
    return count;
}


int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

bool at_position(int num, int pos)
{
    bool bit = num & (1 << pos);
    return bit;
}


bool swap(int a,int b)
{
    // A quick way to swap a and b
a ^= b;
b ^= a;
a ^= b;

}


//get MSD 
int MSD(int n){
      if(n == 0)
        return 0;
      int k = log10(n);
    int x = pow(10,k);
    int ans = n/x;
      return ans;
}


//binary number 
int main()
{
    auto number = 0b011;
    cout << number;
    return 0;
}




