#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


// int editDistance(string s, string t) 
// {
//     int slen1 = s.length();
//     int tlen1 = t.length();

//     vector<vector<int>> dp1(slen1+1);
//     for (int i1 = 0; i1 <= slen1; i1++)
//     {
//         dp1[i1] = vector<int>(tlen1+1);
//         for (int j1 = 0; j1 <=tlen1; j1++)
//         {
//             dp1[i1][j1] = 0;
//         }
        
//     }
    


//     for (int i1 = 0; i1 <= slen1; i1++)
//     {
//         for (int j1 = 0; j1 <= tlen1; j1++)
//         {
//             if (i1==0)
//             {
//                 dp1[i1][j1] = j1;//insert in first string 
//             }
//             else if(j1 == 0)
//             {
//                 dp1[i1][j1] = i1 ;//delete in second string
//             }
//             else if (s[i1-1]==t[j1-1])//both string 
//             {
//                 dp1[i1][j1] = dp1[i1-1][j1-1];
//             }
//             else
//             {
//                 dp1[i1][j1] = 1+min({dp1[i1][j1-1],dp1[i1-1][j1],dp1[i1-1][j1-1] });
            
//             }
            


//         }
        
//     }
    
//     return dp1[slen1][tlen1];
    
// }








int editDistance(string s, string t) 
{
    int slen1 = s.length();
    int tlen1 = t.length();

    vector<vector<int>> dp1(2);
    for (int i1 = 0; i1 < 2; i1++)
    {
        dp1[i1] = vector<int>(tlen1+1);
        for (int j1 = 0; j1 <=tlen1; j1++)
        {
            dp1[i1][j1] = 0;
        }
        
    }
    


    for (int i1 = 1; i1 <= slen1; i1++)
    {
        for (int j1 = 0; j1 <= tlen1; j1++)
        {
            // if (i1==0)
            // {
            //     dp1[i1][j1] = j1;//insert in first string 
            // }
            if(j1 == 0)
            {
                dp1[i1%2][j1] = i1 ;//delete in second string
            }
            else if (s[i1-1]==t[j1-1])//both string 
            {
                dp1[i1%2][j1] = dp1[(i1-1)%2][j1-1];
            }
            else
            {
                dp1[i1%2][j1] = 1+min({dp1[i1%2][j1-1],dp1[(i1-1)%2][j1],dp1[(i1-1)%2][j1-1] });
            
            }
            


        }
        
    }
    
    return dp1[slen1%2][tlen1];
    
}












int main(int argc, char const *argv[])
{
    int slen1 = 

    return 0;
}







