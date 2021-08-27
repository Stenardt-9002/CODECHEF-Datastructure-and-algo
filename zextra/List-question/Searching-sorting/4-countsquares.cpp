#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>


using namespace std;





bool isperfectsqare(long double x)
{
    if (x>0)
    {
        long long sr = sqrt(x) ;
        return (sr*sr==x) ;
    }
    return false ;

}



int func(int n)
{
        if (isperfectsqare(n))
        {
            return sqrt(n)-1;
        }

        double x = sqrt(n) ;
        return floor(x);




}


// int func(int n)
// {
//     if (isperfectsqare(n))
//     {
//         return sqrt(n)-1;
//     }
//     for (int i = n-1; i >1; i--)
//     {
//             if (isperfectsqare(i))
//             {
//                  return sqrt(i) ;
//             }
            
//     }
    
    
// }





int main(int argc, char const *argv[])
{
    int n ;
    cin>>n ;


    return 0;
}












