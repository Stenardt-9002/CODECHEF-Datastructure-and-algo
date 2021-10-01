// // #using priority queue

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;


// struct MinHeapNode {

// 	char data;unsigned freq;
// 	struct MinHeapNode *left, *right;
//     MinHeapNode(char data, unsigned freq)
//     {
 
//         left = right = NULL;
//         this->data = data;
//         this->freq = freq;
//     }

// };

// struct compate {
// 	bool operator()(MinHeapNode* l, MinHeapNode* r)
// 	{
// 		return (l->freq > r->freq);
// 	}
// };

// void printCodes(struct MinHeapNode *var1,string str)
// {
// 	if (!var1)
// 	{
// 		return ;
// 	}

// 	if (var1->data!='$')
// 	{
// 		cout<<var1->data<<":"<<str<<endl ;

// 	}
// 	printCodes(var1->left,str+"0");
// 	printCodes(var1->right,str+"1");

// }


// void HuffmanCode(char data[],int freq[],int size)
// {
// 	struct MinHeapNode *left,*right,*top;

// 	priority_queue<MinHeapNode*,vector<MinHeapNode*>,compate > minHeap ;

// 	for (int i1 = 0; i1 < size; i1++)
// 	{
// 		minHeap.push(new MinHeapNode(data[i1],freq[i1])) ; // nodes of each char freq 
// 	}
// 	while (minHeap.size()!=1)
// 	{
// 		//until you done 
// 		left = minHeap.top();//lowest value //min Heap
// 		minHeap.pop();
// 		right = minHeap.top();//lowest value //min Heap
// 		minHeap.pop();

// 		top = new MinHeapNode('$',left->freq+right->freq);
// 		top->left = left ; top->right = right ;
// 		minHeap.push(top);// automatic in min Heap 

// 	}
	
// 	printCodes(minHeap.top() ,"");

// }























// int main()
// {
 
//     char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//     int freq[] = { 5, 9, 12, 13, 16, 45 };
 
//     int size = sizeof(arr) / sizeof(arr[0]);
 
//     HuffmanCode(arr, freq, size);
 
//     return 0;
// }


class Solution{
	public:
	struct MinHeapNode {

    	char data;unsigned int freq;
    	struct MinHeapNode *left, *right;
        // MinHeapNode(char data, unsigned freq)
        // {
     
        //     left = right = NULL;
        //     this->data = data;
        //     this->freq = freq;
        // }
        
        };
        
        MinHeapNode* cont(char data, unsigned int freq)
        {
            MinHeapNode *var1 ;
            var1->left = var1->right = NULL;
            var1->data = data;
            var1->freq = freq;
            return var1;
        }


        
    struct compate {
    	bool operator()(MinHeapNode* l, MinHeapNode* r)
    	{
    		return (l->freq > r->freq);
    	}
        };
    
    // void printCodes(struct MinHeapNode *var1,string str,vector<string> &finalanswer)
    void printCodes(struct MinHeapNode *var1,string str)
        {
        	if (!var1)
        	{
        		return ;
        	}
        
        	if (var1->data!='$')
        	{
        		cout<<var1->data<<":"<<str<<endl ;
        // 		finalanswer.push_back(var1->data+" : "+str);
        
        	}
        	printCodes(var1->left,str+"0");//,finalanswer);
        	printCodes(var1->right,str+"1");//,finalanswer);
        
        }




		vector<string> huffmanCodes(string data,vector<int> freq,int size)
        {
            vector<string> answer1 ;
			cout<<"DEBUG1";
        	struct MinHeapNode *left,*right,*top;
            //  MinHeapNode* cont(char , unsigned );
        
        	priority_queue<MinHeapNode*,vector<MinHeapNode*>,compate > minHeap ;
            MinHeapNode *tempvar ;
        	for (int i1 = 0; i1 < size; i1++)
        	{
        	    tempvar = cont(data[i1],freq[i1]);
        	    minHeap.push(tempvar);
        // 		minHeap.push(new MinHeapNode(data[i1],freq[i1])) ; // nodes of each char freq 
        	}
        	while (minHeap.size()!=1)
        	{
        		//until you done 
        		left = minHeap.top();//lowest value //min Heap
        		minHeap.pop();
        		right = minHeap.top();//lowest value //min Heap
        		minHeap.pop();
        
        // 		top = new MinHeapNode('$',left->freq+right->freq);
        		top = cont('$',left->freq+right->freq);
        		top->left = left ; top->right = right ;
        		minHeap.push(top);// automatic in min Heap 
        
        	}
        	
        // 	printCodes(minHeap.top() ,"",answer1);
            // printCodes(minHeap.top() ,"");
            
        
            // return {};
        }
		

};





int main()
{
 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };


	vector<int> v1 ; 


	int siez1 = sizeof(freq)/sizeof(freq[0]);
	string inpu1;
	for (int i1 = 0; i1 < siez1; i1++)
	{
		inpu1 = inpu1+arr[i1];
		v1.push_back(freq[i1]);
	}
	

	Solution ob1 ;
    vector<string> answer = ob1.huffmanCodes(arr, v1, siez1);
 
    return 0;
}
















