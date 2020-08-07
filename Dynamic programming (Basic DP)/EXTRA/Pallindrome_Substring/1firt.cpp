#include<iostream>

using namespace std;

void printstring(int start,int length,string str11)
{
    for (int i1 = start; i1 < start+length; i1++)
    {
        cout<<str11[i1];
    }
    cout<<endl;
    
}
int main(int argc, char const *argv[])
{
    int testcases;
    cin>>testcases;
    string str1;
    int lenght ;
    while (testcases--)
    {
        cin>>str1;
        lenght = str1.length();
        int **dp1;
        dp1 = new int*[lenght];
        for (int i1 = 0; i1 < lenght; i1++)
        {
            dp1[i1] = new int[lenght];
            for (int o1 = 0; o1 < lenght; o1++)
            {
             dp1[i1][o1] = 0;
            }

            dp1[i1][i1] = 1;


        }
        int strat_idx = 0;
        int max_length = 1;
        //2 length dp
        for (int i1 = 0; i1 < lenght-1; i1++)
        {
            if (str1[i1]==str1[i1+1])
            {
                /* code */
                dp1[i1][i1+1] =  dp1[i1+1][i1]= 1;
                if (max_length<2)
                {
                    /* code */
                    max_length = 2;
                    strat_idx = i1;
                }
            }
            
        }

    //  cout<<"\ndp\n";
    //     for (int i1 = 0; i1 < lenght; i1++)
    //     {
    //         for (int j1 = 0; j1 < lenght; j1++)
    //         {
    //             cout<<dp1[i1][j1]<<" ";
    //         }
    //         cout<<endl;
    //     }
        

        // each length string of length 3
    //dp top to down

// j1 is length of subtring

        for (int z1 = 3; z1 <= lenght; z1++)
        {
            for (int i1 = 0; i1 < lenght-z1+1; i1++)
            {
               
               int j1 = z1+i1-1; //end index

                if (dp1[i1+1][j1-1]==1 && str1[i1]== str1[j1])
                {
                    dp1[i1][j1] = 1;
                    dp1[j1][i1] = 1;


                    if (max_length<z1)
                    {
                        max_length = z1;
                        strat_idx = i1;
                    }

                    //else if not required
                    else if (max_length == z1)
                    {
                        if (strat_idx>i1)
                        {                            
                            strat_idx = i1;
                        }
                        
                    }
                }

            } 
        }
       

        // cout<<" \n Start idx"<<strat_idx<<" length "<<max_length;

        printstring(strat_idx,max_length,str1);
        for (int u1 = 0; u1 < lenght; u1++)
        {
            delete [] dp1[u1];
        }
        delete [] dp1;
        

    }
    
    return 0;
}



