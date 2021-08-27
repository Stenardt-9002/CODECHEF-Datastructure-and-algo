#include<iostream>
#include<stack>

using namespace std;



void functionutil(stack<int> s2)
{
    while (!s2.empty())
    {
        cout<<" "  <<s2.top() ;
        s2.pop();
    }
    cout<<endl;

}




int main(int argc, char const *argv[])
{
    
    stack<int> s1; 
    int z ;
    int hist[] = {6,2,5,4,5,1,6};
    int n = sizeof(hist)/sizeof(hist[0]);
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar
    int max_area = 0;
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s1.empty() || hist[s1.top()] <= hist[i])
            s1.push(i++);
 
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else
        {
            cout<<"else executed   ";
            tp = s1.top();  // store the top index
            s1.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top = hist[tp] * (s1.empty() ? i : i - s1.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }


        cout<<endl<<endl ;
        cout<<"Stack ";
        functionutil(s1);
        cout<<"Variable i " << i<<endl;
        cout<<"max area" << max_area<<endl;
        cout<<"area" << area_with_top<<endl;
        cout<<"tp" << tp<<endl;



        cout<<endl<<endl ;
        cin>>z;

    }






    return 0;
}



















