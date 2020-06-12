// #include<bits/stdc++.h>
#include<iostream>
#include <queue>
using namespace std;


void printMedians(double arr[], int n)
{

	priority_queue<double> smallheap;

  priority_queue<double,vector<double>,greater<double> > greaterheap;

	double medianvar = arr[0];
	smallheap.push(arr[0]);

	cout << medianvar << endl;


	for (int i=1; i < n; i++)
	{
		double newinput = arr[i];


		if (smallheap.size() > greaterheap.size())
		{
			if (newinput < medianvar)
			{
				greaterheap.push(smallheap.top());
				smallheap.pop();
				smallheap.push(newinput);
			}
			else
				greaterheap.push(newinput);

			medianvar = (smallheap.top() + greaterheap.top())/2.0;
		}


		else if (smallheap.size()<greaterheap.size())
		{


      if (newinput > medianvar)
			{
				smallheap.push(greaterheap.top());
				greaterheap.pop();
				greaterheap.push(newinput);
			}
			else
				smallheap.push(newinput);

			medianvar = (smallheap.top() + greaterheap.top())/2.0;

		}

		else
		{
      if (newinput < medianvar)
			{
				smallheap.push(newinput);
				medianvar = (double)smallheap.top();
			}
			else
			{
				greaterheap.push(newinput);
				medianvar = (double)greaterheap.top();
			}
		}

		cout << (int)(medianvar) << endl;
	}
}


int main()
{
	int lefnth;
  cin>>lefnth;
  double *arr1 = new double[lefnth];
  for (int i = 0 ;i<lefnth;i++)
  {
    cin>>arr1[i];
  }

	printMedians(arr1, lefnth);
  delete[] arr1;
	return 0;
}
