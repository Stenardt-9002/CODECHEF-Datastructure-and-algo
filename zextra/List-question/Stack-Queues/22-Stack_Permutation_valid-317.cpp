// https://leetcode.com/problems/validate-stack-sequences/




#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;





// bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
// {
//     stack<int> tempstack ;
//     // queue<int> inpu_t ;
//     queue<int> oupu_t ;
//     int size = pushed.size() ;
//     for (int i1 = 0; i1 < size; i1++)
//     {
//         // inpu_t.push(pushed[i1]) ;
//         oupu_t.push(popped[i1]) ;
//     }

    
//     int curele,i=0 ;
//     while (i<size)
//     {
//         // curele = inpu_t.front() ;
//         // inpu_t.pop() ;
//         curele = pushed[i++];
//         if (curele==oupu_t.front())
//         {
//             oupu_t.pop();
//             while (!tempstack.empty())
//             {
//                 if (tempstack.top()==oupu_t.front())
//                 {
//                      tempstack.pop()    ;
//                      oupu_t.pop() ;
//                 }
//                 else    
//                     break ;
//             }
            
//         }
//         else
//             tempstack.push(curele)        ;

//     }
    
//     return tempstack.empty() ;

// }



    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
    
        stack<int> tempstack ;
        int size = pushed.size() ;


        int curele,i=0,j=0 ;
        while (i<size)
        {
            curele = pushed[i++];
            if (curele==popped[j])
            {
                j++;
                while (!tempstack.empty())
                {
                    if (tempstack.top()==popped[j])
                    {
                         tempstack.pop()    ;
                         j++;
                    }
                    else    
                        break ;
                }
            }
            else
                tempstack.push(curele)        ;
        }

        return tempstack.empty() ;
    }



int main(int argc, char const *argv[])
{

    vector<int> a1 = {1,2,3,4,5};
    vector<int>b1  = {4,3,5,1,2};
    cout<<" "<<validateStackSequences(a1,b1);

    return 0;
}

