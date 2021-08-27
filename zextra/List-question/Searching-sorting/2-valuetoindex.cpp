#include<iostream>
#include<vector>



using namespace std;

	vector<int> valueEqualToIndex(int arr[], int n) 
    {
        vector<int> anser;

        for (int i1 = 0; i1 < n; i1++)
        {
            if (arr[i1]==i1+1)
            {
                anser.push_back(arr[i1]) ;
            }
            
        }
        return anser ;
	}

int main(int argc, char const *argv[])
{



    return 0;
}























