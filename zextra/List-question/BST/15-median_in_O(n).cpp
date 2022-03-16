



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//morris 

int get_Nodes(Node *root)
{

    Node *cur,*pre ;
    cur = root ;
    int count1 = 0;

    while (cur!=NULL)
    {
        if (cur->left==NULL)
        {
            //data 
            count1++;
            cur = cur->right ;
        }
        else
        {
            pre = cur->left ;

            while (pre->right!=NULL && pre->right!=cur)
                pre = pre->right ;

            if (pre->right==NULL)
            {
                pre->right = cur ;
                cur = cur->left ;
            }
            else
            {
                //break connection 
                pre->right = NULL ;
                //data 
                count1++;
                cur = cur->right ;

            }
        }
    }
    return count1 ;


}

float Median_Util(Node *root , int n)
{
    Node *cur,*pre ;
    // cout<<"  DEBUG\n"<<n;
    Node *prev =NULL; //for median of even nodes
    cur = root ;
    int count1 = 0;
    float ans  ;
    while (cur!=NULL)
    {
        if (cur->left==NULL)
        {
            //data 
            count1++;

            if (n%2==0 && count1==(n/2)+1)
                return ((float)(prev->data + cur->data))/2;
            
            else if(n%2!=0 && count1==(n+1)/2)
                return cur->data;

            prev = cur ;
            cur = cur->right ;
        }
        else
        {
            pre = cur->left ;
            
            while (pre->right!=NULL && pre->right!=cur)
                pre = pre->right ;

            if (pre->right==NULL)
            {
                pre->right = cur ;
                cur = cur->left ;
            }
            else
            {
                //break connection 
                pre->right = NULL ;
                prev = pre ;
                //data 
                count1++;
                if (n%2==0 && count1==(n/2)+1)
                    return ((float)(prev->data + cur->data))/2;
                
                else if(n%2!=0 && count1==(n+1)/2)
                    return cur->data;

                prev = cur ;
                cur = cur->right ;
            }
        }
    } 
    return -1;
}


float findMedian(struct Node *root)
{
      int n = get_Nodes(root);
      float ans1 = Median_Util(root,n);
      return ans1 ;
}
   
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) return new Node(key);
  
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
  
    return node;
}
  

int main(int argc, char const *argv[])
{

    Node *root = NULL ;


    root = insert(root,12);
    root = insert(root,6);
    root = insert(root,3);

    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,11);
    root = insert(root,18);
    root = insert(root,15);
    root = insert(root,13);
    root = insert(root,20);


    cout<<findMedian(root);


    return 0;
}




