using namespace std;

vector<string> split_string(string);
struct datatype {
    int var1; 
    int idx ;
};


bool funcn(datatype a1, datatype b1)
{
    return a1.var1<b1.var1;
}


// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) 
{
    int siez = arr.size();
    datatype arr1[siez];
    for(int i1 = 0 ; i1<siez ; i1++)
    {
        arr1[i1].var1 = arr[i1];
        arr1[i1].idx = i1 ; 
        
    }


    sort(arr1,arr1+siez,funcn);
    
    vector<bool> vis(siez,false);
    int asn1 = 0 ;
    int cyle1 = 0; 
    
    for(int i1 = 0 ;i1<siez ; i1++)
    {
        if(vis[i1]==true || arr1[i1].idx == i1)
        {
            continue ; 
            
        }
        cyle1 = 0;
        int j = i1 ;
        
        while(vis[j]==false)
        {
            vis[j] = true; 
            
            j = arr1[j].idx ;
            cyle1++;
            
            
        }
        
        if(cyle1>0)
        {
            asn1 = asn1+cyle1-1;
            //last of redundant
        }
        
    }

    return asn1;

}