// trie implementation  





#include <iostream>
#include <stdio.h>
#include <vector>
#include<string.h>



#define SIEZA 26







using namespace std;



struct TrieNode
{
    TrieNode* child[SIEZA ];

    bool last1;


};

TrieNode *getnode()
{
    TrieNode *newnode = new TrieNode;
    newnode->last1 = false ;
    for (int i1 = 0; i1 < SIEZA; i1++)
    {
        newnode->child[i1] = NULL;
    }
    return newnode;
    

}






int max1(int a,int b)
{
  return (a>b)?a:b;
}


int main(int argc, char const *argv[])
{
    
    string str1,str2;
    vector<string> dickionary;


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


        TrieNode *triestrtnode = getnode();

        cin>>m1>>n1;
        vector<vector<char>> ch_ar1(m1);
        for (int i1 = 0; i1 < m1; i1++)
        {
            vector<char> tem1p(n1);

            for (int j1k = 0; j1k < n1; j1k++)
            {
                cin>>tem1p[j1k];
            }
            ch_ar1[i1] = tem1p;
        }
        




    }






    return 0;
}




















