// https://leetcode.com/problems/clone-graph/


#include<bits/stdc++.h>
using namespace std;




class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



Node* dfs_util(Node* node,map<Node*,Node*> &m1ap) 
{
    vector<Node*> neighbour ;
    Node* temp1 = new Node(node->val);
    m1ap[node] = temp1;

    for (auto i : node->neighbors )
    {
        if (m1ap[i]==NULL)
        {
            neighbour.push_back(dfs_util(i,m1ap));
        }
        else
        {
            neighbour.push_back(m1ap[i]);
        }
        temp1->neighbors = neighbour;
    }
    return temp1;
}



Node* cloneGraph(Node* node) 
{

    if(node==NULL)
        return NULL ;
    map<Node*,Node*>m1ap ;

    if (node->neighbors.size()==0)
    {
        Node* clone = new Node(node->val);
        return clone ;
    }
    
    return dfs_util(node,m1ap);
}




