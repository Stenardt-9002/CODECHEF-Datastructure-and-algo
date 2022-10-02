
// #insert BST 


#include<iostream>
#include<stack>



using namespace std;
class BST
{
private:


public:
    int data ; BST *left , *right ;

    BST();

    BST(int);
    BST *Insert1(BST* ,int);


    void Inorder(BST*);
    void Preorder(BST*);


};

BST::BST()
{
    data = 0; left=right=NULL ;
}
BST::BST( int valuex)
{
    data = valuex; left=right=NULL ;
}

BST* BST::Insert1( BST* root,int valuex)
{
    if (!root)
    {
        return new BST(valuex);
    }
    
    if (valuex>root->data)
    {
        root->right = Insert1(root->right,valuex);
    }
    else
    {
        root->left = Insert1(root->left,valuex);
    }
    
    return root ;


    // data = valuex; left=right=NULL ;
}

// void BST :: Inorder(BST* root)
// {
//     if (!root)
//     {
//         return ; 
//     }
//     Inorder(root->left); cout<<root->data<<endl ; Inorder(root->right);
    
// }
void BST :: Preorder(BST* root)
{
    if (!root)
    {
        return ; 
    }
    Preorder(root->left);  Preorder(root->right);cout<<root->data<<" " ;
    
}


// #iterative inorder 
void BST :: Inorder(BST* root)
{
    stack<BST *> st1;
    BST *temp = root ;
    while (temp!=NULL || !st1.empty())
    {
        if (temp!=NULL)
        {
            st1.push(temp) ; temp= temp->left ;
        }
            
        else
        {
            temp = st1.top();st1.pop();
            cout<<temp->data<<" " ; 
            temp = temp->right ; 

        }
        
    }
    
    
}
void findPreSuc(BST* root, BST*& pre, BST*& suc, int key)
{

// Your code goes here
if(root==NULL){return ;}

    if(root->data>key)
    {
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else if(root->data<key)
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
    else
    {
        //key match
        if(root->left!=NULL)
        {
            BST *temp1 = root->left ;
            while(temp1->right!=NULL)
            {
                temp1=temp1->right;
            }
            pre = temp1 ;
        
        }

        if(root->right!=NULL)
        {
            BST *temp1 = root->right ;
            while(temp1->left!=NULL)
            {
                temp1=temp1->left;
            }
            suc = temp1 ;
        
        }
        return ;
        
    }


}




int main(int argc, char const *argv[])
{
    BST b, *root=NULL ;

    // root = b.Insert1(root, 50);
    // root = b.Insert1(root, 30);
    // root = b.Insert1(root, 20);
    // root = b.Insert1(root, 40);
    // root = b.Insert1(root, 70);
    // root = b.Insert1(root, 60);
    // root = b.Insert1(root, 80);



    root = b.Insert1(root, 60);
    root = b.Insert1(root, 55);
    root = b.Insert1(root, 70);
    root = b.Insert1(root, 53);
    root = b.Insert1(root, 58);
    root = b.Insert1(root, 68);
    root = b.Insert1(root, 65);
    root = b.Insert1(root, 69);

  BST* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, 15);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";


    cout<<"\nInorder traversal \n";
    b.Inorder(root);
    cout<<endl;

    return 0;
}







