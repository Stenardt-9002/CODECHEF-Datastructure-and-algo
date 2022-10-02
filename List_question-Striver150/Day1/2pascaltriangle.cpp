    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> a1(numRows) ;
        a1[0].push_back(1);
        if(numRows==1)
        {
            return a1 ;
        }
        a1[1].push_back(1);
        a1[1].push_back(1);
        if(numRows==2)
        {
            return a1 ;
        }
        int i1,j1;
        for(i1=2;i1<numRows;i1++)
        {
            for(j1=0;j1<i1+1;j1++)
            {
                a1[i1].push_back(1);
            }
            
            for(j1=1;j1<i1;j1++)
            {
                a1[i1][j1] = a1[i1-1][j1-1]+a1[i1-1][j1];
            }
            
            
        }
        return a1;
        
        
    }