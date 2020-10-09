

// #include<iostream>
// #include<stdio.h>
// #include<vector>

// using namespace std;



     
// void floodfill(vector<int> brow[],int xnew,int ynew,int cruentcolor,int newcolor,int row,int col)
// {

//     if (xnew>=0 && xnew<row &&ynew>=0&&ynew<col&&brow[xnew][ynew]==cruentcolor)
//     {
//         brow[xnew][ynew] = newcolor;
//         floodfill(brow,xnew+1,ynew,cruentcolor,newcolor,row,col);
//         floodfill(brow,xnew,ynew+1,cruentcolor,newcolor,row,col);
//         floodfill(brow,xnew-1,ynew,cruentcolor,newcolor,row,col);
//         floodfill(brow,xnew,ynew-1,cruentcolor,newcolor,row,col);



        
//     }
    





// }




// int main(int argc, char const *argv[])
// {
//     int testcases;

//     int row ,col,xnew,ynew,newcolor,cruentcolor;
//     cin>>testcases;
//     while (testcases--)
//     {
//         cin>>row>>col;
//         vector <int> *brow;
//         brow = new vector<int>[row];
//         // cout<<"\nBRA"<<row<<col<<endl;
//         for (int i1 = 0; i1 < row; i1++)
//         {
//             vector<int> temp1(col);
//             brow[i1] = temp1;
//             for (int j1 = 0; j1 < col; j1++)
//             {
//                 cin>>brow[i1][j1];
//             }
            
//             // cout<<endl;
//             // for (int j1 = 0; j1 < col; j1++)
//             // {
//             //     cout<<brow[i1][j1]<<" ";
//             // }
//             // cout<<endl;




//         }
        


//     cin>>xnew>>ynew>>newcolor;
//     cruentcolor = brow[xnew][ynew];
//         floodfill(brow,xnew,ynew,cruentcolor,newcolor,row,col);
//         // cout<<endl<<cruentcolor;


//         cout<<endl;
//         for (int i1 = 0; i1 < row; i1++)
//         {
//             for (int j1 = 0; j1 < col; j1++)
//             {
//                 cout<<brow[i1][j1]<<" ";
//             }
//         }



//     }
    

//     return 0;
// }






#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;



     
void floodfill(vector<int> brow[],int xnew,int ynew,int cruentcolor,int newcolor,int row,int col)
{

    if (xnew>=0 && xnew<row &&ynew>=0&&ynew<col&&brow[xnew][ynew]==cruentcolor)
    {
        brow[xnew][ynew] = newcolor;
        floodfill(brow,xnew+1,ynew,cruentcolor,newcolor,row,col);
        floodfill(brow,xnew,ynew+1,cruentcolor,newcolor,row,col);
        floodfill(brow,xnew-1,ynew,cruentcolor,newcolor,row,col);
        floodfill(brow,xnew,ynew-1,cruentcolor,newcolor,row,col);



        
    }
    





}




int main(int argc, char const *argv[])
{
    int testcases;

    int row ,col,xnew,ynew,newcolor,cruentcolor;
    cin>>testcases;
    while (testcases--)
    {
        cin>>row>>col;
        vector <int> *brow;
        brow = new vector<int>[row];
        // cout<<"\nBRA"<<row<<col<<endl;
        for (int i1 = 0; i1 < row; i1++)
        {
            vector<int> temp1(col);
            brow[i1] = temp1;
            for (int j1 = 0; j1 < col; j1++)
            {
                cin>>brow[i1][j1];
            }
            
            // cout<<endl;
            // for (int j1 = 0; j1 < col; j1++)
            // {
            //     cout<<brow[i1][j1]<<" ";
            // }
            // cout<<endl;




        }
        


    cin>>xnew>>ynew>>newcolor;
    cruentcolor = brow[xnew][ynew];
        floodfill(brow,xnew,ynew,cruentcolor,newcolor,row,col);
        // cout<<endl<<cruentcolor;


        // cout<<endl;
        for (int i1 = 0; i1 < row; i1++)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                cout<<brow[i1][j1]<<" ";
            }
        }
        cout<<endl;


    }
    






    return 0;
}
















