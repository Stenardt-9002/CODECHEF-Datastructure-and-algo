#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.


int mediancal(int arr1[] , int d)
{
    
}

// quickselect
int select1(int *arr1,int left1,int right1,int num1)
{
    while (1)
    {
        if (left1==right1)
        {
            return left1 ; 
        }
        
        int pivotIndex = pivot(arr1,left1,right1) ;
        int pivotIndex = partition(arr1,left1,right1,pivotIndex,num1) ;
        if (num1==pivotIndex)
        {
            return num1 ;
        }
        else if (num1<pivotIndex)
        {
            right1 = pivotIndex-1 ;
        }
        
        else
        {
            left1 = pivotIndex+1;
        }
        
        

    }
    


}


int partition(int *arr1,int left1,int right1,int pivotIndex , int num1 )
{
    int pivotValue = arr1[pivotIndex] ; 
    
    //swap
    int temp1 = arr1[pivotIndex] ; 
    arr1[pivotIndex] = arr1[right1];
    arr1[right1] = temp1;

    int storeIndex = left1 ;
    for (int i1 = left1; i1 < right1-1; i1++)
    {
        if (arr1[i1]<pivotIndex)
        {
            temp1 = arr1[storeIndex];
            arr1[storeIndex] = arr1[i1] ; 
            arr1[i1] = temp1 ;
            storeIndex++;
        }
        

    }
    
    int storeindexEq = storeIndex ;

    for (int i1 = storeIndex; i1 < right1-1; i1++)
    {
        if ()
        {
                
        }
        
    }
    


}






int activityNotifications(vector<int> expenditure, int d) 
{
    int lenth = expenditure.size() ; 
    int notifcation = 0;
    int arrtemnp1[d];
    double medinava;
    for (int i2 = 0; i2 < lenth-d-1; i2++)
    {
        for (int j2 = i2; j2 < i2+d; j2++)
        {
            arrtemnp1[j2-i2] = expenditure[j2] ;
            
        }
        //sort temp array 
        sort(arrtemnp1,arrtemnp1+d);
        if(d%2==0)
        {
            medinava = arrtemnp1[i2+d/2]+arrtemnp1[i2-1+d/2] ;
            medinava = medinava/2 ;
        }
        else
        {
            medinava = arrtemnp1[i2+d/2] ;
        }
        

        if (expenditure[i2+d]>medinava )
        {
            notifcation++;
        }
        

    }
    

    return notifcation;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}