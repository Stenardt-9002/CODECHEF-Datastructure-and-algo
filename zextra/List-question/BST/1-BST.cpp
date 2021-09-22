
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
            cout<<temp->data<<endl ; 
            temp = temp->right ; 

        }
        
    }
    
    
}





int main(int argc, char const *argv[])
{
    BST b, *root=NULL ;

    root = b.Insert1(root, 50);
    root = b.Insert1(root, 30);
    root = b.Insert1(root, 20);
    root = b.Insert1(root, 40);
    root = b.Insert1(root, 70);
    root = b.Insert1(root, 60);
    root = b.Insert1(root, 80);


    b.Inorder(root);
    // cout<<root->data;
    return 0;
}












