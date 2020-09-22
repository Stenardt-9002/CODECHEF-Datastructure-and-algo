#include<iostream>
#include<stack>

using namespace std;

class Stack_1
{
stack<int>s;    
int minEle=-1;;
public:
    int getMin();
    int pop();
    void push(int);

};



int main(int argc, char const *argv[])
{
    int testcaes;
    cin>>testcaes;
    while (testcaes--)
    {
        
        int q;
        cin>>q;
        Stack_1  *a = new Stack_1();
        while (q--)
        {
            int qt;
            cin>>qt;
            if (at==1)
            {
                int att;
                cin>>att;
                a->push(att);
            }
            else if (qt==2)
            {
                cout<<a->pop()<<" ";
            }
            
            else if (qt==3)
            {
                cout<<a->getMin()<<" ";
            }
            
        }
        


    }
    


    return 0;
}





int Stack_1 :: getMin()
{
   //Your code here
//    return minEle;
      if(s.empty())
   {
       return -1;
   }
   
   return minEle;
}



int Stack_1 ::pop()
{
   //Your code here
       if (s.empty())
    {
        return -1;
    }
    
   int elepop = s.top();
   s.pop();
   if(s.empty())
   {
       minEle = -1;
       return elepop;

   }
    int m1in = 29898;
   if (elepop==minEle)
   {
        //find new min
        stack<int> s2 ;
        while (!s.empty())
        {
            s2.push(s.top());
            if (s.top()<m1in )
            {
                m1in = s.top();
            }
            
            s.pop();
        }

        //refill 
        while (!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }      
    minEle = m1in;

   }
   

return elepop;



}

/*push element x into the stack*/
void Stack_1::push(int x)
{
   //Your code here
   if (s.size()==0)
   {
       minEle = x;
    //    s.push(x);
   }
   else
   {
       if (x<minEle)
       {
           minEle = x;
       }
       
   }
   
       s.push(x);

   
}



