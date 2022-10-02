#include<iostream>


using namespace std;


float pow_ow(float x , int y )
{
    float temp1 ;
    if (y==0)
    {
        return 1;   
    }


    temp1 = pow_ow(x,y/2);

    if (y%2==0)
    {
        return temp1*temp1;
    }
    else
    {
        if (y>0)
        {
            return x*temp1*temp1;
            
        }
        else
        {
            return (temp1*temp1)/x;
            
        }
        
        
    }
    
    

    



}












int main(int argc, char const *argv[])
{
    float x;int y;
    cin>>x>>y;

    float answe1 = pow_ow(x,y);

    return 0;
}





