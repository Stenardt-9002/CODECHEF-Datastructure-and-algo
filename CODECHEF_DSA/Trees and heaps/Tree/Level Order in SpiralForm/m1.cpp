

#include <iostream>

using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;

};




struct node* newNode(int daat)
{
  struct node* node1 = (struct node*)malloc(sizeof(struct node));
  node1->right = node1->left = NULL;
  node1->data = daat;
  return node1;
}

int height(struct node* node)
{
  if (node==NULL)
  {

    return 0;
  }

  else
  {
    int lheight = height(node->left);int rheight = height(node->right);
    if (lheight>rheight)
    {
      return lheight+1;
    }
    else
    {
      return rheight+1;

    }
  }
}

void printparticularlevle(struct node* root,int level,bool reevrse)
{
  if (root==NULL)
  {
    return;
  }
  if (level==1)
  {
    // 1 st lelev
    std::cout << root->data<<" " ;
  }

  else if (level>1)
  {
    if (reevrse)
    {
      printparticularlevle(root->left,level-1,reevrse);
      printparticularlevle(root->right,level-1,reevrse);

    }
    else
    {
      printparticularlevle(root->right,level-1,reevrse);
      printparticularlevle(root->left,level-1,reevrse);



    }

  }


}



void printShit(struct node* rootnode)
{
  int heghtirot = height(rootnode);

  bool reevrse = true;
  for (int i1 = 0; i1 <=heghtirot; i1++)
  {
    printparticularlevle(rootnode,i1,reevrse);
    reevrse = !reevrse;



  }



}






int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printShit(root);
    free(root);
    return 0;
}
