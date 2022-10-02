#include <iostream>
#include <vector>
#include <map>
using namespace std;




struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode1(int daat)
{
  Node* n1 = new Node;
  n1->data = daat;
  n1->left = NULL;
  n1->right = NULL;
  return n1;
}




class Treeeeee
{
public:

// std::map<int, int> mapinfo;
map < int,vector<int> > mapinfo;

  // Treeeeee (arguments);
  void create_vectr(Node *r1oot,int gert)
  {
    if (r1oot==NULL)
    {
      return;
    }
    // if (mapinfo.find(gert)==mapinfo.end())
    // {
    //   mapinfo[gert] = r1oot.data;
    // }
      mapinfo[gert].push_back(r1oot->data);

    create_vectr(r1oot->left,gert-1);
    create_vectr(r1oot->right,gert+1);

  }

  void print_Ver(Node* root1)
  {
    create_vectr(root1,0);
    for (auto got1 = mapinfo.begin(); got1 != mapinfo.end(); got1++)
    {
      for (int ij1 = 0; ij1 < got1->second.size(); ij1++)
      {
        cout<<got1->second[ij1]<<" ";
      }
      std::cout  << '\n';
    }
  }


  // virtual ~Treeeeee ();
};

// void create_vectr(Node *root,int gert,map<int,int>)





int main(int argc, char const *argv[])
{
  Node *root = newNode1(1);
    root->left = newNode1(2);
    root->right = newNode1(3);
    root->left->left = newNode1(4);
    root->left->right = newNode1(5);
    root->right->left = newNode1(6);
    root->right->right = newNode1(7);
    root->right->left->right = newNode1(8);
    root->right->right->right = newNode1(9);
    cout << "Vertical order traversal is n";
    Treeeeee n1 ;//= new Treeeeee();
    n1.print_Ver(root);

  return 0;
}
