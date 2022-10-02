#include<iostream>

#include<algorithm>

using namespace std;



int main(int argc, char const *argv[])
{
    long long int x, y,res = 1;
    cin>>x>>y ;
    long long int PC = 1000000007   ;
      while (y>0)
            {
                if(y&1)
                {res = (res*x)%PC ;  }
                y = y>>1;    x=(x*x)%PC ; 
            }
            cout<<res;
    return 0;
}
   long long power(int N,int R)
    {
            long long int x, y ,res = 1;
            x=N;y=R;
    
            int PC = 1000000007  ;
            while (y>0)
            {
                if (y%2==0)
                {
                    x=(x*x)%PC ; 
                    y = y>>1;    
                }
                else
                {
                    res = (res*x)%PC ;
                    y=y-1;
                    
                }
                
            }
            return res ;
    }



    // long long power(int N,int R)
    // {
    //         unsigned int x, y;long long int res = 1;
    //         x= N;y=R;
    
    //         long long int PC = 1000000007   ;
    //         while (y>0)
    //         {
    //             if (y&1)
    //             {
    //                 res = (res*x)%PC ;
    //                 // if(res<0){res = res+PC;}
    //             }
    //             y = y>>1;x = (x*x)%PC; //if(x<0){x = x+PC;}
                
    //         }
    //     return res ;
    // }




    // long long power(int N,int R)
    // {
    //         unsigned int x, y;long long int res = 1;
    //         x= N;y=R;
    
    //         long long int PC = 1000000007   ;
    //         while (y>0)
    //         {
    //             if (y&1)
    //             {
    //                 res = (res*x) ;
    //                 if(res<0){res = res+PC;}
    //             }
    //             y = y>>1;x = (x*x); if(x<0){x = x+PC;}
                
    //         }
    //     return res ;
    // }





    
    // long long power(int N,int R)
    // {
    //         int x, y; int res = 1;
    //         x=N;y=R;
    
    //         int PC = 1000000007   ;
    //         while (y>0)
    //         {
    //             if (y&1)
    //             {
    //                 res = (res*x) ;
    //                 if(res<0){res = res+PC;}
    //             }
    //             y = y>>1;x = (x*x); if(x<0){x = x+PC;}
                
    //         }
    //         return res ;
    // }



