#include <bits/stdc++.h>
using namespace std;
//using dynamic programming

void printSubStr( string str, int low, int high )
{
	for( int i = low; i <= high; ++i )
		cout << str[i];
}
int longestPalSubstr(string str)
{
	// get length of input string
	int n = str.size();

	bool table[n][n];
	memset(table, 0, sizeof(table));

	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	int start = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if (str[i] == str[i+1])
		{
			table[i][i+1] = true;
			start = i;
			maxLength = 2;
		}
	}



	for (int k = 3; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1 ; ++i)
		{
			int j = i + k - 1;

			if (table[i+1][j-1] && str[i] == str[j])
			{
        // if i+1 to j-1 is a pallidrome and str1[i]==str1[j] then my friend i,j is also a pallindrom
				table[i][j] = true;

				if (k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}

printSubStr( str, start, start + maxLength - 1 );

	return maxLength;
}

int main()
{
	string str ;
  std::cin >> str;
	 longestPalSubstr( str );
	return 0;
}
