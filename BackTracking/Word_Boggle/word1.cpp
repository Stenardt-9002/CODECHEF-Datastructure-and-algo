
//dfs based olution




#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>


using namespace std;



int mtachfuc(string str1,vector<string> dickionary)
{

    int n1s = dickionary.size();
    for (int i1 = 0; i1 < n1s; i1++)
    {
        if(dickionary[i1]==str1)
        {
            // cout<<"DEBIG" <<dickionary[i1]<<"\n";
            return 1;
        }
    }
    return 0;



}


                // findWords(ch_ar1,dickionary,visited_1,i1,j1k,str1,m1,n1);

void findWords(vector<vector<char>> char1,vector<string> dickionary,bool **vsited1,int i1,int j1,string &str1,int rows,int cols)
{
    //done with start index 
    vsited1[i1][j1] = true;

    str1 = str1+char1[i1][j1];

    if (mtachfuc(str1,dickionary))
    {
        cout<<str1<<" ";
    }

    for (int i12 = i1-1; i12 <=i1+1 ; i12++)
    {
        for (int k12 = j1-1; k12 <=j1+1 ; k12++)
        {
            if (i12>=0 && k12>=0&&k12<cols&&i12<rows && vsited1[i12][k12]==false )
            {
                findWords(char1,dickionary,vsited1,i12,k12,str1,rows,cols);




            }
            
        }
        
    }

    //when done with word formation delete that shiz 

    str1.erase(str1.length()-1);
    vsited1[i1][j1] = false;
    
    



}











int main(int argc, char const *argv[])
{
    string str1,str2;
    vector<string> dickionary;
    // cin>>str1>>str2;
    int testcaes;
    cin>>testcaes;

    int nobrestr,m1,n1;

    while (testcaes--)
    {
        cin>>nobrestr;
        for (int i1 = 0; i1 < nobrestr; i1++)
        {
            cin>>str1;
            dickionary.push_back(str1);
        }
        
        // cout<<"Nigga\n";
        // for (int i1 = 0; i1 < nobrestr; i1++)
        // {
        //     cout<<dickionary[i1]<<" ";
        //     // cin>>str1;
        //     // dickionary.push_back(str1);
        // }
        

        cin>>m1>>n1;
        bool **visited_1;
        visited_1 = new bool*[m1];
        vector<vector<char>> ch_ar1(m1);
        for (int i1 = 0; i1 < m1; i1++)
        {
            vector<char> tem1p(n1);
                visited_1[i1] = new bool[n1];

            for (int j1k = 0; j1k < n1; j1k++)
            {
                cin>>tem1p[j1k];
                visited_1[i1][j1k]=false;
            }
            ch_ar1[i1] = tem1p;
        }
        

        // cout<<endl;
         str1 = "";
        for (int i1 = 0; i1 < m1; i1++)
        {
            for (int j1k = 0; j1k < n1; j1k++)
            {
                findWords(ch_ar1,dickionary,visited_1,i1,j1k,str1,m1,n1);


            }
        }

        
        

    for (int i1 = 0; i1 < m1; i1++)
        {
            delete []visited_1[i1];
        }

    delete []visited_1;
        


    }
    





    // if (str1==str2)
    // {
    //     cout<<endl<<"Donot approach";
    // }
    



    return 0;
}








