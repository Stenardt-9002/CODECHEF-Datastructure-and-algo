    vector<int> getRow(int rowIndex) 
    {
        vector<int> A1(rowIndex+1,0);
        A1[0] = 1;
        int i1 ,j1 ;
        for(i1=1;i1<rowIndex+1;i1++)
           for(j1=i1;j1>=1;j1--)
                A1[j1]+=A1[j1-1];
        
        return A1 ;
        
    }