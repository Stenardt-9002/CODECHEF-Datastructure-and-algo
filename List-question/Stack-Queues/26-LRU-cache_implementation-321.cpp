
// https://practice.geeksforgeeks.org/problems/lru-cache/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
#include<list>
#include<unordered_map>
#include<tuple>
using namespace std;






//This function Did not pass  on leetcode //gave TLE
// class LRUCache
// {


//     public:
//     list<pair<int,int>> deque1 ;    //key ,value
//     //dictionary
//     unordered_map<int,list<pair<int,int>>::iterator> hashma1;
//     int n ;

//     LRUCache(int cap)
//     {
//         this->n=cap ;
//     }
    
//     //Function to return value corresponding to the key.
//     int get(int key)
//     {
//         // your code here
//         if (this->hashma1.find(key)==this->hashma1.end())
//             return -1 ; //not present

//         list<pair<int,int>>::iterator itr1 = this->hashma1[key];
//         pair<int,int> temp1 = *itr1; 

//         this->deque1.erase(this->hashma1[key]);
//         this->deque1.push_front(temp1); //latest used in front 
//         this->hashma1[key] = this->deque1.begin() ;//update hashmap
//         return temp1.second ;

//     }
    
//     //Function for storing key-value pair.
//     void set(int key, int value)
//     {
//         //not present 
//         pair<int,int> temp1 ; 
//         if (this->hashma1.find(key)==this->hashma1.end())
//         {//remove least recently used
//             if (this->deque1.size()==this->n)
//             {
//                 temp1 = this->deque1.back() ; //last used 
//                 this->deque1.pop_back() ;
//                 this->hashma1.erase(temp1.first);
//             }
            
//         }
//         else
//             this->deque1.erase(this->hashma1[key]) ;//remove the key


//         //now update value 
//         this->deque1.push_front(make_pair(key,value)); //latest used in front 
//         this->hashma1[key] = this->deque1.begin() ;
//     }
// };


//A better soln : passed on leetcode 

class LRUCache
{


    public:
    list<pair<int,int>> deque1 ;    //key ,value
    //dictionary
    unordered_map<int,list<pair<int,int>>::iterator> hashma1;
    int n ;

    LRUCache(int cap)
    {
        this->n=cap ;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        auto pos = this->hashma1.find(key) ;
        if (pos==this->hashma1.end())
            return -1 ; //not present

        this->deque1.splice(this->deque1.begin(),this->deque1,pos->second) ;
        return pos->second->second  ;//value

    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        //not present 
        auto pos = this->hashma1.find(key) ;

        if (pos!=this->hashma1.end())
        {//remove least recently used
            this->deque1.splice(this->deque1.begin(),this->deque1,pos->second) ;
            pos->second->second = value ;
            return ;
        }
        if (this->deque1.size()==this->n)
        {
            int dele_key = this->deque1.back().first ;
            this->deque1.pop_back() ;
            this->hashma1.erase(dele_key) ;
        }
        this->deque1.emplace_front(key,value);
        this->hashma1[key] = this->deque1.begin();
    }
};


