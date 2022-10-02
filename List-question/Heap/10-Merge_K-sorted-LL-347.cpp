
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
//tle in priorirty queue
// Node * mergeKLists(Node *arr[], int K)
// {
//         // Your code here
//         priority_queue<tuple<int,Node *>,vector<tuple<int,Node *>>,greater<tuple<int,Node *>>> heap1;
//     for (int i1 = 0; i1 < K; i1++)
//         heap1.push(make_tuple(arr[i1]->data,arr[i1]->next))    ;
    
//     Node *head1 = NULL ;

//     tuple<int,Node *> temp1 = heap1.top() ;
//     heap1.pop();
//     head1 = new Node(get<0>(temp1));
//     Node *cur1 = head1 ;

//     Node *next_ptr = get<1>(temp1);
//     if(next_ptr!=NULL)
//         heap1.push(make_tuple(next_ptr->data,next_ptr->next));

//     while (!heap1.empty())
//     {
//         temp1 = heap1.top() ;
//         heap1.pop();
//         cur1->next = new Node(get<0>(temp1));
//         cur1 = cur1->next ;
//         next_ptr = get<1>(temp1);
//         if(next_ptr!=NULL)
//             heap1.push(make_tuple(next_ptr->data,next_ptr->next));
//     }
//     return head1 ;
// }




/* WORKING dont use set because repeated values not stored */

Node * mergeKLists(Node *arr[], int K)
{
        // Your code here
        // set<tuple<int,Node *>> heap1;
            multiset<tuple<int,Node *>> heap1;
            for (int i1 = 0; i1 < K; i1++)
                heap1.insert(make_tuple(arr[i1]->data,arr[i1]->next))    ;
            
            Node *head1 = NULL ;
        
            tuple<int,Node *> temp1 = *heap1.begin()  ;
            heap1.erase(heap1.begin());
            head1 = new Node(get<0>(temp1));
            Node *cur1 = head1 ;
        
            Node *next_ptr = get<1>(temp1);
            if(next_ptr!=NULL)
                heap1.insert(make_tuple(next_ptr->data,next_ptr->next));
        
            while (!heap1.empty())
            {
                temp1 = *heap1.begin() ;
                heap1.erase(heap1.begin());
                cur1->next = new Node(get<0>(temp1));
                cur1 = cur1->next ;
                next_ptr = get<1>(temp1);
                if(next_ptr!=NULL)
                    heap1.insert(make_tuple(next_ptr->data,next_ptr->next));
            }
            return head1 ;
}


bool colmpar1(tuple<int,Node *> a1, tuple<int,Node *> b1)
{
    return get<0>(a1)>get<0>(b1);
}

//even this is getting TLE
// Node * mergeKLists(Node *arr[], int K)
// {
//         // Your code here
//         // set<tuple<int,Node *>> heap1;
//     deque<tuple<int,Node *>> heap1;
//     // vector<tuple<int,Node *>> heap1;


//     for (int i1 = 0; i1 < K; i1++)
//         heap1.emplace_back(make_tuple(arr[i1]->data,arr[i1]->next))    ;
    
//     make_heap(heap1.begin(),heap1.end(),colmpar1);


//     // for (auto x: heap1)
//     // {
//     //     tuple<int,Node *> tem1 = x;
//     //     cout<<" "    <<get<0>(tem1);
//     // }

//     // cout<<endl;
//     // pop_heap(heap1.begin(),heap1.end(),colmpar1);
//     // heap1.pop_back();
//     // for (auto x: heap1)
//     // {
//     //     tuple<int,Node *> tem1 = x;
//     //     cout<<" "    <<get<0>(tem1);
//     // }

//     // cout<<endl;
//     Node *head1 = NULL ;

//     // tuple<int,Node *> temp1 = *heap1.begin()  ;
//     tuple<int,Node *> temp1 = heap1.front()  ;

//     // std::pop_heap(heap1.front(),heap1.end(),colmpar1);
//     pop_heap(heap1.begin(),heap1.end(),colmpar1);
//     heap1.pop_back();

//     // heap1.erase(heap1.begin());
//     head1 = new Node(get<0>(temp1));
//     Node *cur1 = head1 ;

//     Node *next_ptr = get<1>(temp1);
//     if(next_ptr!=NULL)
//         {
//             heap1.emplace_back(make_tuple(next_ptr->data,next_ptr->next));
//             push_heap(heap1.begin(),heap1.end(),colmpar1);
//         }

//     while (!heap1.empty())
//     {
//         // temp1 = *heap1.begin() ;
//         temp1 = heap1.front() ;
//         pop_heap(heap1.begin(),heap1.end(),colmpar1);
//         heap1.pop_back();
//         // heap1.erase(heap1.begin());
//         cur1->next = new Node(get<0>(temp1));
//         cur1 = cur1->next ;
//         next_ptr = get<1>(temp1);
//         if(next_ptr!=NULL)
//         {   
//             heap1.emplace_back(make_tuple(next_ptr->data,next_ptr->next));
//             push_heap(heap1.begin(),heap1.end(),colmpar1);
//         }
//     }
//     return head1 ;
// }

int main(int argc, char const *argv[])
{
    int K = 4;
    Node *temp1 = new Node(1);
    temp1->next = new Node(2);
    temp1->next->next = new Node(3);


    Node *temp2 = new Node(4);
    temp2->next = new Node(5);
    
    Node *temp3 = new Node(5);
    temp3->next = new Node(6);

    Node *temp4 = new Node(7);
    temp4->next = new Node(8);

    Node* arr1[] = {temp1,temp2,temp3,temp4};

    mergeKLists(arr1,K);
    return 0;
}



