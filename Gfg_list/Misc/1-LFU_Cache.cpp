
// https://leetcode.com/problems/permutation-in-string/










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


struct Node
{
    int key , value , cnt ;
    Node *next , *prev ; 

    Node(int key_ , int value_)
    {
        key = key_ ;
        value = value_ ;
        cnt = 1 ; 
    }
};


struct DLL
{
    int size ; 
    Node *head , *tail ; 
    DLL()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail ;
        tail->prev = head ;
        size = 0 ;
    }
    void addFront(Node *newnode)
    {
        Node *temp = head->next ;
        newnode->next = temp ;
        newnode->prev = head ; 
        
        head->next = newnode ;
        temp->prev = newnode ; 
        size++ ;
    } 


    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev ; 
        Node *delnext = delnode->next ; 

        delprev->next = delnext ;
        delnext->prev = delprev ;
        size-- ;
    }



};



class LFUCache {
public:
    map<int,DLL*> freq_List ;
    map<int , Node*> hash_node ; 
    int capacity ;
    int min_freq ; 
    int cursize ; 
    LFUCache(int capacity) {
        this->capacity = capacity ;
        this->cursize = 0 ;
        this->min_freq = 0 ;
    }
    
    void updateFreqList(Node *node)
    {
        this->hash_node.erase(node->key);
        (this->freq_List[node->cnt])->removeNode(node);
        if(node->cnt == this->min_freq && this->freq_List[node->cnt]->size==0)
        {
            this->freq_List.erase(node->cnt);
            this->min_freq++ ;
            
        }
        
        DLL* nexthigherfreq = new DLL();
        if(this->freq_List.find(node->cnt+1)!=this->freq_List.end())
            nexthigherfreq = this->freq_List[node->cnt+1];
        node->cnt++ ;
        nexthigherfreq->addFront(node);
        this->freq_List[node->cnt] = nexthigherfreq ; 
        this->hash_node[node->key] = node ;
    }

    int get(int key) 
    {
        if(this->capacity==0)
            return -1 ;
        if(this->capacity==1)
        {
            if(hash_node.find(key)!=hash_node.end())    
                return hash_node[key]->value;
            return -1 ;
        }
        if(hash_node.find(key)!=hash_node.end())    
        {
            int val = (this->hash_node[key])->value;
            this->updateFreqList(this->hash_node[key]);
            return val ;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(capacity ==0)    
            return ;
        if(this->capacity==1)
        {
            this->hash_node.clear();
            this->hash_node[key] = new Node(key,value) ;
            return ; 
        }
        
        if(this->hash_node.find(key)!=this->hash_node.end())
        {
            Node* node = this->hash_node[key];
            node->value = value ; 
            this->updateFreqList(node);
        }
        else 
        {
            if(cursize==capacity)
            {
                DLL* newList = this->freq_List[this->min_freq];
                this->hash_node.erase(newList->tail->prev->key);//remove least recently used in smae freq 
                this->freq_List[this->min_freq]->removeNode(newList->tail->prev);
                this->cursize-- ;
            }
            this->cursize++ ;
            this->min_freq = 1 ; //new element 
            DLL* newlist = new DLL();
            if(this->freq_List.find(this->min_freq)!=this->freq_List.end())
                newlist = this->freq_List[this->min_freq];
            Node* node = new Node(key , value);
            newlist->addFront(node);
            this->freq_List[this->min_freq] = newlist ; 
            this->hash_node[key] = node ;
        }
    }
};



