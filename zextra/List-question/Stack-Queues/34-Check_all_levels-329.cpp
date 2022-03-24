#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if (p==NULL&&q==NULL)
        return true ;

        
    if (p==NULL||q==NULL)
        return false ;


    queue<TreeNode*> q1,q2 ;

    q1.push(p) ;q2.push(q);
    int sz1 = q1.size() ; int sz2 = q2.size() ;

    //loop queue

    while (1)
    {
       sz1 = q1.size() ;  sz2 = q2.size() ;
       //not same size  of each level 
        if (sz1!=sz2)
            return false ;

        if (sz1==0)
            break ;//break while loop



        //current level 
        vector<int> cur_levl_tree1 , curr_level_tree2 ;

        while (sz1>0)
        {
            TreeNode *node1 = q1.front() ;
            q1.pop() ;
            if (node1->left!=NULL)
                q1.push(node1->left) ;

            if (node1->right!=NULL)
                q1.push(node1->right) ;

            sz1--; //one element 

            //second tree 
            TreeNode *node2 = q2.front() ;
            q2.pop() ;
            if (node2->left!=NULL)
                q2.push(node2->left) ;

            if (node2->right!=NULL)
                q2.push(node2->right) ;


            cur_levl_tree1.push_back(node1->val) ;
            curr_level_tree2.push_back(node2->val);
        }

        //sort the level to check anagrams 
        sort(cur_levl_tree1.begin(),cur_levl_tree1.end()) ;
        sort(curr_level_tree2.begin(),curr_level_tree2.end());

        //vectr check 
        if (cur_levl_tree1!=curr_level_tree2)
            return false ; //differnt at this level         
    }
    return true ;

}





