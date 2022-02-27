
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
    BST *Delete1(BST* ,int);
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


// BST* BST::Insert1( BST* root,int valuex)
// {
//     if (!root)
//     {
//         return new BST(valuex);
//     }
    
//     if (valuex>root->data)
//     {
//         root->right = Insert1(root->right,valuex);
//     }
//     else
//     {
//         root->left = Insert1(root->left,valuex);
//     }
    
//     return root ;


//     // data = valuex; left=right=NULL ;
// }

// #iterative 
BST* BST::Insert1( BST* root,int valuex)
{
    BST *temp1 = new BST(valuex);
    BST *temp2 = root ;
    BST *prev =NULL;

    if (temp2==NULL)
    {
        return temp1;
    }
    

    while (temp2!=NULL)
    {
        if (temp2->data>valuex)
        {
            prev = temp2 ;temp2 = temp2->left;
        }
         else
         {
             prev = temp2 ;temp2 = temp2->right;
         }
         
    }

    if (prev->data>valuex)
    {
        prev->left = temp1;
    }
    else
    {
        prev->right = temp1;        
    }
    // delete prev ;
    return root ;

    

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


BST* BST::Delete1( BST* root,int valuex) //all elements are distinct
{

    if (root==NULL)
    {
        return root ;
    }
    
    if (root->data>valuex)
    {
        root->left = Delete1(root->left , valuex); return root ;
    }
    else if (root->data<valuex)
    {
        root->right = Delete1(root->right , valuex); return root ;
    }
    //one children
    if (root->left==NULL && root->right==NULL )
    {
        return NULL ;   
    }
    else if (root->left==NULL )
    {
        BST *temp1 = root->right ; delete root ; return temp1 ;
    }
    
    else if (root->right==NULL )
    {
        BST *temp1 = root->left ; delete root ; return temp1 ;
    }
    
    //boht children exist 
    else
    {
        //go right once and then left till last 
        BST *temp1 = root ; 
        BST *curr = root->right ;

        while (curr->left!=NULL)
        {
            temp1 = curr ;
            curr = curr->left ;    
        }

        if (temp1!=root)
        {
            //left null 
            temp1->left = curr->right ; 
            cout<<"CHECK CASE WHEN REACH ;" ;
        }
        else
        {
            temp1->right = curr->right;
        }
        

        root->data = curr->data ; //data right and leftmost data        
        delete curr ; return root ;

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




    cout<<"\nInorder traversal \n";
    b.Inorder(root);
    cout<<endl;
    b.Preorder(root);
    cout<<"\nDelete 65 \n";
    root = b.Delete1(root,68);
    b.Inorder(root);
    cout<<endl;
    b.Preorder(root);
    // b.Inorder(root);
    // cout<<"\nDelete 70 \n";
    // root = b.Delete1(root,70);
    // b.Inorder(root);
    // cout<<root->data;
    return 0;
}









    // TreeNode* deleteNode(TreeNode* root, int key) 
    // {
    //     if(root==NULL)    
    //     {
    //         return NULL ;
            
    //     }
    //     if(root->val>key)
    //     {
    //         root->left = deleteNode(root->left , key);return root ;
    //     }
    //     else if(root->val<key)
    //     {
    //         root->right = deleteNode(root->right,key);return root ; 
    //     }
        
    //     if(root->left == NULL && root->right == NULL )
    //     {
    //         return NULL ;
    //     }
    //     else if(root->left == NULL )
    //     {
    //         TreeNode *temp1 = root->right ; delete root; return temp1;
    //     }
    //     else if(root->right == NULL )
    //     {
    //         TreeNode *temp1 = root->left ; delete root; return temp1;
    //     }
    //     else
    //     {
    //         //two childrem
    //         TreeNode *prev = root ;
    //         TreeNode *curr = root->right;
    //         while(curr->left!=NULL)
    //         {
    //             prev = curr ;
    //             curr = curr->left ;
    //         }
    //         if(root==prev)
    //         {prev->right = curr->right ; }
    //         else
    //         {prev->left = curr->right ;}
            
    //         root->val = curr->val ;// curr delete 
    //             delete curr ; return root ;
            
    //     }
        
    // }



struct Node
{
    int data ;Node *left,*right ;
    Node(int val)
    {
        data = val;left=right =NULL;
    }
};



Node *deleteNode(Node *root, int X) 
{
    if(root==NULL)
    {
        return NULL ;
    }
    
    if(root->data>X){root->left = deleteNode(root->left,X) ;return root ;}
    else if(root->data<X){root->right = deleteNode(root->right,X) ;return root ;} 
    
    if(root->left==NULL && root->right==NULL )    {return NULL ;}
    else if(root->left==NULL){ Node *temp1 = root->right ;delete root ; return temp1 ; }
    else if(root->right==NULL){ Node *temp1 = root->left ;delete root ; return temp1 ; }
    else
    {
        //two children inorder successor
        Node *orig = root ;
        
        Node *temp1 = root->right ;
        while(temp1->left!=NULL)
        {
            root = temp1;
            temp1= temp1->left ;
        }
        // data swap 
        
        if(root!=orig)
        {
            root->left = temp1->right ;
        }
        else
        {
            root->right = temp1->right;
        }
        orig->data = temp1->data ;
        delete temp1;
        // int data1 = orig->data ;
        // orig->data = temp1->data ;
        // temp1->data = data1;
        
        // root->left = deleteNode(root->left,X);
        return orig ;
    }
    
    









