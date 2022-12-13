


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


class Node
{

public:
    int data ;
    Node *left , *right ;
    Node(int val)
    {
        data = val ;
        left = right = NULL ;
    }
};



vector<vector<int>> level_order_traversal(Node* root)
{
    queue<Node*> q1;
    q1.push(root);
    vector<vector<int>> levels ;

    while (!q1.empty())
    {
        int size = q1.size();
        vector<int> cur ; 
        while (size--)
        {            
            Node *front = q1.front();
            cur.push_back(front->data);

            q1.pop();
            if(front->left!=NULL)
                q1.push(front->left);

            if(front->right!=NULL)
                q1.push(front->right);
        }
        levels.push_back(cur);
        
    }
    return levels ;
}



pair<int, int> shortestRange(Node *root) 
{
    // Your code goes here
    vector<vector<int>> levels = level_order_traversal(root);
    int n = levels.size();

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<endl;
    //     for (int j = 0; j < levels[i].size(); j++)
    //         cout<<" "<<levels[i][j];
    // }    

    set<pair<int,pair<int,int>>> s1;
    for (int i = 0; i < n; i++)
        s1.insert({levels[i][0] ,{i,0}});
    
    // cout<<endl ;
    // for(auto c : s1)
    //     cout<<c.first <<" ";
    // cout<<endl ;

    int min_val = ((s1.begin())->first);
    int max_val = ((--s1.end())->first);
    int ans1 = min_val, ans2 = max_val;
    while (!s1.empty())
    {
        pair<int,pair<int,int>> out = *(s1.begin())     ;
        s1.erase(s1.begin());
        if(out.second.second+1<levels[out.second.first].size())
        {
            int r = out.second.first , c = out.second.second+1 ;
            s1.insert({levels[r][c] , {r,c} });
            min_val = s1.begin()->first;
            max_val = (--s1.end())->first ;
            if(ans2-ans1>max_val-min_val)
            {
                ans2 = max_val ;
                ans1 = min_val ;
            }
            else if(ans2-ans1==max_val-min_val && min_val<ans1)
            {
                ans2 = max_val ;
                ans1 = min_val ;
            }
        }
        else 
            break ;
    }
    return {ans1,ans2};

}


int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);


    root->right->right = new Node(14);
    root->right->right->left = new Node(12);
    root->right->right->left->left = new Node(11);
    root->right->right->left->right = new Node(13);
    pair<int,int> p = shortestRange(root);
    cout<<endl<<p.first<<" "<<p.second ;
    return 0;
}