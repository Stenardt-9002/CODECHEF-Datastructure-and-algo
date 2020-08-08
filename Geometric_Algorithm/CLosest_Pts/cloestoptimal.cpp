#include<iostream>
#include<algorithm>
#include<math.h>
#include<float.h>
using namespace std;

struct coordinate{
    int x,y;
};

bool compx(coordinate a,coordinate b)
{
    if (a.x == b.x)
    {
        /* code */
        return a.y<b.y;
    }
        return a.x<b.x;
    
}


bool compy(coordinate a,coordinate b)
{
    if (a.y == b.y)
    {
        /* code */
        return a.x<b.x;
    }
        return a.y<b.y;
    
}
float sqareDist(coordinate p1, coordinate p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) 
               ); 
} 


// float 
float stripClosest(coordinate tem1[], int n1, float d) 
{ 
    float min = d;  // Initialize the minimum distance as d 
  
    // Pick all points one by one and try the next points till the difference 
    // between y coordinates is smaller than d. 
    // This is a proven fact that this loop runs at most 6 times 
    for (int i = 0; i < n1; ++i) 
        for (int j = i+1; j < n1 && (tem1[j].y - tem1[i].y) < min; ++j) 
            if (sqareDist(tem1[i],tem1[j]) < min) 
                min = sqareDist(tem1[i], tem1[j]); 
  
    return min; 
} 


float bruteForce(coordinate P[], int n) 
{ 
    float min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (sqareDist(P[i], P[j]) < min) 
                min = sqareDist(P[i], P[j]); 
    return min; 
} 



float closestUtil(coordinate Px[], coordinate Py[], int n) 
{ 
    // If there are 2 or 3 points, then use brute force 
    if (n <= 3) 
        return bruteForce(Px, n); 
  
    // Find the middle point 
    int mid = n/2; 
    coordinate midPoint = Px[mid]; 
  
  
    // Divide points in y sorted array around the vertical line. 
    // Assumption: All x coordinates are distinct. 
    coordinate Pyl[mid];   // y sorted points on left of vertical line 
    coordinate Pyr[n-mid];  // y sorted points on right of vertical line 
    int li = 0, ri = 0;  // indexes of left and right subarrays 
    for (int i = 0; i < n; i++) 
    { 
      if (Py[i].x <= midPoint.x && li<mid) 
         Pyl[li++] = Py[i];     
      else
         Pyr[ri++] = Py[i]; 
    } 


    cout<<"\nPyl\n";

    for (int i = 0; i < mid; i++) 
    { 
      cout<<Pyl[i].x<<" "<<Pyl[i].y <<"   ";
    } 

    cout<<"\nPyr\n";

    for (int i = 0; i < mid; i++) 
    { 
      cout<<Pyr[i].x<<" "<<Pyr[i].y <<"  ";
    } 




  /*
    // Consider the vertical line passing through the middle point 
    // calculate the smallest distance dl on left of middle point and 
    // dr on right side 
    float dl = closestUtil(Px, Pyl, mid); 
    float dr = closestUtil(Px + mid, Pyr, n-mid); 
  
    // Find the smaller of two distances 
    float d = min(dl, dr); 
  
    // Build an array strip[] that contains points close (closer than d) 
    // to the line passing through the middle point 
    coordinate strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(Py[i].x - midPoint.x) < d) 
            strip[j] = Py[i], j++; 
  
    // Find the closest points in strip.  Return the minimum of d and closest 
    // distance is strip[] 
    return stripClosest(strip, j, d); 

    */
   return 0;

}










int main(int argc, char const *argv[])
{
    int n;

    cin>>n;
    coordinate *intup = new coordinate[n];
    coordinate *iupx = new coordinate[n];
    coordinate *iupy = new coordinate[n];

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>intup[i1].x>>intup[i1].y;
        iupx[i1] = intup[i1];
        iupy[i1] = intup[i1];
    }
    // cout<<endl;
    
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<intup[i1].x<<" "<<intup[i1].y<<endl;
    // }

    sort(iupx,iupx+n,compx);
    sort(iupy,iupy+n,compy);

    closestUtil(iupx,iupy,n);
    // cout<<endl;

    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<iupx[i1].x<<" "<<iupx[i1].y<<endl;
    // }
    // cout<<endl;


    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<iupy[i1].x<<" "<<iupy[i1].y<<endl;
    // }


    delete [] intup;
    delete [] iupx;
    delete [] iupy;


    return 0;
}


