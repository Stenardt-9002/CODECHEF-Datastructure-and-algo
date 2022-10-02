#include<iostream>
#include<string>


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int max1, max2;
   max1 = std::max(n1,n2);
   max2 = std::min(n1,n2);
   n1 = max1;n2 = max2;
   
   if(root==NULL)
   {return NULL;}
   //all different elements
   if(root->data>n1 && root->data>n2)
   {
       return LCA(root->left,n1,n2);
   }
   else if(root->data<n1 && root->data<n2)
   {
       return LCA(root->right,n1,n2);
   }
   return root;
   
   
}

int main(int argc, char const *argv[])
{
    int testcaes ; 
    scanf("%d",&testcaes);
    string str11;
    
    while (testcaes--)
    {
        int left_heght,


    }
    

    
    return 0;
}



