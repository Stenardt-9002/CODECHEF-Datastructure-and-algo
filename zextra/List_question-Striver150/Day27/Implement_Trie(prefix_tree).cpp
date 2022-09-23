// https://leetcode.com/problems/implement-trie-prefix-tree/







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;

class Node {
    Node *links[26];
    bool flag = false ;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    void put(char ch , Node *node)
    {
        links[ch-'a'] = node ;
    }

};

class Trie {
public:

    Node* root  ;

    Trie() {
        
    }
    
    void insert(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; i1 < word.length(); i1++)
        {
            if(node->containsKey(word[i1])!=NULL)
            {

            }
        }
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};


// https://www.geeksforgeeks.org/trie-delete/?ref=lbp


// https://colab.research.google.com/drive/1RxMcrBr93n7hHNvn-EIklXygFsmlZTjl
// #pytorch
// https://www.youtube.com/watch?v=U0i7-c3Vrgc&list=PLZoTAELRMXVNxYFq_9MuiUdn2YnlFqmMK
// https://www.youtube.com/watch?v=GIsg-ZUy0MY
// https://jovian.ai/aakashns/02-linear-regression
// https://jovian.ai/aakashns/01-pytorch-basics
// https://jovian.ai/aakashns/02-linear-regression
// https://jovian.ai/aakashns/01-pytorch-basics






// https://www.coursera.org/learn/probability-theory-statistics/home/week/1
// https://www.coursera.org/learn/linear-algebra-machine-learning/home/week/1
// https://www.coursera.org/learn/neural-networks-deep-learning/home/week/1
// https://www.coursera.org/specializations/deep-learning
// https://www.coursera.org/in-progress?page=1
// https://www.coursera.org/professional-certificates/google-data-analytics?page=1
// https://web.learncodeonline.in/
// https://www.udemy.com/home/my-courses/learning/




// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/coin-piles5152
// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
// https://practice.geeksforgeeks.org/problems/distributing-question-papers2513/1
// https://leetcode.com/problems/bag-of-tokens/submissions/
// https://www.geeksforgeeks.org/longest-common-subarray-in-the-given-two-arrays/
// https://practice.geeksforgeeks.org/problems/minimum-swaps-1649134975/1

