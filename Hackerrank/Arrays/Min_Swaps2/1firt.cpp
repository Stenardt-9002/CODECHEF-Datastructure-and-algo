#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
struct Dat_tipe1
{
    int val,index;
};


bool funcn(Dat_tipe1 a1, Dat_tipe1 b1)
{
    return a1.val<b1.val;
}


// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) 
{

    int siez = arr.size();

    Dat_tipe1 arr1pos[siez];
    bool visted[siez];

    for (int i1 = 0; i1 < siez; i1++)
    {
        arr1pos[i1].val = arr[i1];
        arr1pos[i1].index = i1;
        visted[i1] = false;

    }

    sort(arr1pos,arr1pos+siez,funcn);
    int answer1 = 0;


    for (int i1 = 0; i1 < siez; i1++)
    {
        cout<<arr1pos[i1].val<<" ";
    }
    



    for (int j1 = 0; j1 < siez; j1++)
    {
        if(visted[j1] || arr1pos[j1].index == j1 )
        {
            continue;
        }



        int indicycle = 0;
        int k1 = j1; //start to next node and count cycles

        while (visted[k1]==false)
        {
            
            visted[k1] = true;
            k1 = arr1pos[k1].index ;
            indicycle++;
        //mve to next node
        }


        if(indicycle>0)
        {
            answer1+=(indicycle-1);
        }


    }

    
    return answer1;



}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    vector <int> arr1;
    int x1;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>x1;arr1.push_back(x1);
    }
    
x1 = minimumSwaps(arr1);
cout<<x1<<endl;

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // string arr_temp_temp;
    // getline(cin, arr_temp_temp);

    // vector<string> arr_temp = split_string(arr_temp_temp);

    // vector<int> arr(n);

    // for (int i = 0; i < n; i++) {
    //     int arr_item = stoi(arr_temp[i]);

    //     arr[i] = arr_item;
    // }

    // int res = minimumSwaps(arr);

    // fout << res << "\n";

    // fout.close();

    // return 0;
}

// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });

//     input_string.erase(new_end, input_string.end());

//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }

//     vector<string> splits;
//     char delimiter = ' ';

//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);

//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));

//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }

//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

//     return splits;
// }






