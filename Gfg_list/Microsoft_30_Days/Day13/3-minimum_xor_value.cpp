


//https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day13/problem/minimum-xor-value-pair









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




/*

class Node
{
public:
    Node *links[2]   ;
    bool end_flag= false ;
    Node *get(bool c)
    {
        return links[c];
    }
    void put(bool key , Node *node )
    {
        this->links[key] = node ;
    }
    bool containskey(bool key)
    {
        return this->links[key]!=NULL ;
    }
    void end()
    {
        this->end_flag = true ;
    }
    bool get_flag()
    {
        return this->end_flag ;
    }
};




class Trie 
{
    public:
    Node *root ;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *traversal = this->root ;
        for (int i1 = 31; i1 >=0; i1--)
        {
            bool bit = (num>>i1)&1 ;
            if(!traversal->containskey(bit))
                traversal->put(bit, new Node());

            traversal = traversal->get(bit);
        }
        
        // while(num)
        // {
        //     int remainder = num%2;
        //     if(!traversal->containskey(remainder))
        //         traversal->put(remainder, new Node());

        //     traversal = traversal->get(remainder);
        //     num/=2 ;
        // }
        // traversal->end();
    }
    int minimum_xor(int val )
    {
        Node *traversal = this->root ;
        int ans1 = 0 ;
        for (int i1 = 31; i1 >=0; i1--)
        {
            bool bit = (val>>i1)&1 ;
            if(traversal->containskey(bit))//minimised
            {
                ans1|= (1<<i1);
                traversal = traversal->get(bit);
            }
            else 
                traversal = traversal->get(1-bit);
        }
        return ans1 ;
    }

};


void dfs_util(Node *n1 , string current_stack ,vector<string> &ans1)
{
    if(n1->containskey(0))
        dfs_util(n1->get(0),current_stack+"0",ans1);
    else if(n1->containskey(1))
        dfs_util(n1->get(1),current_stack+"1",ans1);
    else 
        ans1.push_back(current_stack);

    return ;
}


void void_debug(Trie *mainroot)
{
    vector<string>ans1 ;
    string current_stack = "";
    dfs_util(mainroot->root , current_stack ,ans1);
    cout<<"\nDEUG1\n\n";
    for(auto x : ans1)
        cout<<x<<endl ;

    cout<<"DEUG2\n";
    
}


int minxorpair(int N, int arr[])
{    
    //code here
    if(N==1)
        return 0 ;
    Trie *mainroot = new Trie();
    mainroot->insert(arr[0]);
    int ans1 = INT_MAX ;
    for (int i1 = 1; i1 < N; i1++)
    {
        void_debug(mainroot);
        ans1 = min(ans1 , mainroot->minimum_xor(arr[i1]));
        mainroot->insert(arr[i1]);
    }
    void_debug(mainroot);

    return ans1 ;
}


*/


class Node
{
public:
    Node *links[2]   ;
    bool end_flag= false ;
    Node *get(bool c)
    {
        return links[c];
    }
    void put(bool key , Node *node )
    {
        this->links[key] = node ;
    }
    bool containskey(bool key)
    {
        return this->links[key]!=NULL ;
    }
    void end()
    {
        this->end_flag = true ;
    }
    bool get_flag()
    {
        return this->end_flag ;
    }
};




class Trie 
{
    Node *root ;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *traversal = this->root ;
        for (int i1 = 31; i1 >=0; i1--)
        {
            bool bit = (num>>i1)&1 ;
            if(!traversal->containskey(bit))
                traversal->put(bit, new Node());

            traversal = traversal->get(bit);
        }
        
        // while(num)
        // {
        //     int remainder = num%2;
        //     if(!traversal->containskey(remainder))
        //         traversal->put(remainder, new Node());

        //     traversal = traversal->get(remainder);
        //     num/=2 ;
        // }
        // traversal->end();
    }
    int minimum_xor(int val )
    {
        Node *traversal = this->root ;
        int ans1 = 0 ;
        for (int i1 = 31; i1 >=0; i1--)
        {
            bool bit = (val>>i1)&1 ;
            if(traversal->containskey(bit))//minimised
            {
                // ans1|= (1<<i1);
                traversal = traversal->get(bit);
            }
            else 
            {
                ans1|= (1<<i1);
                traversal = traversal->get(1-bit);
            }
        }
        return ans1 ;
    }

};








int minxorpair(int N, int arr[])
{
    
    if(N==1)
    return 0 ;
    Trie *mainroot = new Trie();
    mainroot->insert(arr[0]);
    int ans1 = INT_MAX ;
    for (int i1 = 1; i1 < N; i1++)
    {
        ans1 = min(ans1 , mainroot->minimum_xor(arr[i1]));
        mainroot->insert(arr[i1]);
    }
    return ans1 ;

    
    //code here
}

int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n ;
        cin>>n ;
        int *arr1 = new int[n];
        for (int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1];
        
        minxorpair(n, arr1);
        delete []arr1 ;
    }


    return 0;
}





