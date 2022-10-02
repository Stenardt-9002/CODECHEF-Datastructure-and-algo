#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>


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

// # not using dictionary 

vector<int> topview(Node* root)
{
    if (root==NULL)
        return {};

        vector<int> asnwer ;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        Node* temp1 ;
        int inithd = 0,l=0,r=0;
        vector<int> rightsideanswer ; 
        stack<int> leftsideanswer ;
        rightsideanswer.push_back(root->data);//this is at centre
        while (q.size())
        {
            temp1 = q.front().first;
            inithd = q.front().second;

            if (inithd<l)
            {
                leftsideanswer.push(temp1->data);
                l = inithd;
            }
            if (inithd>r)
            {
                rightsideanswer.push_back(temp1->data);
                r = inithd;
            }
            
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

        while (leftsideanswer.size())
        {
            asnwer.push_back(leftsideanswer.top())    ;leftsideanswer.pop();
        }
        
        for (auto i1 = rightsideanswer.begin(); i1 != rightsideanswer.end(); i1++)
        {
            asnwer.push_back(*i1);
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



    vector<int> asnwer = topview(tree1);
    cout<<endl;
    for (int i1 = 0; i1 < asnwer.size(); i1++)
    {
        cout<<asnwer[i1]<<" ";
    }
    










    return 0;
}






