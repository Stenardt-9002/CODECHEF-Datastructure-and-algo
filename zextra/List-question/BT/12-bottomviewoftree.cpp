#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;


struct Node
{
    int data ; struct Node* left ; struct Node* right ;
};


Node* newNode(int val)
{
    Node* temp1 = new Node ;
    temp1->data = val ;
    temp1->left = NULL ;
    temp1->right = NULL ;

    return temp1 ;

}




vector<int> bottomView(Node* root)
{
    if (root==NULL)
    {
        return {};
    }
        vector<int> asnwer ;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        map<int,int> m1 ; //mapping left right distance with first node encounterd

        Node* temp1 ;
        int inithd = 0;
        while (q.size())
        {
            temp1 = q.front().first;
            inithd = q.front().second;

            // if (m1.count(inithd)==0)
            // {
                m1[inithd] = temp1->data  ;
            // }
            if (temp1->left)
            {
                q.push(make_pair(temp1->left,inithd-1));
            }

            if (temp1->right)
            {
                q.push(make_pair(temp1->right,inithd+1));
            }
            
            
            q.pop();

        }
        for (auto i1 = m1.begin(); i1 != m1.end(); i1++)
        {
            asnwer.push_back(i1->second);
        }
        
        
    return asnwer;




}






int main(int argc, char const *argv[])
{

    Node* tree1 = newNode(10);
    tree1->left = newNode(20) ;
    tree1->right = newNode(30) ;
    tree1->left->left = newNode(40) ;
    tree1->left->right = newNode(60) ;





    // Node* tree1 = newNode(20);
    // tree1->left = newNode(8) ;
    // tree1->right = newNode(22) ;
    // tree1->left->left = newNode(4) ;
    // tree1->left->right = newNode(12) ;
    // tree1->left->right->left = newNode(10) ;tree1->left->right->right = newNode(14) ;
    // tree1->right->right = newNode(25) ;

    vector<int> asnwer = bottomView(tree1);
    cout<<endl;
    for (int i1 = 0; i1 < asnwer.size(); i1++)
    {
        cout<<asnwer[i1]<<" ";
    }
    




    return 0;
}














