#include<iostream>
#include<math.h>

typedef long long int lld;
using namespace std;
struct Coordinate
{
    lld x,y;
};

int slopecheckifptinbet(Coordinate c1 ,Coordinate c2 , Coordinate c3)
{
//   c1 c3 same slop c3 c2 
    // if ( (float)((c3.y-c1.y )/(c3.x-c1.x)) == (float)((c2.y-c3.y )/(c2.x-c3.x))  )
    // {
    //     return 1;
    // }
    // return 0;

    // if ( (c3.y-c1.y )*(c2.x-c3.x) == (c2.y-c3.y )*(c3.x-c1.x)  )
    // {
    //     return 1;
    // }
    // return 0;


    if (c2.x <= max(c1.x, c3.x) && c2.x >= min(c1.x, c3.x) && c2.y <= max(c1.y, c3.y) && c2.y >= min(c1.y, c3.y)) 
       return true; 
  
    return false; 



}

int orientation(Coordinate p,Coordinate q,Coordinate r)
{
    lld ore = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

    if(ore==0)
    {
        return 0; //same line
    }
    else if(ore>0)
    {
        return 1 ;//clock
    }
    else
    {
        return 2;
    }
    
}


int insertect(Coordinate p1,Coordinate q1 ,Coordinate p2,Coordinate q2)
{
    //p1 ,q1 one line

    lld firsore = orientation(p1,q1,q2);
    lld secore = orientation(p1,q1,p2);
    lld thirdsore = orientation(p2,q2,q1);
    lld fourtsore = orientation(p2,q2,p1);

    if (thirdsore!=fourtsore && firsore != secore  )
    {
        return true ;//intersect

    }

    // check linearity

    if (firsore==0    &&(slopecheckifptinbet(p1,q2,q1)) )
    {
        return true;//intersect
    }


    if (secore==0 &&(slopecheckifptinbet(p1,p2,q1)) )
    {
        return true;//intersect
    }
    
     if (thirdsore==0 &&(slopecheckifptinbet(p2,q1,q2)))
    {
        return true;//intersect
    }
    
    if (fourtsore==0&&(slopecheckifptinbet(p2,p1,q2)) )
    {
        return true;//intersect
    }
    
    return false;

}





int main(int argc, char const *argv[])
{
    Coordinate c1,c2,l1,l2;

    lld testcaes; 
    cin>>testcaes;
    while (testcaes--)
    {
        cin>>c1.x>>c1.y>>c2.x>>c2.y>>l1.x>>l1.y>>l2.x>>l2.y;
        if (insertect(c1,c2,l1,l2))
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        


    }
    



    return 0;
}


// // A C++ program to check if two given line segments intersect 
// #include <iostream> 
// using namespace std; 

// struct Point 
// { 
// 	int x; 
// 	int y; 
// }; 

// // Given three colinear points p, q, r, the function checks if 
// // point q lies on line segment 'pr' 
// bool onSegment(Point p, Point q, Point r) 
// { 
// 	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
// 		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
// 	return true; 

// 	return false; 
// } 

// // To find orientation of ordered triplet (p, q, r). 
// // The function returns following values 
// // 0 --> p, q and r are colinear 
// // 1 --> Clockwise 
// // 2 --> Counterclockwise 
// int orientation(Point p, Point q, Point r) 
// { 
// 	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
// 	// for details of below formula. 
// 	int val = (q.y - p.y) * (r.x - q.x) - 
// 			(q.x - p.x) * (r.y - q.y); 

// 	if (val == 0) return 0; // colinear 

// 	return (val > 0)? 1: 2; // clock or counterclock wise 
// } 

// // The main function that returns true if line segment 'p1q1' 
// // and 'p2q2' intersect. 
// bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
// { 
// 	// Find the four orientations needed for general and 
// 	// special cases 
// 	int o1 = orientation(p1, q1, p2); 
// 	int o2 = orientation(p1, q1, q2); 
// 	int o3 = orientation(p2, q2, p1); 
// 	int o4 = orientation(p2, q2, q1); 

// 	// General case 
// 	if (o1 != o2 && o3 != o4) 
// 		return true; 

// 	// Special Cases 
// 	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
// 	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

// 	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
// 	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

// 	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
// 	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

// 	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
// 	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

// 	return false; // Doesn't fall in any of the above cases 
// } 

// int main(int argc, char const *argv[])
// {
//     Point c1,c2,l1,l2;

//     lld testcaes; 
//     cin>>testcaes;
//     while (testcaes--)
//     {
//         cin>>c1.x>>c1.y>>c2.x>>c2.y>>l1.x>>l1.y>>l2.x>>l2.y;
//         if (doIntersect(c1,c2,l1,l2))
//         {
//             cout<<1<<endl;
//         }
//         else
//         {
//             cout<<0<<endl;
//         }
        


//     }
    



//     return 0;
// }

