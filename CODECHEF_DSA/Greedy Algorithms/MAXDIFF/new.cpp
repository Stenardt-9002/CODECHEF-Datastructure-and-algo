// C++ Program to find maximum weight
// difference
#include <iostream>
#include <algorithm>
using namespace std;

// return the max value of two numbers
int max(int a, int b)
{
	return a > b ? a : b;
}

int solve(int array[], int n, int k) 
{
	// sort the given array
	sort(array, array + n);

	// Initializing the value to 0
	int sum = 0, sum1 = 0, sum2 = 0;

	// Getting the sum of the array
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}

	// Getting the sum of first k elements
	for (int i = 0; i < k; i++) {
		sum1 += array[i];
	}

	// Getting the sum of (n-k) elements
	for (int i = k; i < n; i++) {
		sum2 += array[i];
	}

	// Returning the maximum possible difference.
	return max(abs(sum1 - (sum - sum1)), abs(sum2 -
								(sum - sum2)));
}

// Driver function
int main()
{
	int k = 2;
	int array[] = { 8, 4, 5, 2, 10 };

	// calculate the numbers of elements in the array
	int n = sizeof(array) / sizeof(array[0]);

	// call the solve function
	cout << solve(array, n, k);

	return 0;
}
