#include<iostream>
#include<vector>
#include<string>

using namespace std;

// vector<int> preprocess(string str1)
void preprocess(string str1,int lps[] )
{   
    int len = 0;
    lps[0] = 0 ;

    int i=1; //start from 1 st index 
    int lenpat = str1.length();
    int i=1;
    while (i<lenpat)
    {

        i++;
        if (str1[i]==str1[len])
        {
            len++;
            
        }
        
    }
    




}

void KMP_Atemp(string pat,string txt)
{
    // #preproces 
    int lengpat = pat.length();
    int lentxt = txt.length();
    // cout<<lengpat;
    int lps[lengpat];
    preprocess(pat,lps);
    int i=0,j = 0;
    while (i<lengpat)
    {
        if (pat[j]==txt[i])
        {
            j++;i++;
        }
        
        if (j==lengpat)
        {
            printf("The string is found %d",i-j);
            j = lps[j-1];

            
        }
        
        else if (i<lentxt && pat[j]!=txt[i]  )
        {
            if (j!=0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
            

        }
        







    }
    



}




int main(int argc, char const *argv[])
{
    
    string txt= "lollipopoplilolilolipopopililolplolilipopo";
    // char txt[] = "lollipopoplilolilolipopopililolplolilipopo";

    string pat = "ipo";
    // char pat[] = "ipo";


    KMP_Atemp(pat,txt);



    return 0;
}








