
#include<iostream>
#include<stack>



using namespace std;

class StackQueue{
    private:
        stack<int> s1;
        stack<int> s2;

    public :
    void push(int B);
    int pop();

};


int main(int argc, char const *argv[])
{
    int T;
    cin>>T;

    while (T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin>>Q;
        while (Q--)
        {
            int QueyType = 0;
            cin>>QueyType;     
            if (QueyType==1)
            {
                //input push
                int a;cin>>a;
                sq->push(a);
            }
            else if (QueyType==2)
            {
                cout<<sq->pop()<<" ";
            }
            
            


        }
        cout<<endl;

    }




    
    return 0;
}



void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code       
        int ele;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        if (s2.empty())
        {
            ele = -1;
        }
        else
        {
       ele = s2.top();
        s2.pop();
        }


        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;

}

