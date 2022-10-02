
#include<iostream>

using namespace std;
#define A_LARGE_NUM 32000


//point is inside polygon NOT ON EDGE    if line extend intersection count is odd 

struct datatipe1
{
    int x,y;
};


int chek_orent(datatipe1 a,datatipe1 b,datatipe1 c)
{
    int orent = (c.x-b.x)*(b.y-a.y)-(c.y-b.y)*(b.x-a.x);
    if (orent==0)
    {
        return 0;   
    }
    else
    {
        return orent>0 ?1:2; 
    }
       

}



int on_same_lie(datatipe1 a,datatipe1 b,datatipe1 c)
{
    // b on same line as line(a,c)

    if (b.x<=max(a.x,c.x)&& b.x>=min(a.x,c.x) && b.y<=max(a.y,c.y) && b.y>=min(a.y,c.y)   )
    {
        return true;
    }
    return false;

}








bool iamitersetect(datatipe1 line1p1,datatipe1 lin1p2, datatipe1 line2p1,datatipe1  line2p2)
{
    int orent1 = chek_orent(line1p1,lin1p2,line2p1);
    int orent2 = chek_orent(line1p1,lin1p2,line2p2);
    int orent3 = chek_orent(line2p1,line2p2,line1p1);
    int orent4 = chek_orent(line2p1,line2p2,lin1p2);


    if (orent1!=orent2 && orent3!=orent4)
    {
        return true;
    }


    if (orent1==0 && on_same_lie(line1p1,line2p1,lin1p2)   )//same orient
    {
        return true;
    }

    if (orent2==0 && on_same_lie(line1p1,line2p2,lin1p2)   )//same orient
    {
        return true;
    }
    
    if (orent3==0 && on_same_lie(line2p1,line1p1,line2p2)   )//same orient
    {
        return true;
    }
    
    if (orent4==0 && on_same_lie(line2p1,lin1p2,line2p2)   )//same orient
    {
        return true;
    }
    
    

    return false;//not intersect


}







bool checkifInside(datatipe1 aray_1[],int n,datatipe1 p)
{
    if (n<3)
    {
        return false;// cant polygon less than 3 sides
    }


    datatipe1 extreme_check = {A_LARGE_NUM,p.y};


    int no_of_intersection =0,i=0;
    do
    {
        int j = (i+1)%n;
        // 2lines
        if (iamitersetect(aray_1[i],aray_1[j],p,extreme_check))
        {
            //check orientation 
            no_of_intersection++;
        }
        


    i = j;//next p t

    } while (i!=0);
    
    return no_of_intersection&1;
    
}



int main(int argc, char const *argv[])
{
    int i=0,n;// no of coordinates


    // cin>>n;
    // datatipe1 arr1[n];


    // while (++i<n)
    // {
    //     cin>>arr1[i].x>>arr1[i].y;
    // }




    datatipe1 arr1[] = {{0,0},{10,0},{10,10},{0,10}};
    n = sizeof(arr1)/sizeof(arr1[0]);


    cout<<checkifInside(arr1,n,{4,4})<<endl;
    cout<<checkifInside(arr1,n,{14,4})<<endl;
    cout<<checkifInside(arr1,n,{9,9})<<endl;



    return 0;
}








