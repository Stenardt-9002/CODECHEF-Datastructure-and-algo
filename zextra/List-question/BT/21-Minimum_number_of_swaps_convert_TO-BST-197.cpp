    
    


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



    static bool comparator(pair<int,int> a1,pair<int,int> b1)
    {
        return a1.first<b1.first;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    int ans1 = 0;
	    int n = nums.size();
	    vector<pair<int,int>> a1 ;
	    for(int i1 = 0;i1<n;i1++)
	        a1.push_back({nums[i1],i1});
	    
	    sort(a1.begin(),a1.end(),comparator);
	    vector<bool>visited(n,false);
	    int j ,cycle_size = 0;
	    for(int i1=0;i1<n;i1++)
	    {
	        if(visited[i1] || a1[i1].second==i1)
	            continue ;
	       j = i1 ;
	       cycle_size = 0;
	       while(visited[j]==false)
	       {
	           visited[j]=true;
	           j = a1[j].second ;
	           cycle_size++;
	       }
	       if(cycle_size>0)
	        ans1+=(cycle_size-1);
	    }
	    
	    return ans1 ;
	}



void Inorder_traversal(TreeNode *node1,vector<int> &Ionder)
{
    if (node1!=NULL)
    {
        Inorder_traversal(node1->left , Ionder);
        Ionder.push_back(node1->val);
        Inorder_traversal(node1->right,Ionder);
    }
    
}



int func_util(TreeNode *node1)
{
    vector<int> Ionder ;
    Inorder_traversal(node1, Ionder);
    return minSwaps(Ionder);
}



int main(int argc, char const *argv[])
{
        TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->left->left->left= new TreeNode(6);

    
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    vector<int>preorder={1,2,4,6,5,7,8,9,10} ;
    vector<int>inorder1={6,4,2,5,1,8,7,9,10} ;

    cout<<" "<<minSwaps(inorder1)<<endl;
    cout<<" "<<func_util(root)<<endl;

    return 0;
}




