
// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day12/problem/a512e4b2e812b6df2159b19cc7090ffc1ab056dd



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;






class Node
{

};


class Trie
{
    public :
    Node* root ;
    Trie()
    {
        root= new Node();
    }


    void insert(int num)
    {
        Node *temp = root ;
        for (int i1 = 31; i1 >=0; --i1)
        {
            int val = (num>>i1)&(1);
            if(!temp->containskey(val))
                temp->put(val,new Node());

            temp = temp->get(val);
        }
        // temp->end_fun();//reached end
    }
    int check_max_xor(int num)
    {
        int ans1 = 0;
        Node *temp = this->root ;
        for (int i = 31; i >=0; --i)
        {
            bool var = (num>>i)&1;
            if(temp->containskey(1-var))
            {
                ans1|=(i<<i);//this will make ans one
                temp = temp->get(1-var);
            }
            else 
                temp = temp->get(var);
                
        }
        
        //trial to get maximum value //always get opposite value
        return ans1 ;
    }

};




#define INT_SIZE 32

class Node
{
    public:
	int value; 
    Node *links[2];
    Node()
    {
        this->links[0] = NULL ;
        this->links[1] = NULL ;
        this->value =0;
    }
    bool containskey(int key)
    {
        return this->links[key]!=NULL;
    }
    void put(int key , Node *node)
    {
        this->links[key] = node ;
    }
    Node *get(int key)
    {
        return this->links[key];
    }
    // void end_fun()
    // {
    //     this->end = true ;
    // }
};


class Trie
{
    public :
    Node* root ;
    Trie()
    {
        root= new Node();
    }


    void insert(int num)
    {
        Node *temp = root;

        for (int i=INT_SIZE-1; i>=0; i--)
        {
            bool val = num & (1<<i);

            if (!temp->containskey(val))
                temp->put(val , new Node());

            temp = temp->links[val];
        }

        temp->value = num;
    }
    int check_max_xor(int num)
    {
        int ans1 = 0;
        Node *temp = this->root ;
        for (int i = 31; i >=0; --i)
        {
            bool var = (num>>i)&1;
            if(temp->containskey(1-var))
            {
                ans1|=(i<<i);//this will make ans one
                temp = temp->get(1-var);
            }
            else 
                temp = temp->get(var);
                
        }
        
        //trial to get maximum value //always get opposite value
        return ans1 ;
    }

};


// void insert(TrieNode *root, int pre_xor)
// {

// }

// int query(TrieNode *root, int pre_xor)
// {
// 	TrieNode *temp = root;
// 	for (int i=INT_SIZE-1; i>=0; i--)
// 	{
// 		bool val = pre_xor & (1<<i);
// 		if (temp->arr[1-val]!=NULL)
// 			temp = temp->arr[1-val];

// 		else if (temp->arr[val] != NULL)
// 			temp = temp->arr[val];
// 	}
// 	return pre_xor^(temp->value);
// }





    int maxSubarrayXOR(int N, int arr[])
    {    
        //code here
    	Trie *root = new Trie();
    	root->insert(0);
    	int ans1 = INT_MIN, pre_xor =0;
    
    	for (int i=0; i<N; i++)
    	{
    
    		pre_xor = pre_xor^arr[i];
    		root->insert(pre_xor);
    		ans1 = max(ans1, root->check_max_xor(pre_xor));
    	}
    	return ans1;
    }
