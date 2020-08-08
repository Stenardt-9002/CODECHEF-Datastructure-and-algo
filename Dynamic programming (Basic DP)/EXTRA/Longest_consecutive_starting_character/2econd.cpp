#include<iostream>
#include<algorithm>


using namespace std;

typedef long long int lld ;


lld propiemax(lld x, lld y)
{
    if (x>y)    
    {
        return x;
    }
        return y;
    
}



lld xopt[] = {-1,-1,-1,0,0,0,1,1,1};
lld yopt[] = {-1,0,1,-1,0,1,-1,0,1};

lld recurfuc(char **intup,lld x,lld y,char c,lld rows1,lld cols1)
{
    lld answer=0 ;
    if( (x>=rows1||y>=cols1||x<0||y<0) && ((intup[x][y]-c)!=1) )
    {
        return 0;
    }
    for (lld ty4 = 0; ty4 < 8; ty4++)
    {
        // answer = 
        answer = propiemax(answer,1+recurfuc(intup,x+xopt[ty4],y+yopt[ty4],intup[x][y],rows1,cols1) );

    }
    for (lld i1 = 0; i1 < rows1; i1++)
    {
        delete [] intup[i1];
    }
    delete [] intup;

    return answer;
}




int main(int argc, char const *argv[])
{
    lld rows,cols ;
    lld startx,starty;
    cin>>rows>>cols;
    // lld **input1 = new lld*[rows];
    char **input1 = new char*[rows];
    

    for (lld i1 = 0; i1 < rows; i1++)
    {
        input1[i1] = new char[cols];

        for (lld j1 = 0; j1 < cols; j1++)
        {
            cin>>input1[i1][j1];
        }
        
    }

//   char **input1 = { {'e','i','b','d'}, 
// 					{ 'g','a','c','e'}, 
// 					{ 'f','b','c','m'}, 
// 					{ 'e','d','n','l'}}; 

    for (lld i1 = 0; i1 < rows; i1++)
    {
        cout<<endl;
        for (lld j1 = 0; j1 < cols; j1++)
        {
            cout<<input1[i1][j1]<<" ";
        }
        
    }
    



    cin>>startx>>starty;
    lld answer = 0;
    for (lld k1 = 0; k1 < 8; k1++)
    {
        // all 8 direction
        answer = propiemax(answer,1+recurfuc(input1,startx+xopt[k1],starty+yopt[k1],input1[startx][starty],rows,cols) );
    }
    cout<<"power  "<<answer;
    

    for (lld i1 = 0; i1 < rows; i1++)
    {
        delete [] input1[i1];
    }
    delete [] input1;

    return 0;
}


