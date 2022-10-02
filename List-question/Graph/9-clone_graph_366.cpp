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





Node* cloneGraph(Node* node) 
{
        if(node==NULL)
            return NULL ;
        map<Node*,Node*>m1ap ;
        queue<Node *> q1 ;

        q1.push(node);
        Node *temp1 ;
        temp1 = new Node(node->val);

        m1ap[node] = temp1;

        while (!q1.empty())
        {//bfs
            Node *temp2 = q1.front();
            q1.pop();
            for ( auto i : temp2->neighbors)
            {
                if (m1ap[i]==NULL)
                {
                    temp1 = new Node(i->val);
                    m1ap[i] = temp1 ;
                    q1.push(i);

                }
                    m1ap[temp2]->neighbors.push_back(m1ap[i]);
            }
        }
        return m1ap[node];
}


