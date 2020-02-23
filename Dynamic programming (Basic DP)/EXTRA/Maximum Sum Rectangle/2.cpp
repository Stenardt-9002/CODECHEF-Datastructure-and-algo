
#include<bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

int kadane(int* arr, int* start,
		int* finish, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN, i;

	*finish = -1;

	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}


	if (*finish != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
	// Variables to store the final output
	int maxSum = INT_MIN, finalLeft, finalRight,
						finalTop, finalBottom;

	int left, right, i,z;
	int temp[ROW], sum, start, finish;

	// Set the left column
	for (left = 0; left < COL; ++left)
	{
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		for (right = left; right < COL; ++right)
		{

			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			sum = kadane(temp, &start, &finish, ROW);

      //visualise temp
      printf("\nOKOKOK\n" );
      for (int k = 0; k < 4; k++)
      {
        std::cout << " "<<temp[k] ;
      }
      printf("\nOKOKOK1 %d\n",sum );

			if (sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}

      std::cout << "\n maxSum "<<maxSum<<" finalLeft "<<finalLeft<<" finalRight "<<finalRight <<" finalTop "<<finalTop<<" finalBottom "<<finalBottom<< '\n';

      std::cin >> z;
		}
	}

	// Print final values
	cout << "(Top, Left) (" << finalTop
		<< ", " << finalLeft << ")" << endl;
	cout << "(Bottom, Right) (" << finalBottom
		<< ", " << finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
	int M[ROW][COL] = {{1, 2, -1, -4, -20},
					{-8, -3, 4, 2, 1},
					{3, 8, 10, 1, 3},
					{-4, -1, 1, 7, -6}};

	findMaxSum(M);

	return 0;
}
